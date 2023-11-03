#include "robot.h"

static const std::vector<std::pair<int, int>> kOffsets = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

Robot::Robot(std::vector<std::vector<int>> room, int initialRow, int initialCol)
    : room_(std::move(room)),
      direction_(0),
      row_(initialRow),
      col_(initialCol) {
  rows_ = room_.size();
  cols_ = room_[0].size();
}

bool Robot::move() {
  int nextRow = row_ + kOffsets[direction_].first;
  int nextCol = col_ + kOffsets[direction_].second;

  if (nextRow < 0 || nextRow >= rows_ || nextCol < 0 || nextCol >= cols_ ||
      room_[nextRow][nextCol] == 0) {
    return false;
  }
  row_ = nextRow;
  col_ = nextCol;
  return true;
}

void Robot::turnLeft() { direction_ = (direction_ + 3) % 4; }

void Robot::turnRight() { direction_ = (direction_ + 1) % 4; }

void Robot::clean() { room_[row_][col_] = 2; }

bool Robot::isAllCleaned() {
  for (int row = 0; row < room_.size(); row++) {
    const auto& theRow = room_[row];
    for (int col = 0; col < theRow.size(); col++) {
      if (theRow[col] == 1) {
        return false;
      }
    }
  }
  return true;
}
