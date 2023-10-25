#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  vector<int> commands;
  vector<vector<int>> obstacles;
  int distance;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {
 protected:
  Solution s;
};

TEST_P(SolutionTest, AllTestCases) {
  auto testCase = GetParam();
  auto result = s.robotSim(testCase.commands, testCase.obstacles);
  EXPECT_EQ(testCase.distance, result);
}

vector<TestCase> generateTestCases() {
  vector<TestCase> testCases{
      {
          .commands = {4, -1, 3},
          .obstacles = {},
          .distance = 25,
      },
      {
          .commands = {4, -1, 4, -2, 4},
          .obstacles = {{2, 4}},
          .distance = 65,
      },
      {
          .commands = {6, -1, -1, 6},
          .obstacles = {},
          .distance = 36,
      },
  };
  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));
