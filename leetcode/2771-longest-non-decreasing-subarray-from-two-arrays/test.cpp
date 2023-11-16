#include <gtest/gtest.h>

#include "solution.h"

struct TestCase {
  std::vector<int> nums1;
  std::vector<int> nums2;
  int expected;
};

class SolutionTest : public testing::TestWithParam<TestCase> {};

TEST_P(SolutionTest, AllTestCases) {
  Solution s;
  auto [nums1, nums2, expected] = GetParam();
  auto result = s.maxNonDecreasingLength(nums1, nums2);
  EXPECT_EQ(expected, result);
}

std::vector<TestCase> generateTestCases() {
  std::vector<TestCase> testCases{
      {
          .nums1 = {2, 3, 1},
          .nums2 = {1, 2, 1},
          .expected = 2,
      },
      {
          .nums1 = {1, 3, 2, 1},
          .nums2 = {2, 2, 3, 4},
          .expected = 4,
      },
      {
          .nums1 = {1, 1},
          .nums2 = {2, 2},
          .expected = 2,
      },
  };

  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));
