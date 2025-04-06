<?php

use Doctrine\DBAL\DriverManager;
use Doctrine\ORM\EntityManager;
use Doctrine\ORM\ORMSetup;

require_once __DIR__ . "/vendor/autoload.php";

// Cria uma configuração para atributos do Doctrine.
// Cria um objeto `Configuration` com valores padrões.
$config = ORMSetup::createAttributeMetadataConfiguration(
    paths: [__DIR__ . '/src'],
    isDevMode: true,
);

$connection = DriverManager::getConnection([
    'driver' => 'pdo_sqlite',
    'path' => __DIR__ . '/db.sqlite',
]);

// O EntityManager irá nos fornecer pontos de acesso para o gerenciamento
// completo do ciclo de vida das entidades além de mapear a estrutura relacional
// para objetos do PHP (data-mapper pattern).
$entityManager = new EntityManager($connection, $config);
