data Natnum = Zero | S Natnum  deriving (Eq, Show)

succ :: Natnum -> Natnum
succ x = S x

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

bee :: Natnum -> Natnum
bee x = (bar . foo) x

fee :: Natnum -> Natnum
fee x = (foo . bar . bar) x
