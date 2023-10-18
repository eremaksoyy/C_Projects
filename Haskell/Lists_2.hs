hellomyvalue a = a*a


check x = if x>10 then "it is greater than 10" else "it is less than 10"


sumoflist x = sum (init(tail x))


body x = init(tail x)


list1 = [1,2,3,4]
list2 = [9,8,7,6,5,4]
maxoftwo x y = max (maximum x) (maximum y)


maketuple x y = (maximum x, maximum y)


checkelement x list = if elem x list then list 
                      else list ++ [x]
                      

thirdelement (a, b ,x) = x
trd (_, _, x) = x


calculatedistance (x1, y1) (x2,y2) = sqrt (hellomyvalue (x2-x1) + hellomyvalue (y2-y1))



salary c hour overtime = if c==1 then 10*hour
                     else if c==2 || c==3 then 7*(hour+1.5*overtime)
                     else 5*(hour+2*overtime)