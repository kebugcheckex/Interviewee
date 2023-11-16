import unittest
from collections import namedtuple
from parameterized import parameterized

from solution import Solution

TestCase = namedtuple("TestCase", ("low", "high", "zero", "one", "expected"))

test_cases = [
    TestCase(3, 3, 1, 1, 8),
    TestCase(2, 3, 1, 2, 5),
    # TestCase(200, 200, 10, 1, 764262396),
]


class TestSolution(unittest.TestCase):
    @parameterized.expand(test_cases)
    def test_case(self, low, high, zero, one, expected):
        s = Solution()
        result = s.countGoodStrings(low, high, zero, one)
        self.assertEqual(result, expected)


if __name__ == "__main__":
    unittest.main()
