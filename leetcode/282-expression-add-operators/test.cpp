#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  string number;
  int target;
  unordered_set<string> results;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {
 protected:
  Solution s;
};

TEST_P(SolutionTest, AllTestCases) {
  auto testCase = GetParam();
  auto results = s.addOperators(testCase.number, testCase.target);
  EXPECT_EQ(testCase.results,
            unordered_set<string>(results.begin(), results.end()));
}

vector<TestCase> generateTestCases() {
  vector<TestCase> testCases{
      {
          .number = "123",
          .target = 6,
          .results = {"1*2*3", "1+2+3"},
      },
      {
          .number = "232",
          .target = 8,
          .results = {"2*3+2", "2+3*2"},
      },
      {
          .number = "3456237490",
          .target = 9191,
          .results = {},
      },
      {
          .number = "105",
          .target = 5,
          .results = {"1*0+5", "10-5"},
      },
  };
  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));