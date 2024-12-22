import Network.Socket
import System.IO

main :: IO ()
main = do
  -- Domain specifies a communication domain, the type of addresses the socket can communicate with.
  -- Stream specifies the communication semantics.
  sock <- socket AF_INET Stream 0
  bind sock (SockAddrInet 4001 0)
  listen sock 2

  loopForever sock

loopForever :: Socket -> IO ()
loopForever sock = do
  (conn, _) <- accept sock
  sockHandle <- socketToHandle conn ReadWriteMode

  line <- hGetLine sockHandle
  putStrLn $ "Request received: " ++ line

  hPutStrLn sockHandle "Hey, client!"
  hClose sockHandle

  loopForever sock