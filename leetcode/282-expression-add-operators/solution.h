#include "header.h"

class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    numbers_ = num;
    target_ = target;
    search(0, "", 0, 0);
    return solutions_;
  }

  void search(int index, string expression, long currentValue,
              long previousValue) {
    if (index >= numbers_.size()) {
      if (currentValue == target_) {
        solutions_.push_back(expression);
      }
      return;
    }
    for (int i = index; i < numbers_.size(); i++) {
      if (numbers_[index] == '0' && i > index) {
        return;
      }
      string number = numbers_.substr(index, i - index + 1);
      long value = stol(number);
      if (index == 0) {
        search(i + 1, number, value, value);
      } else {
        search(i + 1, expression + "+" + number, currentValue + value, value);
        search(i + 1, expression + "-" + number, currentValue - value, -value);
        search(i + 1, expression + "*" + number,
               currentValue - previousValue + previousValue * value,
               previousValue * value);
      }
    }
  }

 private:
  string numbers_;
  int target_;
  vector<string> solutions_;
};
