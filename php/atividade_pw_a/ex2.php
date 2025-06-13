<?php

$livro = "Refactoring";
$tipo = "aluno";

if ($tipo == "professor") {
  $devolverEm = 10;
}

if ($tipo == "aluno") {
  $devolverEm = 3;
}

echo "Empréstimo - Recibo<br />";
echo "Livro: " . $livro . "<br />";
echo "Tipo de Usuário: " . $tipo . "<br />";
echo "Dias para Devolver: " . $devolverEm . "<br />";
