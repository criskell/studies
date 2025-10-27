% esse é sempre o primeiro atributo de módulo e é também um statement.
% deve receber um atom como argumento.
-module(hello).
-export([add/2, hello/0, greet_and_add_two/1]).
-import(io, [format/1]).

% a sintaxe de uma função segue a forma Name(args) -> Body.
% Body pode ser uma lista de expressões do Erlang separadas por vírgulas.
add(A,B) ->
  A + B.

%% exibe uma mensagem pro mundo
hello() ->
  io:format("Hello, world!~n"),
  format("msg").

greet_and_add_two(X) ->
  hello(),
  add(X,2).