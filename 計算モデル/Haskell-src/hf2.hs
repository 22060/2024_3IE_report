plus x y = x + y

multi x y = x * y

hf2 :: (Int -> Int -> Int) -> Int -> Int
hf2 f 1 = 1
hf2 f x = f x (hf2 f (x - 1))
