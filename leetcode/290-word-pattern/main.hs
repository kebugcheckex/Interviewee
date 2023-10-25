import Data.List
import Data.Maybe

-- Function to find the pattern of a list of words
findPattern :: String -> [String] -> [Int]
findPattern pattern list = map fromJust $ filter isJust $ map (`elemIndex` list) pattern

-- Function to check if a string follows a given pattern
followsPattern :: String -> String -> Bool
followsPattern pattern s = patternList == sList
  where
    patternList = findPattern pattern (nub pattern)
    sList = findPattern s (words s)

main :: IO ()
main = do
  let pattern = "abba"
  let s = "dog cat cat dog"
  let result = followsPattern pattern s
  putStrLn $ "Pattern: " ++ pattern
  putStrLn $ "String: " ++ s
  putStrLn $ "Follows pattern: " ++ show result

-- Written by ChatGPT