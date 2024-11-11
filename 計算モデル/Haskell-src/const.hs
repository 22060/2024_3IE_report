data Natnum = Zero | S Natnum  deriving (Eq, Show)

c_1_1 :: Natnum -> Natnum
c_1_1 x1 = S Zero

c_2_1 :: Natnum -> Natnum -> Natnum
c_2_1 x1 x2 = S Zero
