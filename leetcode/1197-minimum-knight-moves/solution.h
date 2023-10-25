#include "header.h"

struct PairHash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution {
   public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        if (x == 1 && y == 1) {
            return 2;
        }
        vector<pair<int, int>> directions{
            {-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}, {1, -2}, {1, 2}, {2, -1}, {2, 1},
        };
        queue<tuple<int, int, int>> locations{};  // (x, y, moves)
        locations.push({0, 0, 0});
        unordered_set<pair<int, int>, PairHash> enqueued{{0, 0}};

        while (!locations.empty()) {
            auto location = locations.front();
            locations.pop();
            int currentX = get<0>(location);
            int currentY = get<1>(location);
            int moves = get<2>(location);
            if (currentX == x && currentY == y) {
                return moves;
            }
            for (const auto& direction : directions) {
                int nextX = currentX + direction.first;
                int nextY = currentY + direction.second;
                if (nextX < 0 || nextX > 300 || nextY < 0 || nextY > 300) {
                    continue;
                }
                pair<int, int> nextLocation{nextX, nextY};
                if (enqueued.contains(nextLocation)) {
                    continue;
                }
                enqueued.insert(nextLocation);
                locations.push({nextX, nextY, moves + 1});
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    int result = s.minKnightMoves(60, 30);
    cout << "Min moves = " << result << "\n";
    return 0;
}
