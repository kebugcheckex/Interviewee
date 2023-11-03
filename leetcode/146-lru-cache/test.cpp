#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  int capacity;
  std::vector<std::string> operations;
  std::vector<std::vector<int>> data;
  std::vector<int> output;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {};

TEST_P(SolutionTest, AllTestCases) {
  auto [capacity, operations, data, output] = GetParam();
  LRUCache cache(capacity);
  for (int i = 0; i < operations.size(); i++) {
    if (operations[i] == "put") {
      cache.put(data[i][0], data[i][1]);
    } else if (operations[i] == "get") {
      int result = cache.get(data[i][0]);
      EXPECT_EQ(result, output[i]);
    }
  }
}

std::vector<TestCase> generateTestCases() {
  std::vector<TestCase> testCases{
      {
          .capacity = 2,
          .operations = {"put", "put", "get", "put", "get", "put", "get", "get",
                         "get"},
          .data = {{1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}},
          .output = {-2, -2, 1, -2, -1, -2, -1, 3, 4},
      },
  };

  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));
