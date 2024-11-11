q(1, 0).
q(X, Z) :- q(X, Y), q(Y, Z).
q(X, Y) :- q(Y, X).

