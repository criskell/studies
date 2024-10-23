{-# LANGUAGE TypeApplications #-}

module Functor where

newtype MyIO a = MyIO { getIO :: IO a }

s x y = x + y 

instance Functor MyIO where
    fmap f action = do
        result <- action
        return (f result)

instance Applicative MyIO where
    pure x = MyIO (pure x)
    (MyIO f) <*> (MyIO x) = MyIO (f <*> x)

instance Monad MyIO where
    -- (MyIO io) >>= f = MyIO $ io >>= (\value -> myIOToIO $ f value)

    -- (MyIO io) >>= f = MyIO $ io >>= (myIOToIO . f)

    -- myIO >>= f = MyIO $ (getIO myIO) >>= (myIOToIO . f)

    -- (>>=) myIO f = MyIO ((>>=) (getIO myIO) (myIOToIO . f))

    -- (>>=) = (MyIO .) . ((>>=) @IO) . getIO

    -- (>>=) = (MyIO .) . (getIO .) . (>>=) . getIO

    -- (>>=) = (MyIO .) . (getIO .) . (>>=) . getIO

    -- (>>=) = (MyIO .) . (flip $ ((=<<)) . (getIO .)) . getIO

    -- (MyIO io) >>= f = MyIO $ io >>= getIO . f