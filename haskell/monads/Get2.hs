import Data.Binary.Strict.Get
import qualified Data.ByteString as BS
import Data.Word (Word8)

main :: IO ()
main = do
  let bs = BS.pack [0x01, 0x02, 0x03]
  let parser = do
      a <- getWord8
      b <- getWord8
      return (a + b)
  let (result, rest) = runGet parser bs
  print result
  print rest