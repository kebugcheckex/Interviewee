import qualified Data.Set as Set

substring :: String -> Int -> Int -> String
substring str start len = take len (drop start str)

wordBreak :: String -> Set String -> [Bool] -> [Bool]
wordBreak "" _ _ = [True]
wordBreak str words dp = 

main :: IO()
main = do
    putStrLn $ substring "Hello, world" 2 4
