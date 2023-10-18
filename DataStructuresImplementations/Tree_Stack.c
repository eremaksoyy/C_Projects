#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	int value ;
	struct TreeNode *left ;
	struct TreeNode *right ;
} Tree;

typedef struct Node {
	int data ;
	struct Node *next ;
} Stack;

Stack *CreateStack() ;
void PushStack(Stack *, int) ;
int PopElement(Stack *) ;
Tree *CreateTree() ;
Tree *InsertElementRecursively(Tree *, int) ;
void PrintTree(Tree *) ;


int main()
{
	int i, num, element ;
	Tree *myTree ;
	myTree = CreateTree() ;
	
	printf("How many elements do you want to insert: ") ;
	scanf("%d", &num) ;
	for(i=0 ; i<num ; i++)	{
		printf("Enter an element: ") ;
		scanf("%d", &element) ;
		myTree = InsertElementRecursively(myTree, element) ;	}
	
	Stack *myStack ;
	myStack = CreateStack() ;

	
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

Stack *CreateStack()
{
	Stack *S ;
	S = (Stack *)malloc(sizeof(Stack)) ;
	if(S==NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	S->next = NULL ;
	return S ;
}

void PushStack(Stack *S, int value)
{
	Stack *newNode ;
	newNode = (Stack *)malloc(sizeof(Stack)) ;
	if(newNode == NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	newNode->data = value ;
	newNode->next = S->next ;
	S->next = newNode ;	
}

int PopElement(Stack *S)
{
	int num ;
	Stack *deleteNode ;
	deleteNode = S->next ;
	num = deleteNode->data ;
	S->next = S->next->next ;
	free(deleteNode) ;
	return num ;
}







