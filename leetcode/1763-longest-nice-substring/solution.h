#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestNiceSubstring(string s) {
        if (s.size() <= 1) {
            return "";
        }
        unordered_set<char> chars{s.begin(), s.end()};
        vector<int> indices{-1};
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch >= 'A' && ch <= 'Z' && !chars.contains(ch + 32)) {
                indices.push_back(i);
            } else if (ch >= 'a' && ch <= 'z' && !chars.contains(ch - 32)) {
                indices.push_back(i);
            }
        }
        if (indices.size() == 1) {
            return s;
        }
        indices.push_back(s.size());
        string longest{""};
        for (int i = 0; i < indices.size() - 1; i++) {
            int start = indices[i] + 1, length = indices[i + 1] - indices[i] - 1;
            auto substring = longestNiceSubstring(s.substr(indices[i] + 1, indices[i + 1] - indices[i] - 1));
            if (substring.size() > longest.size()) {
                longest = substring;
            }
        }
        return longest;
    }
};
int main() {
    Solution s;
    cout << s.longestNiceSubstring("C") << "\n";
    return 0;
}