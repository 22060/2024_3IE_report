価格(a, 100).
価格(b, 150).
価格(c, 200).
ボタン(黄, a).
ボタン(赤, b).
ボタン(緑, c).
購入(X, Y, Z) :- ボタン(Y, Z), 価格(Z, X).
total([], 0).
total([C|Cs], S) :- total(Cs, S1), S is C + S1.
購入2(M, B, G) :- total(M, Ms), 購入(Ms, B, G).
