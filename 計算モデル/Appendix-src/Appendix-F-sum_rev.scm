 (define (sum_lst lst)
     (if (null? lst) 0   ; 空リストの総和は0
         (+ (car lst) (sum_lst (cdr lst)))))
            ;「先頭要素」と「残りのリストの総和」を足す
 (define (rev_lst lst)
     (if (null? lst) '() ; 空リストを反転しても空リスト
         (append (rev_lst (cdr lst)) (list (car lst)))))
                ; 先頭要素を末尾へ，残りの要素は反転して前方へ
