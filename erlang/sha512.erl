-module(sha512).

-define(ROTR64(X, N), (X bsr N) bor (X bsl (64 - N))).
-define(CH(X, Y, Z), (X band Y) ^ ((bnot X) band Z))