import unittest
from collections import namedtuple
from parameterized import parameterized

from solution import TradeType, TradingSystem

PRICE = "process_price_update"
TRADE = "process_trade"
WORST_TRADE = "worst_trade"

TestCase = namedtuple("TestCase", ("operation", "parameters", "result"))

# make sure each test case ends with a comma as it is a tuple
test_cases = [
    (
        [
            TestCase(PRICE, {"instrument_id": "Facebook", "price": 80}, None),
            TestCase(PRICE, {"instrument_id": "Apple", "price": 120}, None),
            TestCase(
                TRADE,
                {
                    "trade_id": 100,
                    "instrument_id": "Apple",
                    "trade_type": TradeType.SELL,
                    "price": 90,
                    "volume": 2,
                },
                None,
            ),
            TestCase(
                TRADE,
                {
                    "trade_id": 10,
                    "instrument_id": "Facebook",
                    "trade_type": TradeType.BUY,
                    "price": 100,
                    "volume": 4,
                },
                None,
            ),
            TestCase(WORST_TRADE, {"instrument_id": "Facebook"}, 10),
            TestCase(WORST_TRADE, {"instrument_id": "Apple"}, 100),
        ],  # tuple, comma is necessary
    ),
    (
        [
            TestCase(PRICE, {"instrument_id": "Google", "price": 100}, None),
            TestCase(
                TRADE,
                {
                    "trade_id": 1,
                    "instrument_id": "Google",
                    "trade_type": TradeType.BUY,
                    "price": 100,
                    "volume": 10,
                },
                None,
            ),
            TestCase(WORST_TRADE, {"instrument_id": "Google"}, -1),
            TestCase(
                TRADE,
                {
                    "trade_id": 2,
                    "instrument_id": "Google",
                    "trade_type": TradeType.SELL,
                    "price": 102,
                    "volume": 5,
                },
                None,
            ),
            TestCase(
                TRADE,
                {
                    "trade_id": 3,
                    "instrument_id": "Google",
                    "trade_type": TradeType.SELL,
                    "price": 103,
                    "volume": 5,
                },
                None,
            ),
            TestCase(PRICE, {"instrument_id": "Google", "price": 98}, None),
            TestCase(WORST_TRADE, {"instrument_id": "Google"}, 1),
            TestCase(
                TRADE,
                {
                    "trade_id": 4,
                    "instrument_id": "Google",
                    "trade_type": TradeType.BUY,
                    "price": 101,
                    "volume": 10,
                },
                None,
            ),
            TestCase(
                TRADE,
                {
                    "trade_id": 5,
                    "instrument_id": "Google",
                    "trade_type": TradeType.BUY,
                    "price": 100,
                    "volume": 10,
                },
                None,
            ),
            TestCase(WORST_TRADE, {"instrument_id": "Google"}, 4),
        ],  # tuple, comma is necessary
    ),
]


class TestSolution(unittest.TestCase):
    @parameterized.expand(test_cases)
    def test_case(self, test_case):
        ts = TradingSystem()
        for action in test_case:
            method = getattr(ts, action.operation)
            result = method(**action.parameters)
            if method == WORST_TRADE:
                self.assertEqual(result, action.result)


if __name__ == "__main__":
    unittest.main()
