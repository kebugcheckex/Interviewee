from typing import List


class Solution:
    def count_count_good_string(self, low: int, high: int, zero: int, one: int) -> int:
        self.low = low
        self.high = high
        self.num_zeros = zero
        self.num_ones = one
        self.results = [0] * (high + 1)

        self.count(0)
        return self.results[high] - self.results[low - 1]

    # def count(self, current_length: int):
    #     if current_length > self.high:
    #         return 0
    #     if current_length >= self.low:
    #         self.result += 1
    #     self.count(current_length + self.num_zeros)
    #     self.count(current_length + self.num_ones)

    def count(self, length: int) -> int:
        if length + append > self.high:
            return 0
        if results[length] != -1:
            return results[length] + 1
        result[length] = self.count(length + self.num_zero) + self.count(
            length + self.num_ones
        )
