#include<stdio.h>
#include<time.h>
#define A 7
#define B 7

void initiliazeboards(char [A][B], char **, int) ;
int randomdiamond() ;
void getguessedcoordinates(int *, int *) ;
int checkdiamonds(int *, int *, char **) ;
void providehints(int, int, char [A][B], char **) ;
void displayuserboard(char [A][B]) ;

int main()
{
	int ans, answer, diamondnum, i, j, output ;
	char userboard[A][B], **diamondboard ;
	int round, score, total=0, rowcoord, columncoord, choice ;

	printf("\n *Diamond-Hunter* ") ;
	answer=1 ;
	do
	{
		printf("\n Let's get started! ") ;
		srand(time(NULL)) ;

		switch(answer)
		{
			case 1 :
				printf("\n Enter the number of diamonds to hunt: ") ;
				scanf("%d", &diamondnum) ;
				printf("\n\n") ;
				printf("User board \n") ;

				for(i=1 ; i<8 ; i++)
					printf("   %d ", i) ;
				printf("\n") ;


                diamondboard = (char**)malloc(A*sizeof(char*));
                for(i=0 ; i<A+1 ; i++)
                    diamondboard[i] = (char*)malloc((A)*sizeof(char));

				initiliazeboards(userboard, diamondboard, diamondnum) ;


				for(round=1 ; round<=10 ; round++)
				{
					printf("\nRound %d ", round) ;
					getguessedcoordinates(&rowcoord,&columncoord) ;

					printf("Coordinates are  (%d, %d) ", rowcoord, columncoord) ;

					fflush(stdin) ;
					checkdiamonds(&rowcoord, &columncoord, diamondboard) ;

					output = checkdiamonds(&rowcoord,&columncoord,diamondboard) ;

					if(output==1)
					{
						score=100 ;
						total += score ;
						printf("\nYou got %d points! \nYour total points is %d ! \n\n", score, total) ;
						userboard[rowcoord-1][columncoord-1] = '*' ;
					}
					else
					{
						score=0 ;
						total += score ;
						printf("\nYou got %d points! \nYour total points is %d ! \n\n", score, total) ;
						providehints(rowcoord, columncoord, userboard, diamondboard) ;
					}

					displayuserboard(userboard) ;
				}

				printf("\n\nYou run out of rounds! Game over! \nWould you like to play again? (Y/N) Enter '1' for YES or '0' for NO :  ") ;
				scanf("%d", &answer) ;
				total=0 ;
				fflush(stdin) ;
				break ;

			default :
				printf("\n Invalid value entered. Please try again! \n\n") ;
				break ;
		}
	} while(answer != 0)  ;

	return 0 ;
}

void initiliazeboards(char userboard[A][B], char **diamondboard, int n)
{
	int i, j, row, column ;

	for(i=0 ; i<7 ; i++)
	{
		printf("%d", (i+1)) ;
		for (j=0 ; j<7 ; j++)
		{
			userboard[i][j] = '?' ;
			diamondboard[i][j] = '?' ;
			printf("  %c  ", userboard[i][j]) ;
		}
		printf("\n") ;
	}

	for(i=0 ; i<n ;i++)
	{
		row = randomdiamond() ;
		column = randomdiamond() ;
		diamondboard[row][column] = '*' ;
	}
	printf("\n") ;
}

int randomdiamond()
{
	int num ;
	num = (int)rand()%7 ;

	return num ;
}

void getguessedcoordinates(int *rowcoord, int *columncoord)
{
	int roww, columnn ;

	printf("\nEnter the coordinates of diamonds (row, column)  :  ") ;
	scanf("%d,%d", &roww, &columnn) ;
	*rowcoord = roww ;
	*columncoord = columnn ;
}

int checkdiamonds(int *rowcoord, int *columncoord, char **diamondboard)
{
	int count=0, value ;

		value = diamondboard[*rowcoord-1][*columncoord-1] ;

		if(value == '*')
			count += 1 ;

	if(count != 0)
		return 1 ;
	else
		return 0 ;
}

void displayuserboard(char userboard[A][B])
{
	int i, j ;

	for(i=1 ; i<8 ; i++)
		printf("   %d ", i) ;
	printf("\n") ;
	for(i=0 ; i<7 ; i++)
	{
		printf("%d", (i+1)) ;
		for (j=0 ; j<7 ; j++)
			printf("  %c  ", userboard[i][j]) ;
		printf("\n") ;
	}
}

void providehints(int rowcoord, int columncoord, char userboard[A][B], char **diamondboard)
{
	int i, j, counter=0 ;

	if(rowcoord==1 || rowcoord==7 || columncoord==1 || columncoord==7)
	{
		if(rowcoord == 1)
		{
			if(columncoord == 1 || columncoord==7)
			{
				for(i=rowcoord-1 ; i<=rowcoord ; i++)
				{
					if(columncoord==1)
					{
						for(j=columncoord-1 ; j<=columncoord ; j++)
						{
							if(diamondboard[i][j] == '*')
							counter += 1 ;
						}
					}
					else
					{
						for(j=columncoord-2 ; j<=columncoord-1 ; j++)
						{
							if(diamondboard[i][j] == '*')
							counter += 1 ;
						}
					}
				}
			}
			else
			{
				for(i=rowcoord-1 ; i<=rowcoord ; i++)
				{
					for(j=columncoord-1 ; j=columncoord+1 ; j++)
					{
						if(diamondboard[i][j] == '*')
							counter += 1 ;
					}
				}
			}
		}
		else if(rowcoord == 7)
		{
			if(columncoord == 1 || columncoord==7)
			{
				for(i=rowcoord-2 ; i<=rowcoord-1 ; i++)
				{
					if(columncoord==1)
					{
						for(j=columncoord-1 ; j<=columncoord ; j++)
						{
							if(diamondboard[i][j] == '*')
							counter += 1 ;
						}
					}
					else
					{
						for(j=columncoord-2 ; j<=columncoord-1 ; j++)
						{
							if(diamondboard[i][j] == '*')
							counter += 1 ;
						}
					}
				}
			}
			else
			{
				for(i=rowcoord-2 ; i<=rowcoord-1 ; i++)
				{
					for(j=columncoord-1 ; j<=columncoord+1 ; j++)
					{
						if(diamondboard[i][j] == '*')
							counter += 1 ;
					}
				}
			}

		}
		else
		{
			for(i=rowcoord-2 ; i<=rowcoord ; i++)
			{
				if(columncoord==1)
				{
					for(j=columncoord-1 ; j<=columncoord ; j++)
					{
						if(diamondboard[i][j] == '*')
						counter += 1 ;
					}
				}
				else
				{
					for(j=columncoord-2 ; j<=columncoord-1 ; j++)
					{
						if(diamondboard[i][j] == '*')
						counter += 1 ;
					}
				}
			}
		}
	}

	else
	{
		for (i=rowcoord-2 ; i<=rowcoord ; i++)
		{
			for(j=columncoord-2 ; j<=columncoord ; j++)
			{
				if(diamondboard[i][j]=='*')
					counter += 1 ;
			}
		}
	}
	if(counter != 0)
	{
		counter = (char)(counter+48) ;
		userboard[rowcoord-1][columncoord-1] = counter ;
	}
}


