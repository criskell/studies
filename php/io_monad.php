<?php

class IO
{
    public function __construct(private $effect) {}

    public function bind(callable $fn)
    {
        $self = $this;

        return new IO(function () use ($fn, $self) {
            return ($fn(($self->effect)())->effect)();
        });
    }

    public static function run(IO $io)
    {
        return ($io->effect)();
    }
}

function println__(string $message)
{
    return new IO(function () use ($message) {
        echo $message . "\n";
    });
}

function getLine__()
{
    return new IO(function () {
        return trim(fgets(STDIN));
    });
}

$program = println__("Digite seu nome: ")
    ->bind(fn() => getLine__())
    ->bind(fn($name) => println__("Seu nome é: " . $name))
    ->bind(fn() => println__("Teste."));

IO::run($program);
