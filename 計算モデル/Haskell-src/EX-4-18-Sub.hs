succ' x = x + 1

pred' x | x==0 = 0
        | otherwise = x - 1

sub'_tail x 0 = x
sub'_tail x y = sub'_tail (pred' x) (pred' y)
