#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  std::string input;
  std::string output;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {};

TEST_P(SolutionTest, AllTestCases) {
  auto [input, output] = GetParam();
  auto result = validateBinaryTree(input);
  EXPECT_EQ(result, output);
}

std::vector<TestCase> generateTestCases() {
  std::vector<TestCase> testCases{
      {
          .input = "(A,B) (B,D) (D,E) (A,C) (C,F) (E,G)",
          .output = "(A(B(D(E(G))))(C(F)))",
      },
      {
          .input = "((A,B))",
          .output = "E1",
      },
      {
          .input = "(A,B) (A,C) (A,B)",
          .output = "E2",
      },
      {
          .input = "(A,B) (A,C) (A,D)",
          .output = "E3",
      },
      {.input = "(A,B) (C,B) (B,D) (B,E)", .output = "E4"},
      {
          .input = "(A,B) (A,C) (B,D) (D,C)",
          .output = "E5",
      },
      {
          .input = "(A,B) (A,C) (B,D) (C,D)",
          .output = "E5",
      },
  };
  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));
