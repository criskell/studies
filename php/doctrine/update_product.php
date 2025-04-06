<?php

require_once __DIR__ . '/bootstrap.php';

$id = $argv[1];
$newName = $argv[2];

/** @var Product|null $product */
$product = $entityManager->find('Product', $id);

if ($product == null) {
    echo "Produto com ID $id não existe.\n";
    exit(1);
}

$product->setName($newName);

$entityManager->flush();
