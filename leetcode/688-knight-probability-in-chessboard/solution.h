#include "header.h"

class Solution {
 public:
  double knightProbability(int n, int k, int row, int column) {
    boardSize_ = n;
    if (k == 0) {
      return 1.0;
    }
    directions_ = {
        {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
    };
    remainCount_ = 0;
    offBoardCount_ = 0;
    nextMove(row, column, k);
    cout << fmt::format("remain = {}, offboard = {}\n", remainCount_,
                        offBoardCount_);
    return (double)remainCount_ / (remainCount_ + offBoardCount_);
  }

  void nextMove(int row, int col, int remainingMoves) {
    cout << fmt::format("At ({}, {})\t", row, col);

    if (row < 0 || row >= boardSize_ || col < 0 || col >= boardSize_) {
      cout << "offboard\n";
      offBoardCount_ += 1;
      return;
    }
    if (remainingMoves == 0) {
      cout << "finished\n";
      remainCount_ += 1;
      return;
    }
    cout << "continue\n";
    for (const auto& direction : directions_) {
      nextMove(row + direction.first, col + direction.second,
               remainingMoves - 1);
    }
  }

 private:
  int boardSize_, totalMoves_, remainCount_, offBoardCount_;
  vector<pair<int, int>> directions_;
};