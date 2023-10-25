#include "header.h"

class Coordinate {
 public:
  Coordinate(int x, int y) : x(x), y(y) {}

  Coordinate operator+(const Coordinate& other) const {
    return Coordinate(x + other.x, y + other.y);
  }

  Coordinate operator-(const Coordinate& other) const {
    return Coordinate(x - other.x, y - other.y);
  }

  size_t hash() const { return std::hash<int>{}(x) ^ std::hash<int>{}(y); }

  bool operator==(const Coordinate& other) const {
    return x == other.x && y == other.y;
  }

  int getX() const { return x; }
  int getY() const { return y; }
  int distanceFromOrigin() const { return x * x + y * y; }

  friend ostream& operator<<(ostream& os, const Coordinate& c) {
    os << "(" << c.x << ", " << c.y << ")";
    return os;
  }

 private:
  int x, y;
};

template <>
struct std::hash<Coordinate> {
  size_t operator()(const Coordinate& c) const noexcept {
    return c.getX() * 100000 + c.getY();
  }
};

class Solution {
 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    const vector<Coordinate> directions{
        {0, 1},
        {-1, 0},
        {0, -1},
        {1, 0},
    };
    Coordinate currentLocation{0, 0};
    unordered_set<Coordinate> obstaclesSet;
    int farthest = 0;
    for (const auto& obstacle : obstacles) {
      obstaclesSet.insert({obstacle[0], obstacle[1]});
    }
    int orientation = 0;  // 0 - north, 1 west, 2 south, 3 east
    for (const int command : commands) {
      switch (command) {
        case -2:
          orientation = (orientation + 1) % 4;
          break;
        case -1:
          orientation = (orientation + 3) % 4;
          break;
        default:
          for (int i = 0; i < command; i++) {
            auto nextLocation = currentLocation + directions[orientation];
            if (obstaclesSet.contains(nextLocation)) {
              break;
            }
            currentLocation = nextLocation;
            farthest = max(farthest, currentLocation.distanceFromOrigin());
          }
      }
    }
    return farthest;
  }
};
