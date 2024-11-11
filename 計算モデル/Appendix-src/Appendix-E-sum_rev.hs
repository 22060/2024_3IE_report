sum_lst [] = 0    -- 空リストの総和は0
sum_lst (h:tail) = h + sum_lst tail
                  --「先頭要素」＋「残りのリストの総和」
rev_lst [] = []   -- 空リストを反転しても空リスト
rev_lst (h:tail) = (rev_lst tail) ++ [h]  --先頭要素hを末尾へ

