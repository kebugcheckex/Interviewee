#include "header.h"
#include "utils.h"

class Solution {
 public:
  explicit Solution(std::vector<int>& weights) : distribution_(0.0, 1.0) {
    const double total = std::accumulate(weights.begin(), weights.end(), 0);
    std::vector<double> ranges(weights.size() + 1);
    std::transform(weights.begin(), weights.end(), std::next(ranges.begin()),
                   [total](int weight) { return weight / total; });
    std::partial_sum(ranges.cbegin(), ranges.cend(), ranges.begin());
    ranges_[0.0] = 0;
    for (int i = 1; i < ranges.size(); i++) {
      ranges_[ranges[i]] = i - 1;
    }
  }

  int pickIndex() {
    auto randomValue = distribution_(randomEngine_);
    return ranges_.upper_bound(randomValue)->second;
  }

  std::map<double, int> ranges_;
  std::default_random_engine randomEngine_;
  std::uniform_real_distribution<> distribution_;
};
