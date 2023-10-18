#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data ;
	struct node *prev ;
	struct node *next ;
} Node;

typedef struct DoubleRecord {
	Node *head ;
	Node *tail ;
	int size ;
} DoubleList;

Node *CreateDoubleList() ;
void MakeEmptyDoubleList(DoubleList *) ;
void InsertElement(DoubleList *, int, int) ;
void DisplayDL(DoubleList *) ;

int main()
{
	int i, num, element ;
	
	DoubleList *myDoubleList ;
	myDoubleList = CreateDoubleList() ;
/*	printf("How many elements do you want to insert to a double list? ") ;
	scanf("%d", &num) ;	*/

	/*	printf("Enter an element to insert: ") ;
		scanf("%d", &element);*/
		InsertElement(myDoubleList, 5, 1) ;
		InsertElement(myDoubleList, 2, 1) ;
		InsertElement(myDoubleList, 10, 3) ;
		InsertElement(myDoubleList, 7, 4) ;
		
	//	printf("\n%d\n", myDoubleList->head->next->data) ;
		//	}
	DisplayDL(myDoubleList) ;
	return 0 ;
}

Node *CreateDoubleList()
{
	DoubleList *DL ;
	DL = (DoubleList *)malloc(sizeof(DoubleList)) ;
	if(DL == NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	MakeEmptyDoubleList(DL) ;
}

void MakeEmptyDoubleList(DoubleList *DL)
{
	DL->head = (Node *)malloc(sizeof(Node)) ;
	if(DL->head == NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	DL->head->prev = DL->head->next = NULL ;
	DL->tail = DL->head ;
	DL->size = 0 ;
}

void InsertElement(DoubleList *DL, int val, int position)
{
	Node *newNode ;
	newNode = (Node *)malloc(sizeof(Node)) ;
	if(newNode == NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	newNode->data = val ;
	newNode->prev = NULL ;
	newNode->next = NULL ;
	if(DL->head->next == NULL)	{
		newNode->prev = DL->head ;
		newNode->prev->next = newNode ;	}
	else	{
		if(position > DL->size+1)
			position = DL->size+1 ;
		if(position == DL->size+1)	{
			DL->tail->next = newNode ;
			newNode->prev = DL->tail ;
			DL->tail = newNode ;	}
		else	{
			int counter=0 ;
			Node *tmp ;
			tmp = DL->head ;
			while(counter != position-1)	{
				tmp = tmp->next ;
				counter ++ ;	}
			newNode->prev = tmp ;
			newNode->next = tmp->next ;
			newNode->prev->next = newNode ;
			newNode->next->prev = newNode ;	}	}
}

void DisplayDL(DoubleList *DL)
{
	Node *p ;
	p = DL->head->next ;
	while(p != NULL)	{
		printf("%d -> ", p->data) ;
		p = p->next ;	}
}

