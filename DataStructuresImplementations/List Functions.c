#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct node {
	int value ;
	struct node *next ;
} Node;

typedef struct ListRecord {
	Node *head ;
	Node *tail ;
	int size ;
} List;

List *CreateList() ;
void MakeEmptyList(List *) ;
void InsertElement(List *) ;
void DeleteElement(List *, int)	;
int SearchPosition(List *, int) ;
void PrintList(List *) ;
int SizeList(List *) ;
int IsEmptyList(List *) ;

int main()
{
	int i=0, choice, remove, answer ;
	List *myList ;
	myList = CreateList() ;
	printf("How many element do you want to insert to you list?  ") ;
	scanf("%d", &choice) ;
	while(i!=choice)	{
		InsertElement(myList) ;
		i ++ ;	}
	
	do {
		int remove, element, position ;
		
		printf("\n\n-------------- MENU --------------\n") ;
		printf("(1) Insert an element to a list.\n(2) Delete an element from the list.\n(3) Print the content of the list.\n(4) Search for the position of an element.\n(5) Exit.") ;
		printf("\n\nPlease enter your choice: ") ;
		scanf("%d", &answer) ;
		
		switch(answer)	{
			case 1:
				InsertElement(myList) ;
				break ;
			case 2:
				printf("Which element do you want to delete from the list?\n") ;
				scanf("%d", &remove) ;
				DeleteElement(myList, remove)	;
				break ;
			case 3:
				PrintList(myList) ;
				break ;
			case 4:
				printf("Enter the element that you want to get the position of: ") ;
				scanf("%d", &element) ;
				position = SearchPosition(myList, element) ;
				printf("%d is in %d th position in the list.\n", element, position) ;
				break ;
			default:
				printf("Invalid value entered!\n") ;
				exit(1) ;	}
	} while(answer!=5) ;
		
	return 0 ;
}

List *CreateList()
{
	List *L ;
	L = (List *)malloc(sizeof(List)) ;
	if(L == NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	MakeEmptyList(L) ;
}

void MakeEmptyList(List *L)
{
	L->head = (Node *)malloc(sizeof(Node)) ;
	if(L == NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	L->size = 0 ;
	L->head->next = NULL ;
	L->tail = L->head ;
}

void InsertElement(List *L)
{
	int value ;
	printf("Enter a value to insert  to your list: ") ;
	scanf("%d", &value) ;
	Node *InsertNode ;
	InsertNode = (Node *)malloc(sizeof(Node)) ;
	if(InsertNode == NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	InsertNode->value = value ;
	InsertNode->next = NULL ;
	
	if(L->head->next == NULL)	{
		L->head->next = InsertNode ;
		L->tail = InsertNode ;	}
	else 	{
		L->tail->next = InsertNode;
		L->tail = InsertNode ;	}
	L->size ++ ;
}

void DeleteElement(List *L, int remove)	
{
	Node *temp, *removeNode ;
	temp = L->head ;
	while(temp->next!=NULL && temp->next->value != remove)	{
		temp = temp->next ;	}
	if(temp->next!=NULL)	{
		removeNode = temp->next ;
		temp->next = removeNode->next ;
		free(removeNode) ;
		L->size -- ;	}
	else 	{
		printf("There is no such an element in the list!\n") ;	}	
}

int SearchPosition(List *L, int element)
{
	int counter=0 ;
	Node *temp ;
	temp = L->head->next ;
	while(temp->next!=NULL && temp->value!=element)	{
		counter ++ ;
		temp = temp->next ;	}
	if(counter==0)	{
		printf("You dont't have %d  in the list!\n", element) ;
		exit(1) ;	}	
	return counter+1 ;
}

void PrintList(List *L)
{
	Node *holder ;
	holder = L->head->next ;
	printf("\n\n%d\n\n", L->tail->value) ;
	while(holder != NULL)	{
		printf("%d -> ", holder->value) ;
		holder = holder->next ;	}
	printf("\n\n") ;
}

int SizeList(List *L)
{
	return L->size ;
}

int IsEmptyList(List *L)
{
	if(L->size == 0)
		return TRUE ;
	else 
		return FALSE ;
}
