#include "header.h"
#include "utils.h"

struct PairHash {
  std::size_t operator()(const std::pair<char, char>& p) const {
    // Combine the hashes of the two characters
    std::hash<char> charHash;
    size_t hash1 = charHash(p.first);
    size_t hash2 = charHash(p.second);
    return hash1 ^ (hash2 << 1);
  }
};

void toSExpression(std::map<char, std::vector<char>>& tree, char node,
                   std::ostringstream& output) {
  output << '(' << node;
  auto& children = tree.at(node);
  if (!children.empty()) {
    sort(children.begin(), children.end());
    for (const char child : children) {
      toSExpression(tree, child, output);
    }
  }
  output << ')';
}

std::string validateBinaryTree(const std::string& inputLine) {
  std::stringstream ss(inputLine);
  std::unordered_set<std::pair<char, char>, PairHash> edges;
  char leftParen, rightParen, ch1, ch2, comma;
  while (ss >> leftParen >> ch1 >> comma >> ch2 >> rightParen) {
    if (leftParen != '(' || rightParen != ')' || comma != ',') {
      return "E1";  // invalid input format
    }
    if (ch1 < 'A' || ch1 > 'Z' || ch2 < 'A' || ch2 > 'Z') {
      return "E1";  // invalid input format
    }
    std::pair<char, char> edge{ch1, ch2};
    if (edges.contains(edge)) {
      return "E2";  // duplicate pair
    }
    edges.insert(std::move(edge));
  }
  std::map<char, std::vector<char>> tree;
  std::unordered_map<char, int> indegrees;
  for (const auto& [parent, child] : edges) {
    if (!indegrees.contains(parent)) {
      indegrees[parent] = 0;
    }
    if (!tree.contains(parent)) {
      tree[parent] = {child};
    } else if (tree.at(parent).size() >= 2) {
      return "E3";  // parent has more than two children
    } else {
      tree.at(parent).push_back(child);
    }
    indegrees[child] += 1;
    if (!tree.contains(child)) {
      tree[child] = {};
    }
  }
  char root = '\0';
  for (const auto [node, indegree] : indegrees) {
    if (indegree > 1) {
      return "E5";  // undirected cycle
    }
    if (indegree == 0) {
      if (root == '\0') {
        root = node;
      } else {
        return "E4";  // multiple roots
      }
    }
  }
  if (root == '\0') {
    return "E5";  // no root, contains cycle
  }

  std::ostringstream oss;
  toSExpression(tree, root, oss);
  return oss.str();
}
