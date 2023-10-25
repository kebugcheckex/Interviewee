#include <iostream>
#include <map>
#include <vector>

class Solution {
   public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> treeMap;
        for (auto interval : intervals) {
            treeMap[interval[0]] += 1;
            treeMap[interval[1]] -= 1;
        }
        int rooms = 0, res = 0;
        for (auto it : treeMap) {
            printf() res = max(res, rooms += it.second);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> data{{0, 10}, {8, 20}, {15, 30}};
    cout << s.minMeetingRooms(data) << "\n";
}