import Control.Monad.Reader

type Config = String

-- ReaderT representa uma função que precisa de um ambiente para produzir um resultado dentro de um monad.
-- runReaderT recebe o ambiente e executa essa função, retornando o resultado dentro do monad.

printConfig :: ReaderT Config IO ()
printConfig = do
  environment <- ask
  liftIO $ putStrLn ("Ambiente: " ++ environment)

main :: IO ()
main = runReaderT printConfig "Meu ambiente"