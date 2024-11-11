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

pred_ :: Natnum -> Natnum
pred_ Zero = Zero
pred_ (S x) = x

minus_ :: Natnum -> Natnum -> Natnum
minus_ x Zero = x
minus_ x (S y) = pred_ (minus_ x y)

sign_ :: Natnum -> Natnum
sign_ Zero = Zero
sign_ (S x) = S Zero

genNatnum :: Natnum -> [Natnum]
genNatnum n = n : genNatnum (S n)

equal_ :: Natnum -> Natnum -> Natnum
equal_ x y = sign_ (plus_ (minus_ x y) (minus_ y x))

div_ x1 x2 = head (filter (\y -> (equal_ x1 (multi_ x2 y)) == Zero) (genNatnum Zero))
root_ x = head (filter (\y -> (equal_ x (multi_ y y)) == Zero) (genNatnum Zero))
