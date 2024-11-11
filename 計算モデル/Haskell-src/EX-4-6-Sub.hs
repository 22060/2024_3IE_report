succ' x = x + 1

pred' x | x==0 = 0
        | otherwise = x - 1

sub' x 0 = x
sub' x y = pred' (sub' x (pred' y))
