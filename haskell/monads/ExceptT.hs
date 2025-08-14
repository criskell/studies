{-# LANGUAGE OverloadedStrings #-}

import Control.Monad.Trans.Except
import Control.Monad.IO.Class
import System.IO
import Text.Read (readMaybe)

type AppError = String
type App = ExceptT AppError IO

readNumberFromFile :: FilePath -> App Int
readNumberFromFile path = do
  liftIO $ putStrLn $ "Reading from path: " ++ path

  content <- liftIO (readFile path)

  case readMaybe content of
    Nothing -> throwE "Content is not a valid number!"
    Just n -> return n

checkEven :: Int -> App ()
checkEven n =
  if even n
    then liftIO $ putStrLn "Number is even!"
    else throwE "Number is odd!"

main :: IO ()
main = do
  result <- runExceptT $ do
    n <- readNumberFromFile "number.txt"
    checkEven n

  case result of
    Left err -> putStrLn $ "Caught error: " ++ err
    Right _ -> return ()