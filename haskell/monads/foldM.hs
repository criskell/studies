import Control.Monad (foldM)

-- Podemos utilizar foldM quando a computação envolve efeitos colaterais a cada passo.
-- Útil para encadear ações que dependem do resultado anterior ou do contexto monádico.

-- Assinatura:
-- foldM :: Monad m => (b -> a -> m b) -> b -> [a] -> m b
-- Onde:
--  - m é uma instância de Monad,
--  - b é o tipo do acumulador,
--  - a é o tipo dos elementos da lista.

safeAdd :: Int -> Int -> Either String Int
safeAdd acc x
  | x < 0 = Left "Numero negativo nao e permitido!"
  | otherwise = Right (acc + x)

sumSafe :: [Int] -> Either String Int
sumSafe = foldM safeAdd 0

step :: Int -> Int -> IO Int
step acc x = do
  print x
  return (acc + x)

sumWithPrint :: [Int] -> IO Int
sumWithPrint = foldM step 0

main = do
  let result1 = sumSafe [1, 2, 3, 4, 5]
  print result1

  let result2 = sumSafe [1, -2, 3, 4, 5]
  print result2

  result <- sumWithPrint [1, 2, 3, 4, 5]
  print result