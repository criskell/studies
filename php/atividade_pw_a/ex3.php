<?php

$alturaJuca = 110;
$alturaChico = 150;
$anos = 0;

while ($alturaJuca <= $alturaChico) {
  $alturaChico += 2;
  $alturaJuca += 3;
  $anos++;
}

echo "Anos: " . $anos .  "<br />";
