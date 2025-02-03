{-# OPTIONS_GHC -fno-warn-partial-type-signatures #-}
{-# LANGUAGE TypeApplications, ExplicitForAll, PartialTypeSignatures #-}

infixr |>
(|>) :: forall b. _
(|>) = flip ((<$>) @((->) b))

main :: IO ()
main = do
  let resultadoEventual = (+100)
      modificadorDesseResultadoEventual = (subtract 100)
      
  putStrLn . show . resultadoEventual |> modificadorDesseResultadoEventual $ 1000
  putStrLn . show . modificadorDesseResultadoEventual <$> resultadoEventual $ 1000
  