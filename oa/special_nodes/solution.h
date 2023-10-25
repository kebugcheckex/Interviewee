#pragma once

#include "header.h"

typedef struct StructSearchResult {
  int maxPathLength;
  vector<int> edgeNodes;
} SearchResult;

typedef vector<set<int>> Graph;

// find the end of second largest value's index
// e.g. [6, 6, 6, 5, 5, 3, 3, 2, 1] => returns 5, index of the first 3
int findFirstSecondLargesIndex(const vector<SearchResult>& data) {
  int largest = data.at(0).maxPathLength;
  int index = 1;
  for (; index < data.size(); index++) {
    if (data.at(index).maxPathLength < largest) {
      break;
    }
  }
  if (index == data.size()) {
    return index;
  }
  largest = data.at(index).maxPathLength;
  for (; index < data.size(); index++) {
    if (data.at(index).maxPathLength < largest) {
      break;
    }
  }
  return index;
}

// return value is a piar of (maxLength, all edge nodes belong to the longest
// path)
SearchResult search(const Graph& graph, int node, int& maxLength,
                    unordered_set<int>& specialNodes) {
  if (graph[node].empty()) {
    return {
        .maxPathLength = 1,
        .edgeNodes = {node},
    };
  }
  vector<SearchResult> searchResults;
  for (const int child : graph[node]) {
    searchResults.push_back(search(graph, child, maxLength, specialNodes));
  }
  sort(searchResults.begin(), searchResults.end(),
       [](const SearchResult& a, const SearchResult& b) {
         return a.maxPathLength > b.maxPathLength;
       });

  // the max path length crossing the current node is the sum of the lengths of
  // its first two children with max path length
  int currentLength = searchResults[0].maxPathLength;
  if (searchResults.size() >= 2) {
    currentLength += searchResults[1].maxPathLength;
  }

  vector<int> edgeNodes;
  if (currentLength >= maxLength) {
    if (currentLength > maxLength) {
      specialNodes.clear();
      maxLength = currentLength;
    }

    int index = findFirstSecondLargesIndex(searchResults);
    for (int i = 0; i < index; i++) {
      auto& nodes = searchResults[i].edgeNodes;
      for (const auto node : nodes) {
        specialNodes.insert(node);
        edgeNodes.push_back(node);
      }
    }
  }
  return {searchResults[0].maxPathLength + 1, edgeNodes};
}

vector<int> isSpecial(int n, const vector<pair<int, int>>& edges) {
  vector<set<int>> graph(n + 1);
  vector<int> indegrees(n + 1);
  for (const auto& edge : edges) {
    graph[edge.first].insert(edge.second);
    indegrees[edge.second] += 1;
  }
  int root;
  for (int i = 1; i <= n; i++) {
    if (indegrees[i] == 0) {
      root = i;
      break;
    }
  }

  int maxLength = 0;
  unordered_set<int> specialNodes;
  search(graph, root, maxLength, specialNodes);
  if (specialNodes.size() <= 1) {
    specialNodes.insert(root);
  }
  vector<int> results(n + 1);
  for (const int node : specialNodes) {
    results[node] = 1;
  }
  return results;
}
