#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  pair<int, int> dimension;  // width, height
  vector<vector<int>> food;
  vector<string> moves;  // does not include the first one from LeetCode
  vector<int> output;    // does not include the first one from LeetCode
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {};

TEST_P(SolutionTest, AllTestCases) {
  auto [dimension, food, moves, output] = GetParam();
  SnakeGame game(dimension.first, dimension.second, food);
  for (int i = 0; i < moves.size(); i++) {
    int result = game.move(moves[i]);
    EXPECT_EQ(result, output[i]);
  }
}

vector<TestCase> generateTestCases() {
  vector<TestCase> testCases{
      {
          .dimension = {3, 2},
          .food = {{1, 2}, {0, 1}},
          .moves = {"R", "D", "R", "U", "L", "U"},
          .output = {0, 0, 1, 1, 2, -1},
      },
      {
          .dimension = {3, 3},
          .food = {{2, 0}, {0, 0}, {0, 2}, {0, 1}, {2, 2}, {0, 1}},
          .moves = {"D", "D", "R", "U", "U", "L", "D", "R", "R", "U", "L", "L",
                    "D", "R", "U"},
          .output = {0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4, 4, 4, -1},
      },
      {
          .dimension = {3, 3},
          .food = {{2, 0}, {0, 0}, {0, 2}, {2, 2}},
          .moves = {"D", "D", "R", "U", "U", "L", "D", "R", "R", "U", "L", "D"},
          .output = {0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3},
      },
      {
          .dimension = {3, 3},
          .food = {{0, 1}, {0, 2}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {1, 0}},
          .moves = {"R", "R", "D", "D", "L", "L", "U", "U", "R", "R", "D", "D",
                    "L", "L", "U", "R", "U", "L", "D"},
          .output = {1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, -1},
      },
  };

  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));