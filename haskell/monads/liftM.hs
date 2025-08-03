import Control.Monad (liftM)

-- liftM eleva uma função pura para operar valores dentro de um contexto monádico.

square :: Int -> Int
square x = x * x

ex1 = liftM square (Just 3)
ex2 = liftM square (Just 4)

getLineLength :: IO Int
getLineLength = liftM length getLine

-- liftM e fmap fazem a mesma coisa. A diferença entre liftM e fmap é só semântica, onde
-- liftM é da typeclass Monad e fmap é da typeclass Functor.
-- liftM é mais específico para monads.