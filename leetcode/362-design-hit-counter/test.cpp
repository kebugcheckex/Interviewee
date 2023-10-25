#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  vector<string> operations;
  vector<int> timestamps;
  vector<int> expected;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {};

TEST_P(SolutionTest, AllTestCases) {
  auto [operations, timestamps, expected] = GetParam();
  HitCounter hitCounter;
  for (int i = 0; i < operations.size(); i++) {
    if (operations[i] == "hit") {
      hitCounter.hit(timestamps[i]);
    } else {
      int result = hitCounter.getHits(timestamps[i]);
      cout << "index = " << i << "\n";
      EXPECT_EQ(result, expected[i]);
    }
  }
}

vector<TestCase> generateTestCases() {
  vector<TestCase> testCases{{
      .operations = {"hit", "hit", "hit", "getHits", "hit", "getHits",
                     "getHits"},
      .timestamps = {1, 2, 3, 4, 300, 300, 301},
      .expected = {-1, -1, -1, 3, -1, 4, 3},
  }};
  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));