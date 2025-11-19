-module(guards).

% a vírgula se comporta de uma maneira parecida com `andalso` que é basicamente um AND com curto-circuito.
old_enough(X) when X >= 16, X =< 104 ->
	true;
old_enough(X) ->
	false.

% o ponto-e-vírgula se comporta de uma forma parecida com `orelse` que é basicamente um OR com curto-circuito.
wrong_age(X) when X < 16; X > 104 ->
	true;
wrong_age(X) ->
	false.
