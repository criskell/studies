insertionSort :: (Ord a) => [a] -> [a]
insertionSort = foldr insert []
  where
    insert x [] = [x]
    insert x (y : ys)
      | x <= y = x : y : ys
      | otherwise = y : insert x ys

main = do
  let sortedList = insertionSort [7, 3, 5, 6]
  print sortedList
