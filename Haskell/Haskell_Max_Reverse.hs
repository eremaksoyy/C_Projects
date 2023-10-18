maxi []=error "Maximum function cannot handle empty list"
maxi [a]=a
maxi (x:xs)= if (x > maxi xs) then x else maxi xs

reversi [a]=[a]
reversi (x:xs)= reversi xs ++ [x]