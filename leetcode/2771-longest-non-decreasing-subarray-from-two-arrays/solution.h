#include "header.h"
#include "utils.h"

class Solution {
 public:
  int maxNonDecreasingLength(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> dp1(nums1.size(), 1);
    std::vector<int> dp2(nums2.size(), 1);
    dp1[0] = 1;
    dp2[0] = 1;
    int maxLength = 1;
    for (int i = 1; i < nums1.size(); i++) {
      if (nums1[i] >= nums1[i - 1]) {
        dp1[i] = dp1[i - 1] + 1;
      }
      if (nums2[i] >= nums2[i - 1]) {
        dp2[i] = dp2[i - 1] + 1;
      }
      if (nums1[i] >= nums2[i - 1]) {
        dp1[i] = std::max(dp1[i], dp2[i - 1] + 1);
      }
      if (nums2[i] >= nums1[i - 1]) {
        dp2[i] = std::max(dp2[i], dp1[i - 1] + 1);
      }
      maxLength = std::max(std::max(maxLength, dp1[i]), dp2[i]);
    }
    return maxLength;
  }
};