type Person=(String,Int)
p1::Person
p1=("Dennis Ritchie",80)

data Numb=Real Float | Inty Int deriving Show
n1=Real 3.14
n2=Inty 5

evencheck a= if (mod a 2 == 0) then 1 else 0

myfunct a b = fromIntegral(mod a b) * 0.1