{-# LANGUAGE DeriveFunctor #-}

-- Functor que descreve um nível da árvore com filhos genéricos `a`.
-- A instância desse functor aplica uma função para cada filho`recursivo, isso por causa do `deriving Functor`.
-- Evita misturar a definição do nó com filhos recursivos.
data ExprF a
  = Lit Int
  | Var String
  | Add a a
  | Sub a a
  | Mul a a
  | Div a a
  | Call a [a]
  | Dot a String
  deriving Functor

-- Generaliza a forma estrutural de tipos recursivos.
-- Pega a definição `f` de um nível da árvore e gera uma árvore recursiva completa.
-- Cada filho é outro `Fix f`.
newtype Fix f = Fix (f (Fix f))

data Algebra r = Algebra
  { algLit :: Int -> r
  , algVar :: String -> r
  , algAdd :: r -> r -> r
  , algSub :: r -> r -> r
  , algMul :: r -> r -> r
  , algDiv :: r -> r -> r
  , algCall :: r -> [r] -> r
  , algDot :: r -> String -> r
  }

-- Smart constructors da AST.
type Expr = Fix ExprF

lit :: Int -> Expr
lit n = Fix (Lit n)

var :: String -> Expr
var s = Fix (Var s)

add, sub, mul, div :: Expr -> Expr -> Expr
add x y = Fix (Add x y)
sub x y = Fix (Sub x y)
mul x y = Fix (Mul x y)
div x y = Fix (Div x y)

call :: Expr -> [Expr] -> Expr
call f args = Fix (Call f args)

-- Aplica a algebra a um ExprF -> r.
applyAlg :: Algebra r -> ExprF r -> r
applyAlg alg (Lit n) = algLit alg n
applyAlg alg (Var s) = algVar alg s
applyAlg alg (Add x y) = algAdd alg x y
applyAlg alg (Sub x y) = algSub alg x y
applyAlg alg (Mul x y) = algMul alg x y
applyAlg alg (Div x y) = algDiv alg x y
applyAlg alg (Call f as) = algCall alg f as
applyArg alg (Dot e s) = algDot alg e s

-- Generaliza a recursão, evita que cada operação do visitor escreva a recursão explicitamente. Por meio dela,
-- conseguimos aplicar a algebra recursivamente.
-- Recebe uma álgebra que sabe como reduzir um nível da árvore para um valor final `a`.
-- `Fix f` é a árvore recursiva completa.
cata :: Functor f => (f a -> a) -> Fix f -> a
-- `t :: f (Fix f)`
-- `fmap (cata alg)` aplica `cata alg` em cada filho, transformando `f (Fix f)` em `f a`.
cata alg (Fix t) = alg (fmap (cata alg) t)
-- aplica `alg` a `t` depois de aplicar `cata alg` a cada filho de `t`.

-- Aqui é a álgebra, um registro onde cada campo converte um `ExprF a` (onde cada filho já virou um `a :: String`) em um `a`. 
rpnAlgebra :: Algebra String
rpnAlgebra = Algebra
  { algLit = \n -> show n
  , algVar = id
  , algAdd = \a b -> a ++ " " ++ b ++ " +"
  , algSub = \a b -> a ++ " " ++ b ++ " -"
  , algMul = \a b -> a ++ " " ++ b ++ " *"
  , algDiv = \a b -> a ++ " " ++ b ++ " /"
  , algCall = \f args ->
        let argsStr = unwords args
        in if null args then f ++ " call"
           else argsStr ++ " " ++ f ++ " call"
  , algDot = \e name -> e ++ " ." ++ name
  }

example :: Expr
example = mul (add (lit 1) (lit 2))
              (sub (lit 2) (lit 3))

main :: IO ()
main = putStrLn $ cata (applyAlg rpnAlgebra) example