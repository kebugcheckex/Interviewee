#include <gtest/gtest.h>

#include "solution.h"

// TODO: replace with actual fields
typedef struct StructTestCase {
  int inputValue;
  std::string expectedOutput;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {};

TEST_P(SolutionTest, AllTestCases) {
  Solution s;
  auto [inputValue, expectedOutput] = GetParam();
  // TODO call function with inputValue and compare with expected output
  EXPECT_EQ("expected", "actual");
}

std::vector<TestCase> generateTestCases() {
  std::vector<TestCase> testCases{
      // TODO replace with actual test data
      {
          .inputValue = 123,
          .expectedOuput = "test",
      },
  };

  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));
