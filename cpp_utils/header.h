#include <fmt/format.h>

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

// This is normally a bad practice, especially in headers. But we are solve
// interview questions, so why not?
using namespace std;

namespace utils {
template <typename T>
void printVectorOfVector(const vector<vector<T>>& data,
                         string title = "untitiled") {
  cout << "===== BEGIN " << title << " =====\n";
  for (const auto& row : data) {
    for (int i = 0; i < row.size() - 1; i++) {
      cout << row[i] << ", ";
    }
    cout << *row.rbegin() << "\n";
  }
  cout << "===== END " << title << " =====\n";
}

void printUnorderedSet(const unordered_set<int>& data,
                       string title = "untitiled") {
  cout << "===== BEGIN " << title << " =====\n";
  for (auto it = data.begin(); it != data.end(); ++it) {
    cout << *it << ", ";
  }
  cout << "\b\b\n===== END " << title << " =====\n";
}

}  // namespace utils