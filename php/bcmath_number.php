<?php

use BcMath\Number;

$num1 = new Number('0.10');
$num2 = new Number('0.20');

echo $num1 + $num2 . PHP_EOL;
echo $num1->add($num2, scale: 27) . PHP_EOL;
