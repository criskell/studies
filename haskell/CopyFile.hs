import System.Environment
import qualified Data.ByteString.Lazy as B

main = do
    (source:destination:_) <- getArgs
    copyFile source destination

copyFile :: FilePath -> FilePath -> IO ()
copyFile source destination = do
    contents <- B.readFile source
    B.writeFile destination contents