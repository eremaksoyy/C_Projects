data List1= Elem(Int,List1)|Empty deriving Show
l1= Elem(1,Elem(2,Elem(3,Elem(4,Elem(5,Empty)))))

data Polylist alpha= Node(alpha,Polylist alpha) | Emptyp deriving Show
l2=Node('a',Node('b',Node('c',Node('d',Emptyp))))
l3=Node("Alice",Node("Bob",Node("John",Node("Anne",Node("John",Emptyp)))))
l4=Node(1,Node(2,Node(3,Emptyp)))

l5=(1:(2:(3:(4:[]))))