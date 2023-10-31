#pragma once

#include "header.h"

template <typename T>
concept Printable = std::is_same_v<T, int> || std::is_same_v<T, float> ||
                    std::is_same_v<T, double> || std::is_same_v<T, char> ||
                    std::is_same_v<T, std::string>;

// template <typename T>
// concept GeneticMap = std::is_same_v<T, std::map<K, V>> || std::is_same_v < T,
//         std::unordered_map<T, std::unordered_map<K, V>>;

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

}  // namespace utils
