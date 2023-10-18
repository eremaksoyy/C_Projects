#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct node {
	int element ;
	struct node *next ;
} Node;

typedef struct QueueRecord {
	Node *front ;
	Node *rear ;
	int size ;
} Queue;

Queue *CreateQueue() ;
void MakeEmptyQueue(Queue *) ;
void Enqueue(Queue *, int) ;
int Dequeue(Queue *) ;
void SearchElement(Queue *, int) ;
void DisplayQueue(Queue *) ;
int QueueSize(Queue *) ;
int IsEmptyQueue(Queue *) ;

int main()
{
	int i, num, element, choice ;
	
	Queue *myQueue ;
	myQueue = CreateQueue() ;
	printf("How many elements do you want to insert to your queue?  ") ;
	scanf("%d", &num) ;
	
	for(i=0 ; i<num ; i++)	{
		printf("Enter an element: ") ;
		scanf("%d", &element) ;
		Enqueue(myQueue, element) ;	}
	
	do {
		int search, deleted ;
		printf("\n\n-------------- MENU --------------\n") ;
		printf("(1) Insert an element to the queue.\n(2) Delete an element from the queue.\n(3) Print the content of the queue.\n(4) Search for an element in the queue.\n(5) Exit.") ;
		printf("\n\nPlease enter your choice: ") ;
		scanf("%d", &choice) ;
		
		switch(choice)	{
			case 1:
				printf("Enter the element you want to insert: ") ;
				scanf("%d", &element) ;
				Enqueue(myQueue, element) ;
				break ;
			case 2:
				deleted = Dequeue(myQueue) ;
				printf("Element %d is deleted successfully!\n", deleted) ;
				break ;
			case 3:
				DisplayQueue(myQueue) ;
				break ;
			case 4:
				printf("Enter an element to search: ") ;
				scanf("%d", &search) ;
				SearchElement(myQueue, search) ;
				break ;
			default:
				printf("Invalid value entered!\n") ;
				exit(1) ;	}	
	}	while(choice!=5) ;

//	printf("%d->%d->%d", myQueue->front->next->element, myQueue->front->next->next->element, myQueue->rear->element) ;
	return 0 ;
}

Queue *CreateQueue()
{
	Queue *Q ;
	Q = (Queue *)malloc(sizeof(Queue)) ;
	if(Q == NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	MakeEmptyQueue(Q) ;
}

void MakeEmptyQueue(Queue *Q)
{
	Q->front = (Node *)malloc(sizeof(Node)) ;
	if(Q->front == NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	Q->size = 0 ;
	Q->front->next = NULL ;
	Q->rear = Q->front ;
}

void Enqueue(Queue *Q, int value)
{
	Node *insertNode;
	insertNode = (Node *)malloc(sizeof(Node)) ;
	if(insertNode == NULL)	{
		printf("Memory allocation is not successful!\n") ;
		exit(1) ;	}
	insertNode->element = value ;
	insertNode->next = NULL ;
	
	if(Q->front->next == NULL)	{
		Q->front->next = insertNode ;
		Q->rear = insertNode ;	}
	else {
		Q->rear->next = insertNode ;
		Q->rear = insertNode ;	}
	Q->size ++ ;
}

int Dequeue(Queue *Q)
{
	int holder ;
	Node *removeNode ;
	removeNode = Q->front->next ;
	holder = removeNode->element ;
	Q->front->next = removeNode->next ;
	free(removeNode) ;
	Q->size -- ;
	return holder ;
}

void SearchElement(Queue *Q, int value)
{
	Node *temp ;
	temp = Q->front->next ;
	while(temp->next!=NULL && temp->element!=value)	{
		temp = temp->next ;	}
	if(temp->next == NULL)
		printf("There is no such an element in the queue!\n") ;
	else 
		printf("Element %d is found in the list!\n", value) ;
}

void DisplayQueue(Queue *Q)
{
	Node *temp ;
	temp = Q->front->next ;
	while(temp!=NULL)	{
		printf("%d -> ", temp->element) ;
		temp = temp->next ;	}
}

int QueueSize(Queue *Q)
{
	return Q->size ;
}

int IsEmptyQueue(Queue *Q)
{
	if(Q->size == 0)
		return TRUE ;
	else 
		return FALSE ;
}
