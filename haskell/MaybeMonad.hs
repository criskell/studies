data Maybe' a = Just' a | Nothing'

instance Functor Maybe' where
  f `fmap` Nothing' = Nothing'
  f `fmap` Just' x = Just' $ f x

instance Applicative Maybe' where
  pure = Just'

  Nothing' <*> _ = Nothing'
  Just' f <*> x = fmap f x

instance Monad Maybe' where
  return = pure

  Nothing' >>= f = Nothing'
  (Just' x) >>= f = f x