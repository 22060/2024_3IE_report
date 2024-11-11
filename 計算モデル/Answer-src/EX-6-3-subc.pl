if(Cond, Then, Else) :- Cond, !, Then.
if(Cond, Then, Else) :- Else.

subc(X, Y, Z) :- if(X > Y, Z is X - Y, Z is 0).
