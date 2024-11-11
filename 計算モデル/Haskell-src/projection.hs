data Natnum = Zero | S Natnum  deriving (Eq, Show)

u_1_1 :: Natnum -> Natnum
u_1_1 x1 = x1

u_2_1 :: Natnum -> Natnum -> Natnum
u_2_1 x1 x2 = x1

u_2_2 :: Natnum -> Natnum -> Natnum
u_2_2 x1 x2 = x2
