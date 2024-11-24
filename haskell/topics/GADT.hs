{-# LANGUAGE GADTs #-}

module GADT where

-- The data constructor function type `IsZero` returns `InvalidExpr a` and not `InvalidExpr Bool`.
data InvalidExpr a = InvalidIVal Int | InvalidBVal Bool | InvalidAdd (InvalidExpr Int) (InvalidExpr Int) | InvalidIsZero (InvalidExpr Int)

-- So we can do things like:
invalidResult = InvalidAdd (InvalidAdd (InvalidIVal 5) (InvalidIVal 6)) (InvalidBVal True)
-- `(5 + 6) + True`? This is invalid, but accepted by the compiler.

-- Generalized Algebraic Aata Types (GADTs) allows us to explicitly specify the type of the data constructors.
-- Here we have correctly specified the type of the `IsZero` constructor.
data Expr a where
    IVal :: Int -> Expr Int
    BVal :: Bool -> Expr Bool
    Add :: Expr Int -> Expr Int -> Expr Int
    IsZero :: Expr Int -> Expr Bool

-- This is rejected by the compiler.
-- Error: 'Couldn't match type ‘Bool’ with ‘Int’'
-- rejectedByCompiler = Add (Add (IVal 5) (IVal 6)) (BVal True)