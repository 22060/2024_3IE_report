add(X, 0, X).
add(X, s(Y), s(Z)) :- add(X, Y, Z).

multi(X, 0, 0).
multi(X, s(Y), Z) :- multi(X, Y, W), add(X, W, Z).
