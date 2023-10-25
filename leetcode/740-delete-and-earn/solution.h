#include "header.h"

class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> values(*nums.rbegin() + 1, 0);
    for (const int num : nums) {
      values[num] += num;
    }
    vector<int> gains(values.size());
    gains[0] = 0;
    gains[1] = values[1];
    for (int i = 2; i < gains.size(); i++) {
      gains[i] = max(gains[i - 2] + values[i], gains[i - 1]);
    }
    return *gains.rbegin();
  }
};