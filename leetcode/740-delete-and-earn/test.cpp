#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  vector<int> nums;
  int maxPoints;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {
 protected:
  Solution s;
};

TEST_P(SolutionTest, AllTestCases) {
  auto testCase = GetParam();
  auto result = s.deleteAndEarn(testCase.nums);
  EXPECT_EQ(testCase.maxPoints, result);
}

vector<TestCase> generateTestCases() {
  vector<TestCase> testCases{
      {
          .nums = {3, 4, 2},
          .maxPoints = 6,
      },
      {
          .nums = {2, 2, 3, 3, 3, 4},
          .maxPoints = 9,
      },
      {
          .nums = {5, 5, 5},
          .maxPoints = 15,
      },
  };
  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));