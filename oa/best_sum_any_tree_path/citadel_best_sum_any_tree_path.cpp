#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

#include "../json.hpp"

using namespace std;
using json = nlohmann::json;

typedef struct NodeStruct {
    int value;
    vector<int> children;
} Node;

vector<Node> constructNodes(const vector<int>& parents, const vector<int>& values) {
    vector<Node> nodes(parents.size());
    for (int i = 0; i < parents.size(); i++) {
        Node node;
        node.value = values[i];
        nodes[i] = move(node);
    }
    for (int i = 0; i < parents.size(); i++) {
        int parent = parents[i];
        if (parent == -1) {
            continue;
        }
        nodes[parent].children.push_back(i);
    }
    return nodes;
}

int searchDfs(const vector<Node>& nodes, int currentNodeIndex, int& maxValue) {
    auto& node = nodes[currentNodeIndex];
    if (node.children.empty()) {
        // For nodes with no children, the max gain is the node's value.
        // Yes, it can be negative. This case is handled later.
        if (node.value > maxValue) {
            maxValue = node.value;
        }
        return node.value;
    }

    vector<int> results;
    for (const int childIndex : node.children) {
        results.push_back(max(searchDfs(nodes, childIndex, maxValue), 0));
    }
    sort(results.begin(), results.end(), greater<int>());
    int currentNodeMaxSum = node.value + results[0];
    if (results.size() >= 2) {
        currentNodeMaxSum += results[1];
    }
    if (currentNodeMaxSum > maxValue) {
        maxValue = currentNodeMaxSum;
    }
    // return the max child path sum plus the current node value
    return results[0] + node.value;
}

int maxSumAnyPathRecursive(const vector<int>& parents, const vector<int>& values) {
    auto nodes = constructNodes(parents, values);
    int maxValue = numeric_limits<int>::min();
    searchDfs(nodes, 0, maxValue);
    return maxValue;
}

int maxSumAnyPathIterative(const vector<int>& parents, const vector<int>& values) {
    auto nodes = constructNodes(parents, values);
    int maxValue = numeric_limits<int>::min();
}

int main() {
    // vector<int> parents{-1, 0, 1, 2, 0};
    // vector<int> values{-2, 10, 10, -3, 10};
    fstream testCaseFile("test_cases.json");
    json testCases = json::parse(testCaseFile);
    for (const auto& testCase : testCases) {
        vector<int> values = testCase["values"];
        vector<int> parents = testCase["parents"];
        int result = testCase["result"];
        int actual = maxSumAnyPathRecursive(parents, values);
        if (result == actual) {
            cout << "test case passed\n";
        } else {
            cout << "test case failed\n\texpected: " << result << ", actual: " << actual << "\n";
        }
    }
    return 0;
}