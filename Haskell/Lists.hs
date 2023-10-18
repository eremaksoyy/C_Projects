
--QUESTION 1 

module Qfour(lastncompare, capitalizeFirstLast, verifier) where
import Data.Char

convert list = [toLower x | x <- list]

compareLists :: [Char] -> [Char] -> Int -> Bool
compareLists [] _ _ = True
compareLists _ [] _ = True
compareLists _ _ 0 = True   
compareLists list1 list2 num = if last(list1)==last(list2) then compareLists (init(list1)) (init(list2)) (num-1)
                               else if last(list1)/=last(list2) && num==0 then True
                               else False
                                                             
lastncompare list1 list2 num = compareLists (convert(list1)) (convert(list2)) num 



--QUESTION 2

splitList list = takeWhile(/= ' ') list
restList list = dropWhile (/= ' ') list


convertLetters [] = []
convertLetters (x:xs) = if length(x)==1 then [toUpper(head x)] ++ " " ++ convertLetters xs
                        else [toUpper(head x)] ++(convert(init(tail(x)))) ++ [toUpper(last(x))] ++ " " ++ convertLetters xs
capitalizeFirstLast list = convertLetters(words(list))



--QUESTION 3

intCounter [] = 0
intCounter (x:xs) = if isDigit x then (1 + intCounter xs)
                    else intCounter xs
                    
lowerCounter [] = 0
lowerCounter (x:xs) = if (elem x ['a'..'z']==True) then 1 + lowerCounter xs
                      else lowerCounter xs

upperCounter [] = 0
upperCounter (x:xs) = if (elem x ['A'..'Z'] == True) then 1 + upperCounter xs
                      else upperCounter xs


verifier :: [Char] -> Bool
verifier list = if length(list)<7 || length(list)>10 then False
                else if intCounter(list)>=1 && lowerCounter(list)>=2 && upperCounter(list)>=2 then True
                else False
                
