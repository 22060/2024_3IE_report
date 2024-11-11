data Natnum = Zero | S Natnum  deriving (Eq, Show)

pred_ :: Natnum -> Natnum
pred_ Zero = Zero
pred_ (S x) = x

minus_ :: Natnum -> Natnum -> Natnum
minus_ x Zero = x
minus_ x (S y) = pred_ (minus_ x y)

sign_ :: Natnum -> Natnum
sign_ Zero = Zero
sign_ (S x) = S Zero

nsign_ :: Natnum -> Natnum
nsign_ x = minus_ (S Zero) (sign_ x)
