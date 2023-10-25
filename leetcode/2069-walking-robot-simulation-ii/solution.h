#include "header.h"

class Robot {
 public:
  Robot(int width, int height)
      : width(width),
        height(height),
        x(0),
        y(0),
        dir(3),
        directionNames{"North", "West", "South", "East"} {
    directions = {
        {0, 1},
        {-1, 0},
        {0, -1},
        {1, 0},
    };
    circ = width * 2 + height * 2 - 4;
  }

  void step(int num) {
    if (circ > 0) {
      num %= circ;
    }
    int index = 0;
    while (index < num) {
      int nextX = x + directions[dir].first;
      int nextY = y + directions[dir].second;
      if (nextX < 0 || nextX >= width || nextY < 0 || nextY >= height) {
        dir = (dir + 1) % 4;
        continue;
      }
      x = nextX;
      y = nextY;
      index += 1;
    }
  }

  vector<int> getPos() { return {x, y}; }

  string getDir() { return directionNames[dir]; }

 private:
  int width, height, circ;
  int x, y;  // current location
  int dir;   // current direction north 0, west 1, south 2, east 3
  const string directionNames[4];
  vector<pair<int, int>> directions;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */