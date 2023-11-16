#pragma once

#include "header.h"

template <typename T>
concept Printable = std::is_same_v<T, int> || std::is_same_v<T, float> ||
                    std::is_same_v<T, double> || std::is_same_v<T, char> ||
                    std::is_same_v<T, std::string>;

struct OrderedPairHash {
  std::size_t operator()(const std::pair<int, int>& p) const {
    // Use a combination of the hashes of the two integers
    // to create a unique hash for the pair.
    std::hash<int> hasher;
    std::size_t hash1 = hasher(p.first);
    std::size_t hash2 = hasher(p.second);

    // Combine the two hashes using a simple bitwise operation.
    // You can use other techniques like XOR (^) or shift (<<) as well.
    return hash1 ^ (hash2 << 1);
  }
};

namespace utils {

// TODO figure out how to correctly use this
// template < Printable Key, Printable Value>
void printMap(const std::unordered_map<char, int>& data,
              const std::string title = "untitled");

void printUnorderedSet(const std::unordered_set<int>& data,
                       std::string title = "untitiled");

void printSet(const std::set<int>& data, std::string title = "untitled");

template <typename T>
void printVectorOfVector(const std::vector<std::vector<T>>& data,
                         std::string title = "untitiled");

// Print a map of int -> list<int>
std::ostream& operator<<(std::ostream& ostr,
                         const std::unordered_map<int, std::list<int>>& data);

}  // namespace utils
