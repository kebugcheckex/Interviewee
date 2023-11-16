#include <fmt/format.h>

#include <algorithm>
#include <cmath>
#include <concepts>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

void recurse(int n, int target, std::vector<int> current,
             std::vector<std::vector<int>>& results) {
  if (n == 0 && target == 0) {
    results.push_back(current);
    return;
  }
  if (n < 0 || target == 0) {
    return;
  }

  for (int i = 0; i < target + 1; i++) {
    current.push_back(i);
    recurse(n - 1, target - i, current, results);
    current.pop_back();
  }
}

std::vector<std::vector<int>> findCombinations(int n, int target) {
  std::vector<std::vector<int>> results;
  recurse(n, target, {}, results);
  return results;
}

int compute(const std::vector<int>& priceA, const std::vector<int>& priceB,
            int numberOfItems) {
  int numberOfTypes = priceA.size();
  std::vector<std::vector<int>> costs(numberOfTypes,
                                      std::vector<int>(numberOfItems));
  for (int i = 0; i < numberOfTypes; i++) {
    for (int j = 0; j < numberOfItems; j++) {
      costs[i][j] = priceA.at(i) + (j - 1) * priceB.at(j);
    }
  }
  return 0;
}

int main() {
  auto res = findCombinations(3, 5);
  for (const auto& row : res) {
    for (const int i : row) {
      std::cout << i << ", ";
    }
    std::cout << "\n";
  }
  return 0;
}