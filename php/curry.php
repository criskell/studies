<?php

function curry(callable $fn)
{
  $reflectionFunction = new ReflectionFunction($fn);
  $requiredParametersCount = $reflectionFunction->getNumberOfRequiredParameters();

  return (fn($recur) => $recur($recur, []))(fn($recur, $args) => function (...$newArgs) use ($requiredParametersCount, $fn, $recur, $args) {
    $args = [...$args, ...$newArgs];

    if (count($args) < $requiredParametersCount) {
      return $recur($recur, $args);
    }

    return $fn(...$args);
  });
}

$somaComTres = curry(fn($a, $b) => $a + $b)(3);

echo $somaComTres(10) . "\n";
