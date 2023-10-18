#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void create_code (char *[]) ;
void player_guess (char *[]) ;
void find_score (char *[], char *[], char *[]) ;
void display_score (char *[], int, int *) ;
void display_winner (char *[], int *, int) ;

int main ()
{
	srand(time(NULL)) ;
	char *colors[5] = {"Red", "Green", "Orange", "Blue", "Yellow"} ;
	char answer, *userarray[5], *score[5] ;
	int  i, round, *result ;

	printf("\n\t\tCODEBREAKER IS STARTING!\n\n") ;
	printf("\n\nSecret Code Generated!") ;

	do {									//This loop should be executed at least one time so do-while loop is going to execute it at the beginning without asking anything.
		char answer ;

		create_code(&colors) ;
		for (round=1 ; round<9 ; round++)	{

			printf("\n\n%d.Enter your guess: ", round) ;
			player_guess (&userarray) ;
			find_score (&colors, &userarray, &score) ;
			display_score (&score, round, &result) ;

			if (result == 1)
				break ;
			else	{
				if (round == 8)	{
					display_winner (&colors, &result, round) ;
					break ;		}	}	}
		printf("\n\nDo you want to play again (Y/N) ?  ") ;
		scanf(" %c", &answer) ;

		if (answer == 'n' || answer == 'N')	{
			printf("\nBYEE !!") ;
			break ;		}
		printf("\n\n") ;
	} while (answer!='n' || answer!='N') ;  	//If the user says he/she doesn't want to play again, the loop will stop.

	return 0 ;
}

void create_code (char *colors[])   //This function will create a secret code with 5 colors for computer.
{
	int i, j;

	for(j=0 ; j<4 ; j++)
	{
		i = rand()%5 ;
		colors[j] = colors[i] ;
		printf("%s ", colors[j]);   //This part will show the secret code made on the screen to check if the score is displayed correctly or not.
	}
}

void player_guess (char *userarray[])  //This function will take the user guess and stores these values.
{
	int i ;
	for (i=0 ; i<4 ; i++)	{
		scanf("%s", &userarray[i]) ;	}
}

void find_score (char *colors[], char *userarray[], char *score[])  //This function will create the appropriate score table according to the user guess.
{
	int i, j, a ;

	for (i=0 ; i<4 ; i++)	{
		for (j=0 ; j<4 ; j++)	{
			a = strcmp(colors[i], (userarray+j)) ;
			while(i != j)	{
				if (a==0)
					strcpy((score+j), "White") ;
				else	{
					if (strcmp((score+j), "White") != 0 )
						strcpy((score+j), " _ ") ;	}
			break ;	}	}	}
	for(i=0 ; i<4 ; i++)	{
		if(strcmp(colors[i], (userarray+i)) == 0)
			strcpy((score+i), "Black") ;	}

	printf("\nYour score: ") ;
	for (i=0 ; i<4 ; i++)	{
		printf("%s ", score+i) ;	}
}

void display_score (char *score[], int round, int *result)  //This function will decide if the user breaks the code or not, and if he/she breaks the code, the result will return 1 and the computer will stop asking for more guess. If the code is not broken, the result will return 0 and user will continue to make guesses.
{
	int i, counter=0 ;

	for (i=0 ; i<4 ;i++)	{
		if (strcmp((score+i), "Black") == 0)
			counter ++ ;	}
	if (counter == 4)	{
		printf("\nYou found it after %d guesses! You WON!! ", round) ;
		*result = 1 ;	}
	else
		*result = 0 ;
}

void display_winner (char *colors[], int *result, int round) //This function will display the winner. If the user can not guess the code correctly after 8 try, the codemaker will win and it will show the secret code on the screen.
{
	int i ;

	if (round == 8)	{
		printf("\n\nYou LOST!\nSecret code: ") ;
		for (i=0 ; i<4 ; i++)
			printf("%s ", colors[i]) ;
		printf("\nCODEMAKER WINS!") ;	}
}

