#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	int value ;
	struct TreeNode *left ;
	struct TreeNode *right ;
} Tree;

Tree *CreateTree() ;
void InsertElementIteratively(Tree *, int) ;
Tree *InsertElementRecursively(Tree *, int) ;
void PrintTree(Tree *) ;
int countNodes(Tree *) ;
int Left(Tree *) ;
int Right(Tree *) ;
int TreeHeight(int, int) ;

int main()
{
	int i, num, element, nodes, height, left, right ;
	
	Tree *myTree ;
	myTree = CreateTree() ;
	
	printf("How many elements do you want to insert: ") ;
	scanf("%d", &num) ;
	for(i=0 ; i<num ; i++)	{
		printf("Enter an element: ") ;
		scanf("%d", &element) ;
		myTree = InsertElementRecursively(myTree, element) ;	}
		
//	printf("\n%d\n", myTree->value) ;
	PrintTree(myTree) ;
	nodes = countNodes(myTree)-1 ;
	printf("The number of nodes is: %d\n", nodes) ;
	
/*	left = Left(myTree) ;
	right = Right(myTree) ;
	
	height = TreeHeight(left, right) ;
	printf("the height is %d\n\n", height) ;	*/
	return 0 ;
}

Tree *CreateTree()
{
	Tree *T ;
	T = (Tree *)malloc(sizeof(Tree)) ;
	if(T == NULL){
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	T->left = T->right = NULL ;
	return T ;
}

Tree *InsertElementRecursively(Tree *T, int value)
{
	if(T == NULL)	{
		Tree *insertNode ;
		insertNode = (Tree *)malloc(sizeof(Tree)) ;
		insertNode->value = value ;
		insertNode->left = insertNode->right = NULL ;
		return insertNode ;	}
	if(value < T->value)
		T->left = InsertElementRecursively(T->left, value) ;
	else if(value > T->value)
		T->right = InsertElementRecursively(T->right, value) ;
	return T ;
}

void PrintTree(Tree *T)
{
	if(T != NULL)	{
		printf("%d -> ", T->value) ;
		PrintTree(T->left) ;
		PrintTree(T->right) ;	}
}

int countNodes(Tree *T)
{
	if(T == NULL)
		return 0 ;
	else
		return (countNodes(T->left)+countNodes(T->right)+1) ;
}


/*
int Left(Tree *T)
{
	if(T!=NULL)	
		return Left(T->left) ;
}

int Right(Tree *T)
{
	if(T!=NULL)		
		return Right(T->right) ;
}

int TreeHeight(int x, int y)
{
	if(x>=y)
		return x ;
	else 
		return y ;
}

*/

/*void InsertElementIteratively(Tree *T, int value)
{
	Tree *holder, *temp ;
	holder = (Tree *)malloc(sizeof(Tree)) ;
	if(holder == NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	holder->value = value ;
	holder->left = holder->right = NULL ;
	if(T == NULL)	{
		if(holder->value < T->value)
			T->left = holder ;
		else
			temp->right = holder ;	}
	else 	{
		temp = T ;
		if(holder->value < temp->value)	{
			if(temp->left == NULL)	
				temp->left = holder ;
		else {
			while(temp->left!=NULL && holder->value<temp->left->value)	{
				temp = temp->left ;	}
			if(temp->left == NULL)
				temp->left = holder ;
			else 	{
				if(temp->right == NULL)
					temp->right = holder ;
				else {
					while(temp->right!=NULL && holder->value>temp->right->value)	{
						temp = temp->right ;	}
					if(temp->right == NULL)
						temp->right = holder ;
					else
						temp->left = holder ;	}	}	}	}
		else 	{
			if(temp->right == NULL)
				temp->right = holder ;
			else	{
				while(temp->right!=NULL && holder->value>temp->right->value)	{
					temp = temp->right ;	}
				if(temp->right == NULL)
					temp->right = holder ;
				else	{
					if(temp->left == NULL)
						temp->left = holder ;
					else	{
						while(temp->left!=NULL && holder->value<temp->left->value)	{
							temp = temp->left ;	}
						if(temp->left == NULL)
							temp->left = holder ;
						else 
							temp->right = holder ;	}	}	}	}	}
						
	printf("%d -> ", temp->value) ;
}	*/


