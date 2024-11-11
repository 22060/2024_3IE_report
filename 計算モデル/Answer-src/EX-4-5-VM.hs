-- ファイルの読込  :load ./EX-4-5.hs
-- 実行例         vm_1 100 'Y'
--               vm_2 [100, 50] 'R'
vm_1 100 'Y' = print "JuiceA"
vm_1 150 'R' = print "JuiceB"
vm_1 200 'G' = print "JuiceC"

vm_2 lst y = vm_1 (amount lst) y

amount [] = 0
amount (x:ls) = (amount ls) + x


