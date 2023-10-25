#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  vector<int> data;
  int k;
  int expected;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {};

TEST_P(SolutionTest, AllTestCases) {
  auto& testCase = GetParam();
  auto result = maxLength(testCase.data, testCase.k);
  EXPECT_EQ(testCase.expected, result);
}

vector<TestCase> generateTestCases() {
  vector<TestCase> testCases{.data = {1, 2, 3}, .k = 4, .expected = 2};
  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));