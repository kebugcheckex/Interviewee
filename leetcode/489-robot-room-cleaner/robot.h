#include "header.h"

class Robot {
 public:
  Robot(std::vector<std::vector<int>> room, int initialRow, int initialCol);
  // Returns true if the cell in front is open and robot moves into the cell.
  // Returns false if the cell in front is blocked and robot stays in the
  // current cell.
  bool move();

  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();

  bool isAllCleaned();

 private:
  int direction_;  // 0 - up, 1 - right, 2 - down, 3 - left
  int row_, col_, rows_, cols_;
  std::vector<std::vector<int>> room_;
};