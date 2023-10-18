#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	int height;
} AVLTree;

typedef struct node {
	AVLTree *data;
	struct node *next;
} Node;

typedef struct QueueRecord {
	Node *front;
	Node *rear;
	int size;
} Queue;

AVLTree *CreateTree();
AVLTree *InsertElement(int, AVLTree *) ;
int Max(int, int) ;
AVLTree *SingleRotateWithLeft(AVLTree *)  ;
AVLTree *SingleRotateWithRight(AVLTree *) ;
AVLTree *DoubleRotateWithLeft(AVLTree *) ;
AVLTree *DoubleRotateWithRight(AVLTree *) ;
int SearchAvlTree(AVLTree *, int) ;
void Display(AVLTree *) ;

int main()
{
	int size, i, element, value, answer ;
	AVLTree *myAVLTree ;
	myAVLTree = CreateTree() ;
	printf("Enter the # of data you want to insert: ") ;
	scanf("%d", &size) ;
	printf("Enter %d values: ", size) ;
	for(i=0 ; i<size ; i++)	{
		scanf("%d", &element) ;
		myAVLTree = InsertElement(element, myAVLTree) ;	}
//	printf("\n%d->%d->%d->%d->%d->%d\n", myAVLTree->left->left->val, myAVLTree->left->right->val, myAVLTree->left->val, myAVLTree->right->right->val, myAVLTree->right->val, myAVLTree->val) ;
//	printf("t->left: %d\n", myAVLTree->left->val) ;
	
	Display(myAVLTree) ;
	
	/*printf("Enter a value to search: ") ;
	scanf("%d", &value) ;
	answer = SearchAvlTree(myAVLTree, value) ;
	if(answer==0)
		printf("There is no such a value in the tree\n") ;
	else 
		printf("You have %d in the tree!\n", value) ;
	*/
	return 0 ;
}

AVLTree *CreateTree()
{
	return NULL ;
}

AVLTree *InsertElement(int val, AVLTree *t)	//This function insert an elemnt to the tree by considering the requirements for an AVL Tree.
{
	if (t == NULL)	{
		t = (AVLTree *)malloc(sizeof(AVLTree)) ;
		if (t == NULL)
			printf("Memory allocation is failed!\n") ;
		else	{
			printf("11111  ihiihihhii\n") ;
			t->val = val ; 
			t->height = 0 ;
			t->left = t->right = NULL ;	}	}
	else {
		if (val < t->val)	{
			t->left = InsertElement(val, t->left);
		//	printf("2222 ihiihihhii\n") ;
			if ((t->left->height - t->right->height) == 2)	{
				if (val < t->left->val)	{
				//	printf("3333333 ihiihihhii\n") ;
					t = SingleRotateWithLeft(t) ;	}	
				else
					t = DoubleRotateWithLeft(t) ;	}	}
		else if (val > t->val)	{
			t->right = InsertElement(val, t->right) ;
			if ((t->right->height - t->left->height) == 2)	{
				if (val > t->right->val)
					t = SingleRotateWithRight(t) ;
				else
					t = DoubleRotateWithRight(t) ;	}	}
	}
	return t ;
}

int Max(int x, int y)	//This function finds the max height (either left or right).
{
	if (x >= y)
		return x ;
	else
		return y ;
}

AVLTree *SingleRotateWithLeft(AVLTree *t) 
{
	AVLTree *temp ;
	temp = (AVLTree *)malloc(sizeof(AVLTree)) ;
	temp = t->left ;
	t->left = temp->right ;
	temp->right = t ;
	printf("ihiihihhii\n") ;
	t->height = Max(t->left->height, t->right->height)+1 ;
	temp->height = Max(temp->left->height, temp->right->height)+1 ;
//	printf("%d->%d->%d \n", t->val, t->left->val, t->right->val);	//This is to print the content in prefix order.
	return t ;
}

AVLTree *SingleRotateWithRight(AVLTree *t)
{
	AVLTree *temp;
	temp = (AVLTree *)malloc(sizeof(AVLTree)) ;
	temp = t->right ;
	t->right = temp->left ;
	printf("nonnono\n") ;
	temp->left = t ;
	t->height = Max(t->left->height, t->right->height)+1 ;
	temp->height = Max(temp->left->height, temp->right->height)+1 ;
//	printf("%d->%d->%d \n", t->left->val, t->val, t->right->val);	//This is to print the content in an infix order.
	return t ;
}

AVLTree *DoubleRotateWithLeft(AVLTree *t)
{
	t->left = SingleRotateWithLeft(t) ;
//	t = SingleRotateWithRight(t) ;
	printf("yeyeyey\n") ;
	
/*	AVLTree *temp;
	temp = (AVLTree *)malloc(sizeof(AVLTree)) ;
	temp = t->left ;
	t->left = temp->right ;
	t->left->left = temp ;
	temp = t ;
	t = temp->left;
	t->right = temp;	*/
//	printf("%d -> %d -> %d \n",t->left->val, t->val, t->right->val);	//This is to print the content in an infix order.
	return SingleRotateWithRight(t);
}

AVLTree *DoubleRotateWithRight(AVLTree *t)
{
	t->right = SingleRotateWithRight(t) ;
//	t = SingleRotateWithLeft(t) ;
	printf("lalalall\n") ;
	/*AVLTree *temp;
	temp = (AVLTree *)malloc(sizeof(AVLTree)) ;
	temp = t->right ;
	t->right = temp->left ;
	t->right->right = temp ;
	temp = t ;
	t = temp->right;
	t->left = temp;	*/
//	printf("%d -> %d -> %d \n",t->left->val, t->val, t->right->val);	//This is to print the content in an infix order.
	return SingleRotateWithLeft(t);
}

int SearchAvlTree(AVLTree *t, int value)
{
	if (t==NULL)
		return FALSE ;
	else	{
		if (t->val==value)
			return TRUE ;
		else {
			SearchAvlTree(t->left, value) ;
			SearchAvlTree(t->right, value) ;	
			return TRUE ;	}
		return FALSE ;	}
}

void Display(AVLTree *t)
{	
	if(t!=NULL){
		Display(t->left) ;
		printf("%d->", t->val) ;
		Display(t->right) ;		}	
}
