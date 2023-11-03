#include <gtest/gtest.h>

#include "solution.h"

// TODO: replace with actual fields
typedef struct StructTestCase {
  std::vector<std::vector<int>> room;
  int initialRow;
  int initialCol;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {};

TEST_P(SolutionTest, AllTestCases) {
  auto [room, initialRow, initialCol] = GetParam();
  Robot robot(room, initialRow, initialCol);
  Solution s;
  s.cleanRoom(robot);
  EXPECT_TRUE(robot.isAllCleaned());
}

std::vector<TestCase> generateTestCases() {
  std::vector<TestCase> testCases{
      {
          .room = {{1, 1, 1, 1, 1, 0, 1, 1},
                   {1, 1, 1, 1, 1, 0, 1, 1},
                   {1, 0, 1, 1, 1, 1, 1, 1},
                   {0, 0, 0, 1, 0, 0, 0, 0},
                   {1, 1, 1, 1, 1, 1, 1, 1}},
          .initialRow = 1,
          .initialCol = 3,
      },
  };

  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));
