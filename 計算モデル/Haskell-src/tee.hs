data Natnum = Zero | S Natnum  deriving (Eq, Show)

pred_ :: Natnum -> Natnum
pred_ Zero = Zero
pred_ (S x) = x

minus_ :: Natnum -> Natnum -> Natnum
minus_ x Zero = x
minus_ x (S y) = pred_ (minus_ x y)

genNatnum :: Natnum -> [Natnum]
genNatnum n = n : genNatnum (S n)

tee x = head (filter (\y -> (minus_ x y) == Zero) (genNatnum Zero))
