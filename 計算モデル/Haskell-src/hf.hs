hf :: (Int -> Int) -> Int -> Int -> Int
hf f x 0 = x
hf f x y = f (hf f x (pred y))
