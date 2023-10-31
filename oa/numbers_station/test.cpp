#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  std::vector<std::pair<int, char>> inputSequence;
  std::vector<std::string> expectedOutput;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {};

TEST_P(SolutionTest, AllTestCases) {
  Solution s;
  auto [inputSequence, expectedOutput] = GetParam();
  for (const auto [seq, ch] : inputSequence) {
    s.processSample(seq, ch);
  }
  const auto& res = s.getOutputLines();
  EXPECT_EQ(res, expectedOutput);
}

std::vector<TestCase> generateTestCases() {
  std::vector<TestCase> testCases{
      {
          .inputSequence =
              {
                  {1, '-'},
                  {2, 'h'},
                  {3, 'e'},
                  {4, 'l'},
                  {5, 'l'},
                  {6, 'o'},
                  {7, '-'},
                  {8, 'b'},
              },
          .expectedOutput = {"hello"},
      },
      {
          .inputSequence =
              {
                  {1, '-'},
                  {2, 'b'},
                  {3, 'y'},
                  {5, '-'},
                  {6, 'h'},
                  {7, 'i'},
                  {8, '-'},
                  {4, 'e'},
              },
          .expectedOutput = {"hi"},
      },
      {
          .inputSequence =
              {
                  {1, '-'},
                  {2, 'h'},
                  {3, 'e'},
                  {4, 'l'},
                  {5, 'l'},
                  {6, 'o'},
                  {7, '-'},
                  {8, 'b'},
                  {9, 'y'},
                  {10, 'e'},
                  {11, '-'},
              },
          .expectedOutput = {"hello", "bye"},
      },
  };
  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));
