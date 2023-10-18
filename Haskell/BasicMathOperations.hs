
--QUESTION 1

calculate num1 [x] num2 = if x=='+'||x=='s' then (num1 + num2)
                          else if x=='-'||x=='r' then (num1 - num2)
                          else if x=='*'||x=='m' then (num1 * num2)
                          else if x=='/'||x=='d' then (num1/num2) 
                          else if x=='x' then tProduct (max num1 num2) (min num1 num2)
                          else if x=='.' then tSum (max num1 num2) (min num1 num2)
                          else 0


--HELPER FUNCTIONS FOR RECURSION (FOR BOTH QUESTIONS 1 AND 2)

makeList num1 num2 =  if num1==num2 then [(min num1 num2)]
                      else ([(max num1 num2)]++(makeList ((max num1 num2)-1) ((min num1 num2))))

tProduct num1 num2 = multiple(makeList num1 num2)

tSum num1 num2 = plus(makeList num1 num2)

plus [] = 0
plus (x:xs) = x + plus xs

minus [] = 0
minus (x:xs) = x - minus xs

multiple [] = 1
multiple (x:xs) = x * multiple xs

divide [] = 1
divide (x:xs) = x /(divide xs)


--QUESTION 2

evaluate x [op] = if op=='+'||op=='s' then plus x
                  else if op=='-'||op=='r' then minus x
                  else if op=='*'||op=='m' then multiple x
                  else if op=='/'||op=='d' then divide x
                  else if op=='x' then (tProduct2 x)
                  else if op=='.' then (tSum2 x)
                  else 0
                       
                       
tSum2 [] = 0
tSum2 (x:y:xs) = (tSum x y) + (tSum2 xs)    

tProduct2 [] = 1
tProduct2 (x:y:xs) = (tProduct x y)*(tProduct2 xs)

       
       
--QUESTION 3

