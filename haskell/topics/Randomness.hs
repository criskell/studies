import System.Random
import Data.List

threeCoins :: StdGen -> (Bool, Bool, Bool)
threeCoins gen =
    let (firstCoin, newGen) = random gen
        (secondCoin, newGen') = random newGen
        (thirdCoin, _) = random newGen'
    in (firstCoin, secondCoin, thirdCoin)

randoms' :: (RandomGen g, Random a) => g -> [a]
randoms' gen = let (value, newGen) = random gen in value:randoms' newGen

finiteRandoms :: (RandomGen g, Random a, Num c, Eq c) => c -> g -> ([a], g)
finiteRandoms 0 gen = ([], gen)
finiteRandoms c gen =
    let (value, newGen) = random gen
        (restOfList, finalGen) = finiteRandoms (c - 1) newGen
    in (value:restOfList, finalGen)

-- Gets the same global generator!
-- main = do
--     gen <- getStdGen
--     putStrLn $ take 20 (randomRs ('a', 'z') gen)
--     newGen <- getStdGen
--     putStrLn $ take 20 (randomRs ('a', 'z') newGen)

-- main = do
--     gen <- getStdGen
--     let randomCharacters = randomRs ('a', 'z') gen
--         (first20, rest) = splitAt 20 randomCharacters
--         (second20, _) = splitAt 20 rest
--     putStrLn first20
--     putStr second20

main = do
    gen <- getStdGen
    putStrLn $ take 20 (randomRs ('a','z') gen)
    gen' <- newStdGen
    putStr $ take 20 (randomRs ('a','z') gen')