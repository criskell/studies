module Functor where

newtype MyIO a = MyIO (IO a)

myIOToIO :: MyIO a -> IO a
myIOToIO (MyIO io) = io 

instance Functor MyIO where
    fmap f action = do
        result <- action
        return (f result)

instance Applicative MyIO where
    pure x = MyIO (pure x)
    (MyIO f) <*> (MyIO x) = MyIO (f <*> x)

instance Monad MyIO where
    -- (MyIO io) >>= f = MyIO $ do
    --     value <- io
    --     let MyIO io' = f value
    --     io'

    -- (MyIO io) >>= f = MyIO $ io >>= (\value -> myIOToIO $ f value)

    -- (MyIO io) >>= f = do
    --     value <- io
    --     myIOToIO $ f value

    (MyIO io) >>= f = MyIO $ io >>= (myIOToIO . f)