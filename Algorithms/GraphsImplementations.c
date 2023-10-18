#include<stdio.h>
#include<stdlib.h>

struct graphHead{
	int count;
	struct graphVertex *first;
};

struct graphVertex{
	struct graphVertex *next;
	struct Holder Scanpath;
	int neighbor;
	int processed;
	struct graphArc *firstArc;
};

struct graphArc{
	struct graphVertex *destination;
	struct graphArc *nextArc;
};

struct graphHead *createGraph(void){
	struct graphHead *head = (struct graphHead*)malloc(sizeof(struct graphHead));
	
	head->count = 0;
	head->first = NULL;
	
	return head;
}

void insertVertex(struct graphHead *head, struct Holder data){
	struct graphVertex *vertex = (struct graphVertex *)malloc(sizeof(struct graphVertex));
	
	vertex->next = NULL;
	vertex->Scanpath = data;
	vertex->neighbor = 0;
	vertex->processed = 0;
	vertex->firstArc = NULL;
	head->count++;
	
	if(head->first == NULL){
		head->first = vertex;	}
	else{
		struct graphVertex *tempVertex = head->first;
		while(tempVertex->next != NULL)
			tempVertex = tempVertex->next;
		tempVertex->next = vertex;	}
}

void displayGraph(struct graphHead *head){
	struct graphVertex *tempVertex = NULL;
	struct graphArc *tempArc = NULL;
	
	tempVertex = head->first;
	
	while(tempVertex != NULL){
		printf("\nData: %d|%s", tempVertex->Scanpath.id, tempVertex->Scanpath.letter);
		tempArc = tempVertex->firstArc;
		while(tempArc != NULL){
			printf("-> %d|%s", tempArc->destination->Scanpath.id);
			tempArc = tempArc->nextArc;	}
		tempVertex = tempVertex->next;	}
}

int insertArc(struct graphHead *head, int fromKey, int toKey){
	struct graphArc *arc = (struct graphArc *)malloc(sizeof(struct graphArc));
	struct graphVertex *fromVertex = NULL;
	struct graphVertex *toVertex = NULL;
	
	fromVertex = head->first;
	while(fromVertex!=NULL && fromVertex->data!=fromKey)
		fromVertex = fromVertex->next;
	
	if(fromVertex == NULL)
		return -2;	//fromVertex is not found!
		
	toVertex = head->first;
	while(toVertex!=NULL && toVertex->data!=toKey)
		toVertex = toVertex->next;
		
	if(toVertex == NULL)
		return -3;	//toVertex is not found!
	
	fromVertex->outDegree++;
	toVertex->inDegree++;
	
	arc->destination = toVertex;
	arc->nextArc = NULL;
	
	if(fromVertex->firstArc == NULL)
		fromVertex->firstArc = arc;
	else{
		struct graphArc *tempArc = fromVertex->firstArc;
		while(tempArc->nextArc != NULL)
			tempArc = tempArc->nextArc;
		tempArc->nextArc = arc;	}

	return 1;	//Successful operation!
}


int main(){
	
	return 0;
}








