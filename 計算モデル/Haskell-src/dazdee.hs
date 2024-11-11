data Natnum = Zero | S Natnum  deriving (Eq, Show)

succ :: Natnum -> Natnum
succ x = S x

u_2_2 :: Natnum -> Natnum -> Natnum
u_2_2 x1 x2 = x2

add :: Natnum -> Natnum -> Natnum
add x Zero = x
add x (S y) = S (add x y)

multi :: Natnum -> Natnum -> Natnum
multi x Zero = Zero
multi x (S y) = add (multi x y) x

foo :: Natnum -> Natnum
foo x = (S . S) x

bar :: Natnum -> Natnum
bar x = multi x x

baz x y = add x y

daz x y = (foo . bar)(baz x y)

dee x y = (bar . foo)(u_2_2 x y)
