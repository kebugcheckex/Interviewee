#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        float totalTax = 0., percent = 0.;
        int index = 0, prev = 0, upper;
        while (index < brackets.size()) {
            upper = brackets[index][0];
            percent = brackets[index][1] / 100.;
            if (income > upper) {
                totalTax += (upper - prev) * percent;
                cout << "total = " << totalTax << "\n";
                prev = upper;
                index++;
            } else {
                break;
            }
        }
        if (index < brackets.size()) {
            totalTax += (income - prev) * percent;
        }
        return totalTax;
    }
};

int main() {
    Solution s;
    vector<vector<int>> input{{3, 50}, {7, 10}, {12, 25}};
    cout << s.calculateTax(input, 10) << "\n";
}