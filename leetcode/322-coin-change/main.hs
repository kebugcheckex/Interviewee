findSolution :: [Int] -> Int -> Int
findSolution coins remaining
    | remaining < 0 = -1
    | remaining == 0 = 0
    | remaining > 0 = minimum (map (\x -> 1 + findSolution coins (remaining - x)) coins)

coinChange :: [Int] -> Int -> Int
coinChange _ 0 = 0
coinChange coins target = findSolution coins target
