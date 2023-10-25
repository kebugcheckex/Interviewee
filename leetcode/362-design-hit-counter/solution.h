#include "header.h"

class HitCounter {
 public:
  HitCounter() {}

  void hit(int timestamp) {
    rotateHistory(timestamp);

    auto mostRecentElement = history_.rbegin();
    if (mostRecentElement != history_.rend() &&
        mostRecentElement->first == timestamp) {
      mostRecentElement->second += 1;
    } else {
      history_.push_back({timestamp, 1});
    }
    sum_ += 1;
  }

  int getHits(int timestamp) {
    rotateHistory(timestamp);
    return sum_;
  }

 private:
  void rotateHistory(int timestamp) {
    while (history_.size() > 0 && timestamp - history_.front().first >= 300) {
      sum_ -= history_.front().second;
      history_.pop_front();
    }
  }
  deque<pair<int, int>> history_;  // pair<timestamp, hitCount>
  int sum_;
};
