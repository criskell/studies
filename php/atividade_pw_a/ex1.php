<?php

$nome = "criskell";
$sexo = "Masculino";
$idade = 20;

if ($sexo == "Feminino" && $idade < 25) {
  echo "Nome: " . $nome . "<br />";
  echo "ACEITA<br />";
} else {
  echo "Nome: " . $nome . "<br />";
  echo "NÃO ACEITA<br />";
}
