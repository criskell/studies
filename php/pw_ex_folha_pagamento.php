<?php

function obter_aliquota($salario)
{
  if ($salario < 2468.80) {
    return 0;
  }

  if ($salario < 2826.65) {
    return 7.5;
  }

  if ($salario < 3751.05) {
    return 15;
  }

  if ($salario < 4664.68) {
    return 22.5;
  }

  return 27.5;
}

function calcular_desconto($salarioBruto, $aliquota)
{
  return $salarioBruto * ($aliquota / 100);
}

function calcular_salario_liquido($salarioBruto, $desconto)
{
  return $salarioBruto - $desconto;
}

function formatar_valor($valor)
{
  return sprintf("%.2f", $valor);
}

function principal()
{
  echo "Folha de Pagamento\n";
  echo "---------------------------------\n";
  echo "Bem-vindo ao programa de cálculo de desconto de IR 2025\n";
  echo "---------------------------------\n";

  $salarioBruto = 5200;
  $aliquota = obter_aliquota($salarioBruto);
  $desconto = calcular_desconto($salarioBruto, $aliquota);
  $salarioLiquido = calcular_salario_liquido($salarioBruto, $desconto);

  echo "Salário bruto: " . formatar_valor($salarioBruto) . "\n";
  echo "Porcentagem de desconto: " . $aliquota . "%\n";
  echo "Valor do desconto: " . formatar_valor($desconto) . "\n";
  echo "Salário líquido: " . formatar_valor($salarioLiquido) . "\n";
  echo "---------------------------------\n";
}

principal();
