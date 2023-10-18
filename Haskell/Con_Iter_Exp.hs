myfunc a b= (if a>b then (+) else (-)) a b

data Days=Mon|Tue|Wed|Thu|Fri|Sat|Sun deriving Show

dayteller a= case a of
             1->Mon
             2->Tue
             3->Wed
             4->Thu
             5->Fri
             6->Sat
             7->Sun
			 
l1=[1,2,3,4,5,6,7,8,9,10,11,12]
l2=[2*x|x<-l1]
l3=[x*x|x<-l1]
l4=[x*x*x|x<-l1,(mod x 2)==0]