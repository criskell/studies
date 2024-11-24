-- import System.IO
-- import System.Directory
-- import Data.List

-- main = do
--     handle <- openFile "todos.txt" ReadMode
--     (tempName, tempHandle) <- openTempFile "." "temp"
    
--     contents <- hGetContents handle
--     let todoTasks = lines contents
--         numberedTasks = zipWith (\n line -> show n ++ " - " ++ line) [0..] todoTasks
    
--     putStrLn "These are your TO-DO items:"
--     putStr $ unlines numberedTasks
--     putStrLn "Which one do you want to delete?"
--     numberString <- getLine

--     let number = read numberString
--         newTodoItems = delete (todoTasks !! number) todoTasks

--     hPutStr tempHandle $ unlines newTodoItems
    
--     hClose handle
--     hClose tempHandle

--     removeFile "todos.txt"
--     renameFile tempName "todos.txt"

import System.Environment
import Data.List

main = do
    args <- getArgs
    progName <- getProgName
    
    putStrLn "The arguments are:"
    mapM putStrLn args
    
    putStrLn "The program name is:"
    putStrLn progName