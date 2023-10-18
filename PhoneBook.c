#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct TreeNode {
	int value ;
	char *names ;
	struct TreeNode *left ;
	struct TreeNode *right ;
} Tree;

typedef struct Node {
	Tree *data ;
	struct Node *next ;
} Stack;

Tree *CreateTree() ;
Tree *InsertPerson(Tree *, char *, int) ;
void DisplayPhoneBook(Tree *) ;
void SearchDisplayPerson(Tree *, char *) ;
Stack *CreateStack() ;
void PushStack(Stack *, Tree *) ;
Tree *PopStack(Stack *) ;

int main()
{
	char name[50] ;
	Tree *myTree ;
	myTree = CreateTree() ;

	myTree = InsertPerson(myTree, "David", 345689) ;
	myTree = InsertPerson(myTree, "Ahmet", 109872) ;
	myTree = InsertPerson(myTree, "Maria", 569842) ;
	myTree = InsertPerson(myTree, "Ahmet", 423698) ;
	
	printf("\nPhone Book Content:\n") ;
	DisplayPhoneBook(myTree) ;
	
	printf("\nEnter a name: \n") ;
	gets(name) ;
	
	SearchDisplayPerson(myTree, name) ;

	return 0 ;
}

Tree *CreateTree()
{
	return NULL ;
}

Tree *InsertPerson(Tree *T, char *name, int No)
{
	if(T == NULL)	{
		Tree *insertNode ;
		insertNode = (Tree *)malloc(sizeof(Tree)) ;
		insertNode->names = name ;
		insertNode->value = No ;
		insertNode->left = insertNode->right = NULL ;
		return insertNode ;	}
	if(strcmp(name, T->names)<=0)
		T->left = InsertPerson(T->left, name, No) ;
	else 
		T->right = InsertPerson(T->right, name, No) ;
	return T ;
}

void DisplayPhoneBook(Tree *T)
{
	if(T != NULL)	{
		DisplayPhoneBook(T->left) ;
		printf("%s : %d\n ", T->names, T->value) ;
		DisplayPhoneBook(T->right) ;	}
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

void SearchDisplayPerson(Tree *T, char *name)
{
	int counter=0 ;
	Stack *myStack ;
	myStack = CreateStack() ;
	PushStack(myStack, T) ;
	
	while(myStack->next != NULL)	{
		Tree *removed ;
		removed = PopStack(myStack) ;
		if(strcmp(name, removed->names) == 0)	{
			if(strcmp(name, removed->left->names) == 0)	
				printf("\nTelephone numbers belonging to people with name %s :\n\t%s : %d\n\t%s : %d\n", name, name, removed->value, name, removed->left->value) ;
			else
				printf("\nTelephone numbers belonging to people with name %s :\n\t%d\n", name, removed->value) ;
			counter ++ ;	}
			
			
		else	{
			if(removed->left != NULL)	{
				PushStack(myStack, removed->left) ;	}
			if(removed->right != NULL)	{
				PushStack(myStack, removed->right) ;	}	}	}
	if(counter == 0)
		printf("\nTelephone numbers belonging to people with name %s :\n\tNot available!\n", name) ;			
}

void PushStack(Stack *S, Tree *T)
{
	Stack *newNode ;
	newNode = (Stack *)malloc(sizeof(Stack)) ;
	newNode->data = T ;
	newNode->next = S->next ;
	S->next = newNode ;	
}

Tree *PopStack(Stack *S)
{
	if(S!=NULL)	{
		Stack *deletedNode ;
		deletedNode = S->next ;
		Tree *holder ;
		holder = deletedNode->data ;
		S->next = S->next->next ;
		free(deletedNode) ;	
		return holder ;	}
}

