#include "header.h"

// Copied from
// https://github.com/wisdompeak/LeetCode/blob/b1513fa6c71b5eee53bef04ab7d3644f8a7e72e3/Design/460.LFU-Cache/460.LFU-Cache_v2.cpp

class LFUCache {
  std::unordered_map<int, int> key2value;
  std::unordered_map<int, std::list<int>::iterator> key2iter;
  std::unordered_map<int, int> key2freq;
  std::unordered_map<int, std::list<int>> freq2list;
  int capacity_, minimumFrequency_;

 public:
  LFUCache(int capacity) : capacity_(capacity), minimumFrequency_(0) {}

  int get(int key) {
    if (!key2value.contains(key)) {
      return -1;
    }

    int f = key2freq.at(key);
    freq2list[f].erase(key2iter[key]);
    freq2list[f + 1].push_back(key);
    key2iter[key] = --freq2list[f + 1].end();  // ???
    key2freq[key] = f + 1;

    if (freq2list[minimumFrequency_].empty()) {
      minimumFrequency_ += 1;
    }

    return key2value.at(key);
  }

  void put(int key, int value) {
    if (capacity_ == 0) {
      return;
    };

    if (get(key) != -1) {
      key2value[key] = value;
      return;
    }

    if (key2value.size() == capacity_) {
      int leastFrequentKey = freq2list[minimumFrequency_].front();

      key2value.erase(leastFrequentKey);
      key2iter.erase(leastFrequentKey);
      key2freq.erase(leastFrequentKey);
      freq2list[minimumFrequency_].pop_front();
    }

    key2value[key] = value;
    key2freq[key] = 1;
    freq2list[1].push_back(key);
    key2iter[key] = --freq2list[1].end();

    minimumFrequency_ = 1;
  }
};