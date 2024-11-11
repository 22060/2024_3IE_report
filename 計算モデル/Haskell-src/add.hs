succ' x = x + 1

pred' x | x==0 = 0
        | otherwise = x - 1

add x 0 = x
add x y = succ' (add x (pred' y))
