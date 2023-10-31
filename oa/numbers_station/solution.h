#include "header.h"
#include "utils.h"

class Solution {
 public:
  Solution() : nextSeq_(1) {}

  void processSample(int seq, char ch) {
    if (ch != '-') {
      buffer_[seq] = ch;
      if (seq >= nextSeq_) {
        nextSeq_ = seq + 1;
        return;
      }
      // new seq is a previously missing one, check if it completes a message
      auto it = dashSeqs_.upper_bound(seq);
      if (it != dashSeqs_.end() && it != dashSeqs_.begin()) {
        tryGetMessage(*std::prev(it), *it);
      }
    } else {  // deal with '-'
      dashSeqs_.insert(seq);
      if (dashSeqs_.size() < 2) {
        return;
      }
      auto it = dashSeqs_.find(seq);
      if (seq != *dashSeqs_.begin()) {
        tryGetMessage(*std::prev(it), seq);
      }
      if (seq != *dashSeqs_.rbegin()) {
        tryGetMessage(seq, *std::next(it));
      }
    }
  }

  void onMessageComplete(const std::string& message) {
    outputLines_.push_back(message);
  }

  // for testing use
  std::vector<std::string> getOutputLines() { return outputLines_; }

 private:
  void tryGetMessage(int start, int end) {
    std::ostringstream oss;
    for (int i = start + 1; i < end; i++) {
      if (!buffer_.contains(i)) {
        return;  // still missing character
      }
      oss << buffer_.at(i);
    }
    onMessageComplete(oss.str());
    cleanUpBuffer(end);
  }

  void cleanUpBuffer(int end) {
    for (auto it = buffer_.begin(); it != buffer_.end();) {
      if (it->first < end) {
        it = buffer_.erase(it);
      } else {
        ++it;
      }
    }

    for (auto it = dashSeqs_.begin(); it != dashSeqs_.end();) {
      if (*it < end) {
        it = dashSeqs_.erase(it);
      } else {
        ++it;
      }
    }
  }
  std::map<int, char> buffer_;
  std::set<int> dashSeqs_;
  int nextSeq_;

  // for unit tests
  std::vector<std::string> outputLines_;
};
