#include "header.h"

class SnakeGame {
 public:
  SnakeGame(int width, int height, vector<vector<int>>& food)
      : width_(width), height_(height), score_(0), foodIndex_(0) {
    for (const auto coord : food) {
      food_.push_back(encodeCoord(coord));
    }
    snake_.push(encodeCoord(0, 0));
    snakeLocations_.insert(encodeCoord(0, 0));
  }

  int move(string direction) {
    pair<int, int> current = decodeCoord(snake_.back());
    pair<int, int> next;
    switch (direction[0]) {
      case 'U':
        next = {current.first - 1, current.second};
        break;
      case 'D':
        next = {current.first + 1, current.second};
        break;
      case 'L':
        next = {current.first, current.second - 1};
        break;
      case 'R':
        next = {current.first, current.second + 1};
        break;
    }
    if (next.first < 0 || next.first >= height_ || next.second < 0 ||
        next.second >= width_) {
      cout << "\thit wall\n";
      return -1;
    }
    int nextEncoded = encodeCoord(next);
    cout << fmt::format("snake head {}, snake tail = {}, direction {}\n",
                        snake_.back(), snake_.front(), direction);
    utils::printUnorderedSet(snakeLocations_, "snake locations");
    if (nextEncoded != snake_.front() &&
        snakeLocations_.contains(nextEncoded)) {
      cout << fmt::format("\thit self {}, {}\n", next.first, next.second);
      return -1;
    }
    if (foodIndex_ < food_.size() && nextEncoded == food_.at(foodIndex_)) {
      foodIndex_ += 1;
      score_ += 1;
    } else {
      snakeLocations_.erase(snake_.front());
      snake_.pop();
    }
    snake_.push(nextEncoded);
    snakeLocations_.insert(nextEncoded);
    return score_;
  }

 private:
  int encodeCoord(const pair<int, int>& c) {
    return encodeCoord(c.first, c.second);
  }
  int encodeCoord(const vector<int>& c) { return encodeCoord(c[0], c[1]); };
  int encodeCoord(int row, int col) { return row * width_ + col; }

  pair<int, int> decodeCoord(int c) { return {c / width_, c % width_}; }

  int width_, height_, score_, foodIndex_;
  vector<int> food_;
  queue<int> snake_;
  unordered_set<int> snakeLocations_;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */