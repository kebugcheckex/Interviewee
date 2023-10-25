#include "header.h"

int maxComputingPower(const vector<int>& processors) {
  map<int, int> powers;
  for (const int processor : processors) {
    powers[processor] += processor;
  }
  vector<int> results(powers.rbegin()->first + 1, 0);
  if (powers.contains(1)) {
    results[1] = powers[1];
  }
  for (int i = 2; i < results.size(); i++) {
    results[i] = max(results[i - 1], results[i - 2] + powers[i]);
  }
  return *results.rbegin();
}

int maxComputingPowerNew(const vector<int>& processors) {
  map<int, int> powers;
  for (const int processor : processors) {
    powers[processor] += processor;
  }
  vector<int> keys;
  for (const auto& p : powers) {
    keys.push_back(p.first);
  }
  map<int, int> results;
  results[keys[0]] = powers[keys[0]];
  results[keys[1]] = keys[1] - keys[0] == 1 ? powers[keys[1]]
                                            : powers[keys[0]] + powers[keys[1]];
  for (int i = 2; i < keys.size(); i++) {
    if (keys[i] - keys[i - 1] == 1) {
      results[keys[i]] =
          max(results[keys[i - 1]], results[keys[i - 2]] + powers[keys[i]]);
    } else {
      results[keys[i]] = results[keys[i - 1]] + powers[keys[i]];
    }
  }
  return results.rbegin()->second;
}

int main() {
  vector<int> data{3, 3, 3, 4, 4, 1, 8};
  int result = maxComputingPowerNew(data);
  cout << "Result = " << result << "\n";
  return 0;
}
