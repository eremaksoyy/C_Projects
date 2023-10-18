#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stud {	//Student structure with all the necessary values
	char studentID[4];
	char name[40];
	char department[4];
} Student;

typedef struct array {	//An array structure to hold the student information with the key values for hash table
	int key;
	Student *stud;
} Array;

Array *CreateArray(Array *);
void addStudent(int, Student *, Array *);
void DoubleHashing(Student *, Array *);
void QuadraticProbing(Student *, Array *);
int hash1(int, int);
int hash2(int, int);
void searchStudent(Array *, int *);
void printTable(Array *, int *);


int main(){
	int option, opaddChoice, counter, holder, i, size;
	Array *hash;
	hash = (Array*)malloc(sizeof(Array)*11);
	CreateArray(hash);

	printf("Please enter your choice for open addressing technique:\n(1) Double Hashing\n(2) Quadratic Probing\n\nChoice: ");
	scanf("%d",&opaddChoice);

	if(opaddChoice!=1 && opaddChoice!=2){
		printf("Invalid value entered!\n");
		exit(1);	}
		counter = 0;	//counter will hold the number of elements in the hash table
		size=11;	//as size is 11 initially
		char ID[4];

	do{
		printf("\n1. Add a student\n2. Search for a student using ID\n3. Print Table\n4.Exit\n\nPlease select an option: ");
		scanf("%d",&option);
		if(option>4 || option<1){
			printf("\nInvalid value for option is entered! Please try again.\n\n");
			break;	}
		Student *student;
		student = (Student*)malloc(sizeof(Student));
		switch(option){
			case 1:
				if(student == NULL)	{
					printf("Memory allocation is not successful!\n");
					exit(1) ;	}
				counter+=1;
				printf("\nEnter unique identifier: ");
				fflush(stdin);
				gets(ID);
				strcpy(student->studentID,ID);
				fflush(stdin);
				printf("Enter name: ") ;
				fflush(stdin);
				gets(student->name);
				fflush(stdin);
				printf("Enter department: ");
				fflush(stdin);
				gets(student->department);
				fflush(stdin);
				addStudent(opaddChoice,student,hash);
				break;

			case 2:
				searchStudent(hash,&size);
				break;

			case 3:
				printTable(hash,&size);
				break;
		}

	} while(option!=4 || option>4);

	return 0;
}


Array *CreateArray(Array *arr){	//Creates a NULL array of structure with size 11 for the beginning.
	int i;
	for(i=0 ; i<11 ; i++){
		arr[i].key = 0;
		arr[i].stud = NULL;	}
	return arr;
}


void addStudent(int option, Student *student, Array *hash){
	if(option==1)
		DoubleHashing(student,hash);
	else
		QuadraticProbing(student,hash);
}


void DoubleHashing(Student *student, Array *hash){
	int i=0, h1, h2, index;
	hash->key = (int)student->studentID[0] - 65 + (student->studentID[1]-48)+ (student->studentID[2]-48);
	h1=hash1(hash->key,11);
	h2=hash2(hash->key,11);

	if(hash[h1].stud == NULL){
		hash[h1].stud = student;	}
	else{
		while(1){
			index = ((hash->key)*2 + i*h2) % 11;	//Applies hash2 function when the collision occurs.
			if(hash[index].stud==NULL){
				hash[index].stud=student;	}
			i++;	}	}
}


void QuadraticProbing(Student *student, Array *hash){
	int i, j=0, index, newIndex;
	hash->key = (int)student->studentID[0] - 65 + (student->studentID[1]-48)+ (student->studentID[2]-48);
//	printf("key %d: ",hash->key);
	index = (hash->key *2) % 11;
		if(hash[index].stud == NULL){
			hash[index].stud = student;	}
		else{
			while(1){
				newIndex = ((hash->key)*2 + (j*j)) % 11;
				if(hash[newIndex].stud == NULL){
					hash[newIndex].stud = student;	}
				j++;	}	}
}


int hash1(int key, int size){
	return (2*key)%size;
}


int hash2(int key, int size){
	return (7-(key%7));
}


void searchStudent(Array *table, int *size){
	int i, counter=0;
	char ID[4];
	printf("Enter unique identifier: ");
	fflush(stdin);
	gets(ID);
	fflush(stdin);
	for(i=0 ; i<*size ; i++){
		if(strcmp(ID,table[i].stud->studentID)==0){
			printf("Name: %s", table[i].stud->name);
			printf("Department: %s", table[i].stud->department);
			counter++;	}	}
	if(counter!=1){
		printf("Student is not found!\n");
		exit(1);	}
}


void printTable(Array *hashTable, int *size){
	int i;
	printf("Index\tID\tName\tDepartment\n");
	for(i=0 ; i<*size ; i++){
		if(hashTable[i].stud != NULL){
			printf("%d\t%s\t%s\t%s\n",i,hashTable[i].stud->studentID,hashTable[i].stud->name,hashTable[i].stud->department);	}	}
}

