sum(N, S) :- sum_tail(N, 0, S).

sum_tail(0, S, S).
sum_tail(N, T, S) :- 
  N > 0, 
  T1 is T + N, 
  N1 is N - 1, 
  sum_tail(N1, T1, S).
