 sum([], 0).       %  空リストの総和は 0
 sum([H|Tail], N) :- sum(Tail, M), N is H + M.
                   % 「頭部」と「尾部の総和」を加算
 rev_lst([], []).  %  空リストの反転は空リスト
 rev_lst([H|Tail], Z) :- rev_lst(Tail, W), append(W, [H], Z).
                   %  「頭部」をリストの末尾へ
