#include "utils.h"

namespace utils {

// template <Printable Key, Printable Value>
void printMap(const std::unordered_map<char, int>& data,
              const std::string title) {
  std::cout << "======== [BEGIN] " << title << " ========\n";
  std::cout << fmt::format("\tmap size = {}\n", data.size());
  for (const auto& [key, value] : data) {
    std::cout << fmt::format("\t{}: {}\n", key, value);
  }
  std::cout << "======== [END] " << title << " ========\n";
}

template <typename T>
void printVectorOfVector(const std::vector<std::vector<T>>& data,
                         std::string title) {
  std::cout << "===== BEGIN " << title << " =====\n";
  for (const auto& row : data) {
    for (int i = 0; i < row.size() - 1; i++) {
      std::cout << row[i] << ", ";
    }
    std::cout << *row.rbegin() << "\n";
  }
  std::cout << "===== END " << title << " =====\n";
}

void printUnorderedSet(const std::unordered_set<int>& data, std::string title) {
  std::cout << "===== BEGIN " << title << " =====\n";
  for (auto it = data.begin(); it != data.end(); ++it) {
    std::cout << *it << ", ";
  }
  std::cout << "\b\b\n===== END " << title << " =====\n";
}

void printSet(const std::set<int>& data, std::string title) {
  std::cout << "===== BEGIN " << title << " =====\n";
  for (auto it = data.begin(); it != data.end(); ++it) {
    std::cout << *it << ", ";
  }
  std::cout << "\b\b\n===== END " << title << " =====\n";
}

}  // namespace utils
