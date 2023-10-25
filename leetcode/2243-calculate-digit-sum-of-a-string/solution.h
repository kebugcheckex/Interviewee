#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
   public:
    string digitSum(string s, int k) {
        ostringstream oss;
        int current = 0;
        while (s.size() >= k) {
            int currentGroup = 0;
            while (currentGroup * k < s.size()) {
                int currentIndex = currentGroup * k;
                int sum = 0;
                for (int i = currentIndex; i < currentIndex + k && i < s.size(); i++) {
                    sum += s[i] - '0';
                }
                oss << sum;
                currentGroup++;
            }
            s = oss.str();
            cout << s << "\n";
        }
        return oss.str();
    }
};

int main() {
    Solution s;
    cout << s.digitSum("11111222223", 3) << "\n";
    return 0;
}
