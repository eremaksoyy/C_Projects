#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int  data ;
	struct Node *next ;
} Stack;

Stack *CreateStack() ;
void PushStack(Stack *, int) ;
int PopElement(Stack *) ;
int TopOfStack(Stack *) ;
void DisplayStack(Stack *) ;

int main()
{
	int i, num, element, removed, top ;
	Stack *myStack ;
	myStack = CreateStack() ;
	printf("How many elements you want to insert to the stack? ") ;
	scanf("%d", &num) ;
	fflush(stdin) ;
	for(i=0 ; i<num ; i++)	{
		printf("Enter an element to insert to the stack: ")	;	
		scanf("%d", &element) ;	
		PushStack(myStack, element) ;
	//	printf("\n%d \n", myStack->next->data) ;
		}
	top = TopOfStack(myStack) ;
	printf("The top of the stack is %d !\n", top) ;
	removed = PopElement(myStack) ;
	printf("Removed data is %d\n", removed) ;
	top = TopOfStack(myStack) ;
	printf("After deletion, the new top value is %d !\n", top) ;
	DisplayStack(myStack) ;
	
	return 0 ;
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

int TopOfStack(Stack *S) 
{
	if(S != NULL)
		return S->next->data ;
}

void DisplayStack(Stack *S)
{
	Stack *temp ;
	temp = S->next ;
	while(temp != NULL)	{
		printf("%d -> ", temp->data) ;
		temp = temp->next ;	}
}

