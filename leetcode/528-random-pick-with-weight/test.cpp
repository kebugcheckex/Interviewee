#include <gtest/gtest.h>

#include "solution.h"

int main() {
  // TODO: fix the seed of the random number generator so that we can test the
  // solution class with deterministic data
  std::vector<int> weights{1, 2, 3, 4};
  Solution s(weights);
  for (int i = 0; i < 10; i++) {
    std::cout << s.pickIndex() << " ";
  }
  return 0;
}
