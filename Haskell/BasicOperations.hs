listFunction [] = "I am an empty list"
listFunction [x] = "I am a list with only one element: " ++[x]
listFunction (x:xs) = x: " is my first element and my other elements are: " ++ xs


example (x:y:ys) = x: " is the whole, " ++ [y] ++ " is the first, and " ++ ys ++ " is the rest!!"
example2 a@(x:y:ys) = a ++ " "++[y]++" " ++ys



myFunction [x] = "I am " ++ [x] ++ " years old"


reverselist [] = []
reverselist (x:xs) = reverselist(xs) ++ [x]



factorial 0 = 1
factorial n = factorial (n-1) * n


myLen [] = 0
myLen (x:xs) = myLen xs + 1



natural 0 = []
natural n = (natural (n-1)) ++ [n] 
-- natural n = [n] ++ (natural (n-1)) reverse order version


vowels = "aeiou"
vowelcount "" = 0
vowelcount (x:xs) = if (elem x vowels) then (vowelcount xs) + 1
                    else vowelcount xs
                    
                    
                    
calculateWeight [] [] = 0
calculateWeight (x:xs) (y:ys) = if x=='A' then 4*y + (calculateWeight xs ys)
                                else if x=='B' then 3*y + (calculateWeight xs ys)
                                else if x=='C' then 2*y + (calculateWeight xs ys)
                                else if x=='D' then 1*y + (calculateWeight xs ys)
                                else y + (calculateWeight xs ys)
calculateGPA xs ys = (calculateWeight xs ys)/sum(ys)            







   