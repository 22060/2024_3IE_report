data Natnum = Zero | S Natnum  deriving (Eq, Show)

u_1_1 :: Natnum -> Natnum
u_1_1 x1 = x1

u_3_3 :: Natnum -> Natnum -> Natnum -> Natnum
u_3_3 x1 x2 x3 = x3

plus_ :: Natnum -> Natnum -> Natnum
plus_ x Zero = u_1_1 x
plus_ x (S y) = S (u_3_3 x y (plus_ x y))

pred_ :: Natnum -> Natnum
pred_ Zero = Zero
pred_ (S x) = x

minus_ :: Natnum -> Natnum -> Natnum
minus_ x Zero = x
minus_ x (S y) = pred_ (minus_ x y)

genNatnum :: Natnum -> [Natnum]
genNatnum n = n : genNatnum (S n)

fee x1 x2 = head (filter (\y -> (minus_ (plus_ x1 y) x2) == Zero) (genNatnum Zero))