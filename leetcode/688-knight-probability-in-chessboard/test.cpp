#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  int boardSize;
  int totalMoves;
  int row;
  int col;
  double probability;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {
 protected:
  Solution s;
};

TEST_P(SolutionTest, AllTestCases) {
  auto [boardSize, totalMoves, row, col, probability] = GetParam();
  auto result = s.knightProbability(boardSize, totalMoves, row, col);
  EXPECT_EQ(result, probability);
}

vector<TestCase> generateTestCases() {
  vector<TestCase> testCases{
      {
          .boardSize = 3,
          .totalMoves = 2,
          .row = 0,
          .col = 0,
          .probability = 0.0625,
      },
      {
          .boardSize = 1,
          .totalMoves = 0,
          .row = 0,
          .col = 0,
          .probability = 1.0,
      },
  };
  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));
