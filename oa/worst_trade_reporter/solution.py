from enum import Enum
from collections import defaultdict, namedtuple


class TradeType(Enum):
    BUY = 1
    SELL = 2


Trade = namedtuple("Trade", ["id", "type", "price", "volume"])


class TradingSystem:
    positions = {}
    prices = defaultdict(int)

    def process_trade(
        self,
        trade_id: int,
        instrument_id: str,
        trade_type: TradeType,
        price: int,
        volume: int,
    ):
        if instrument_id not in self.positions:
            self.positions[instrument_id] = []
        self.positions[instrument_id].append(Trade(trade_id, trade_type, price, volume))

    def process_price_update(self, instrument_id: str, price: int):
        self.prices[instrument_id] = price

    def worst_trade(self, instrument_id: str) -> int:
        if instrument_id not in self.positions:
            return -1
        price = self.prices[instrument_id]
        min_pnl = 10**6 + 1
        worst_trade_id = -1
        for trade in self.positions[instrument_id]:
            if trade.type == TradeType.BUY:
                pnl = price - trade.price
            elif trade.type == TradeType.SELL:
                pnl = trade.price - price
            if pnl > 0:
                continue
            if pnl < min_pnl:
                min_pnl = pnl
                worst_trade_id = trade.id
        return worst_trade_id
