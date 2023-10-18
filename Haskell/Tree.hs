data Tree alpha= Empty | Node (alpha, Tree alpha, Tree alpha) deriving Show
t1= Node (1,Node(2,Empty,Empty),Node(3,Node(4,Empty,Empty),Empty))
t2= Node ('a',Node('b',Node('d',Empty,Empty),Node('e',Empty,Empty)),Node('c',Empty,Empty))