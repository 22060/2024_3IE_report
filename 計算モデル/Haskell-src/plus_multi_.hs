data Natnum = Zero | S Natnum  deriving (Eq, Show)

u_1_1 :: Natnum -> Natnum
u_1_1 x1 = x1

u_3_3 :: Natnum -> Natnum -> Natnum -> Natnum
u_3_3 x1 x2 x3 = x3

u_3_1 :: Natnum -> Natnum -> Natnum -> Natnum
u_3_1 x1 x2 x3 = x1

plus_ :: Natnum -> Natnum -> Natnum
plus_ x Zero = u_1_1 x
plus_ x (S y) = S (u_3_3 x y (plus_ x y))

multi_ :: Natnum -> Natnum -> Natnum
multi_ x Zero = Zero
multi_ x (S y) = plus_ (u_3_3 x y (multi_ x y)) (u_3_1 x y (multi_ x y))
