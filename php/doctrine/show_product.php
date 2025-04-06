<?php

require_once __DIR__ . '/bootstrap.php';

$id = $argv[1];
/** @var Product|null $product */
$product = $entityManager->find('Product', $id);

if ($product == null) {
    echo "No product found.\n";
    exit(1);
}

echo sprintf("-%s\n", $product->getName());
