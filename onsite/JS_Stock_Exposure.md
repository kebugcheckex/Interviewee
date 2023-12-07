首先给出ETF的定义，比如一股SPY里包含3股AAPL, 5股MSFT, 2股META. 这个叫做成分股 compositions. 数据类型是 `Dict[str, float]` （不一定是整数）
然后给出exposure的定义，就是一个portifolio里，某一个股票和它在各个ETF里的总价值。比如，portifolio里有10股AAPL, 5股SPY, 当前AAPL的股价是$10, 那么AAPL的exposure就是 `10*$10 + 5*3*$10 = $250`.

首先写一个function, 计算一个股票的exposure. 输入的参数是 compositions, prices, 输出一个 dollar value.

```python
def compute_exposure(compositions: Dict[str, Dict[str, float]], prices: Dict[str, float]) -> float:
    pass
```

然后要实现一个class, 来计算如何 minimize the exposure of a stock. 比如现在的持仓里AAPL的exposure有$3000, 我们要把这个exposure降低到$2000. 那么应该如何卖出股票和ETF, 同时还要尽量减小对其他股票的exposure的影响。注意，股票的股数不一定是整数。

```python
class TradeSystem:

    def __init__(compositions: Dict[str, Dict[str, float]], prices: Dict[str, float], positions: Dict[str, float])：
        pass

    def on_composition_change(etf: str, composition: Dict[str, float]):
        pass
    
    def minimize_exposure(symbol: str, minimize_goal: float) -> List[Tuple[str, float]]:
        pass
```
