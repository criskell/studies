import Data.Binary.Get
import qualified Data.ByteString.Lazy as BL

getInt32 :: Get Int
getInt32 = do
  value <- getInt32be
  return (fromIntegral value)

main :: IO ()
main = do
    let binaryData = BL.pack [0x00, 0x00, 0x01, 0x0F]
    let value = runGet getInt32 binaryData

    -- 0x01 * 2**8 + 0x0F = 271
    print value
