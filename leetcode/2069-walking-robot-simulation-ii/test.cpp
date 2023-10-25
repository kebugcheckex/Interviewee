#include <gtest/gtest.h>

#include "solution.h"

typedef struct StructTestCase {
  vector<string> functions;
  vector<vector<int>> data;
  vector<variant<vector<int>, string>> results;
} TestCase;

class SolutionTest : public testing::TestWithParam<TestCase> {};

TEST_P(SolutionTest, AllTestCases) {
  auto& [functions, data, results] = GetParam();
  std::unique_ptr<Robot> robot;
  for (int i = 0; i < functions.size(); i++) {
    if (functions[i] == "Robot") {
      robot = make_unique<Robot>(data[i][0], data[i][1]);
    } else if (functions[i] == "step") {
      robot->step(data[i][0]);
    } else if (functions[i] == "getPos") {
      auto result = robot->getPos();
      EXPECT_EQ(get<vector<int>>(results[i]), result);
    } else if (functions[i] == "getDir") {
      auto result = robot->getDir();
      EXPECT_EQ(get<string>(results[i]), result);
    } else {
      cout << "Unknown function " << functions[i] << "\n";
      EXPECT_TRUE(false);
    }
  }
}

vector<TestCase> generateTestCases() {
  vector<TestCase> testCases{
      {
          .functions = {"Robot", "step", "step", "getPos", "getDir", "step",
                        "step", "step", "getPos", "getDir"},
          .data = {{6, 3}, {2}, {2}, {}, {}, {2}, {1}, {4}, {}, {}},
          .results = {"", "", "", vector<int>{4, 0}, "East", "", "", "",
                      vector<int>{1, 2}, "West"},
      },
      {
          .functions = {"Robot", "step", "step", "step", "getPos", "getDir",
                        "step", "getPos", "getDir", "step", "getPos", "getDir"},
          .data = {{100, 100},
                   {31811},
                   {63679},
                   {19676},
                   {},
                   {},
                   {67390},
                   {},
                   {},
                   {25768},
                   {},
                   {}},
          .results = {"", "", "", "", vector<int>{0, 70}, "South", "",
                      vector<int>{0, 0}, "South", "", vector<int>{28, 0},
                      "East"},
      },
  };
  return testCases;
}

INSTANTIATE_TEST_SUITE_P(DefaultTestSuite, SolutionTest,
                         testing::ValuesIn(generateTestCases()));
