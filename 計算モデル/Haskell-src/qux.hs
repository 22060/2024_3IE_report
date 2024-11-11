data Natnum = Zero | S Natnum  deriving (Eq, Show)

u_1_1 :: Natnum -> Natnum
u_1_1 x1 = x1

u_3_2 :: Natnum -> Natnum -> Natnum -> Natnum
u_3_2 x1 x2 x3 = x2

qux :: Natnum -> Natnum -> Natnum
qux x Zero = u_1_1 x
qux x (S y) = u_3_2 x y (qux x y)
