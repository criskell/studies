calculateSquares :: Int -> [Int]
calculateSquares max = takeWhile (\i -> i * i <= max) [0 ..]

main :: IO ()
main = do
  let squares = calculateSquares 103
  mapM_ (\x -> putStr (show x ++ " ")) squares
  putStrLn ""