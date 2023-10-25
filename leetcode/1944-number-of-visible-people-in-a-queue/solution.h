#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int size = h.size();
        vector<int> ans(size, 0);
        stack<int> st;
        st.push(h[size - 1]);

        for (int i = size - 2; i >= 0; i--) {
            int num = 0;

            while (!st.empty() && st.top() < h[i]) {
                st.pop();
                num++;
            }

            if (!st.empty()) {
                num++;
            }

            st.push(h[i]);
            ans[i] = num;
        }

        return ans;
    }
};

int main() {
    vector<int> data{10, 6, 8, 5, 11, 9};
    Solution s;
    auto res = s.canSeePersonsCount(data);
    for (const auto val : res) {
        cout << val << ", ";
    }
    cout << "\n";
    return 0;
}