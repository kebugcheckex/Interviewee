# Worst Trade Reporter

> Note: ??? in the text below means missing content due to original image missing those parts.

You are tasked with building a tool to analyze the profitability of _trades_ (also known as "profit and loss" or PnL). For the purpose of this problem, every _trade_ has the following attributes:

- _TradeID_ - unique identifier of the trade,
- _InstrumentID_ - identifier of the instrument that has been traded,
- _Buy/Sell_ - flag to indicate whether you bought or sold the instrument,
- _Price_ - the price at which the instrument has been traded,
- _Volume_ - the quantity of the instrument that has been traded.

Consider a trade with the following attributes:

- _TradeID_ = 5,
- _InstrumentID_ = Google,
- _Buy/Sell_ = BUY,
- _Price_ = 500,
- _Volume_ = 20.

It means that you bought 20 lots of Google stock for 500 dollars and the indentifier for the trade is 5.

Note that trades have a _TradeID_ because there can be multiple trades with the same _InstrumentID_, _Buy/Sell_, _Price_ and _Volume_ attributes.

## Problem Statement

In this task, you receive a stream of N instructions. Each instruction can be an update. An update can be of 2 kinds:

- _Trade_ - indicates that a trade has happened. Attributes: _TradeID_, _InstrumentID_, _Buy/Sell_ ??? and _Volume_.
- _Price_ - indicates that the true value of an instrument has been updated. Attributes: _InstrumentID_ and _Price_.

There is only 1 kind of query:

- _WorstTrade_ - output the _TradeID_ of the _worst trade_ for an instrument. Attributes: _InstrumentID_ ???

The _WorstTrade_ is the trade with highest loss made per-lot of the trade. To calculate ??? trade the latest price update for an instrument is used as the true value of the instrument. ???

- If you sell 2Google stock for 500 each, and had the latest price update saying Google ??? 400, the PnL for the trade is (500 - 400) * 2 = 200.
- If you laater get a price update saying Google is worth 600, the PnL for the same trade is (500 - 600) * 2 = -200.

In the example above, initially we make a profit-per-lot of 200 / 2 = 100, and after the ??? update it is a loss-per-lot of 200 / 2 = 100.

- In case of ties for the worst trade, output the latest one.
- In case there are no trades that result in a loss from the instrument, output NO BAD TRADE ???

## Function Description

Your task is to implement a class that provides methods `ProcessTrade`, `ProcessPriceUpdate`, `OutputWorstTrade`. These methods ??? correspond to the instructions described above with the method arguments corresponding to the update or query attributes.

## Constraints

- 1 <= N, _TradeID_, _Price_, _Volume_ <= 10^6
- It is guaranteed that price update for an instrument is available before first trade ??? instrument.

## Input Format For Custom Testing

Input to the program is specified using a simple text format. The format and deta??? are not relevant to answering the question but custom input can be used to help ??? development and debugging.

The first line of input contains an integer `N` that denotes the number of instructions ??? the `N` subsequent lines contains either an _update_ or a _query_ in the format below:

Update:

- `TRADE <TradeID> <InstrumentID> <BUY/SELL> <Price> <Volume>`
- `PRICE <InstrumentID> <Price>`

Query:

- `WORST_TRADE <InstrumentID>`

Some example inputs and their expected outputs are described below.

### Sample Case 1

Sample input for custom testing:

```
6
PRICE Facebook 80
PRICE Apple 120
TRADE 100 Apple SELL 90 2
TRADE 10 Facebook BUY 100 4
WORST_TRADE Facebook
WORST_TRADE Apple
```

Expected output:
```
10
100
```

Explanation:

There are 2 instruments (Apple and Facebook), each of which has 1 trade. There are ??? 1 for each instrument.

1. PnL from TradeID 100: (90 - 120) * 2 = -60
    - Apple price at the time of the trade is 120 and we sell at 90, so we make a total loss ??? trade 2 lots, so the lost-per-lot is 30.
2. PnL from TradeID 10: (100 - 80) * 4 = 80
    - Facebook price at the time of the trade is 80 and we buy at 100, so we make a total ??? We trade 4 lots, so in total we make a loss-per-lot of 20.

For both Facebook and Apple, we do exactly one bad trade which is hence also the ??? for each instrument.

### Sample Case 2

Sample input for custom testing:
```
10
PRICE Google 100
TRADE 1 Google BUY 100 10
WORST_TRADE Google
TRADE 2 Google SELL 102 5
TRADE 3 Google SELL 103 5
PRICE Google 98
WORST_TRADE Google
TRADE 4 Google BUY 101 10
TRADE 5 Google BUY 100 10
WORST_TRADE Google
```

Expected output:
```
NO BAD TRADES
1
4
```

Explanation:

First `WorstTrade` query:

- PnL from TradeID 1: (100 - 100) * 10 = 0.
- There are no trades that result in a loss (PnL < 0), so there are no bad trades.

PnLs before second `WorstTrade` query:

- PnL from TradeID 1: (98 - 100) * 10 = -20
- PnL from TradeID 2: (102 - 98) * 5 = 20
- PnL from TradeID 3: (103 - 98) * 5 = 25

Second `WorstTrade` query:

- From the PnL values above, only trade with TradeID 1 results in a loss, so it is indeed the worst trade.

PnLs before third `WorstTrade` query:

- Net PnL for TradeID 1, 2, 3,: 25
- PnL from TradeID 4: (98 - 101) * 10 = -30
- PnL from TradeID 5: (98 - 100) * 10 = -20

Third `WorstTrade` query:

- There are 3 trades (TradeID = 1, 4, 5) that result in a loss and the loss-per-lot for each of them are 2, 3 and 2 respectively.
- So worst trade would be trade with TradeID 4.