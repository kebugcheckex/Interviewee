#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  int numberOfNodes;
  vector<pair<int, int>> edges;
  vector<int> specialNodes;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {};

TEST_P(SolutionTest, AllTestCases) {
  auto& testCase = GetParam();
  auto result = isSpecial(testCase.numberOfNodes, testCase.edges);
  EXPECT_EQ(testCase.specialNodes, result);
}

vector<TestCase> generateTestCases() {
  vector<TestCase> testCases{
      {
          .numberOfNodes = 7,
          .edges = {{1, 2}, {2, 3}, {3, 4}, {3, 5}, {1, 6}, {1, 7}},
          .specialNodes = {0, 0, 0, 0, 1, 1, 1, 1},
      },
      {
          .numberOfNodes = 1,
          .edges = {},
          .specialNodes = {0, 1},
      },
      {
          .numberOfNodes = 2,
          .edges = {{1, 2}},
          .specialNodes = {0, 1, 1},
      },
      {
          .numberOfNodes = 3,
          .edges = {{1, 2}, {1, 3}},
          .specialNodes = {0, 0, 1, 1},
      },
      {
          .numberOfNodes = 4,
          .edges = {{1, 2}, {1, 3}, {1, 4}},
          .specialNodes = {0, 0, 1, 1, 1},
      }};
  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));
