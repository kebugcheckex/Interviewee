#include "header.h"
#include "robot.h"
#include "utils.h"

const std::unordered_map<int, std::string> kDirectionName{
    {0, "Up"},
    {1, "Right"},
    {2, "Down"},
    {3, "Left"},
};

class Solution {
 public:
  Solution() {
    // directions: 0 - up, 1 -right, 2 - down, 3 - left
    directions_ = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  }
  void cleanRoom(Robot& robot) { search(robot, 0, 0, 0); }

 private:
  void returnToPrevious(Robot& robot) {
    robot.turnLeft();
    robot.turnLeft();
    robot.move();
    robot.turnLeft();
    robot.turnLeft();
  }
  void search(Robot& robot, int row, int col, int direction) {
    robot.clean();
    visited_.insert({row, col});
    for (int i = 0; i < 4; i++) {
      direction = (direction + 1) % 4;
      robot.turnRight();
      int nextRow = directions_.at(direction).first + row;
      int nextCol = directions_.at(direction).second + col;
      std::pair<int, int> nextCoord{nextRow, nextCol};
      if (!visited_.contains(nextCoord) && robot.move()) {
        visited_.insert(nextCoord);
        search(robot, nextRow, nextCol, direction);
        returnToPrevious(robot);
      }
    }
  }

  std::unordered_set<std::pair<int, int>, OrderedPairHash> visited_;
  std::vector<std::pair<int, int>> directions_;
};

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the
 * cell.
 *     // Returns false if the cell in front is blocked and robot stays in the
 * current cell. bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
