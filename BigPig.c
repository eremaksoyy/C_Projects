#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int play_user (char) ;
int roll_a_dice () ;
char play_computer (int) ;
int computer_strategy_decider (int, int) ;
void scoresheet (int, int) ; 


int main ()
{
	int randplayer, randpc, ans, roundcounter=1, scorepc, scoreplayer, answerpc ;
	char answer ;
	int dice1, dice2, x, y, roundplayer=1, roundpc=1, score1, score2 ;
	int totalplayer=0, totalpc=0, finaltotalplayer=0, finaltotalpc=0 ;
	
	printf("\nWelcome to the Big Pig Game. \nLet's get started!\n\n") ;
	
	srand(time(NULL)) ;
	answerpc = rand()%2 ;
			
	srand(time(NULL)) ;
	randpc = 1 + rand()%6 ;
	printf("I have rolled a dice and got %d ! \nShall I roll the dice for you (Y / N)?  ", randpc) ;
	scanf(" %c", &answer) ;
	
	ans = (int)play_user(answer) ;
	
	switch (ans)
	{
	case 1 :
		srand(time(NULL)) ;
		randplayer = 1 + rand()%6 ;
		printf("\nI have rolled the dice for you and you got %d ! ", randplayer) ;
		
		if (randplayer != randpc)
		{
			if (randplayer > randpc)
			{
				printf("\nYou got the higher number! \n") ;
				
				while (roundcounter <= 6)
				{
					printf("\nRound %d   ----   Your turn!", roundcounter) ;
				
					while (roundplayer <= 6)
					{
						dice1 = roll_a_dice() ;
						dice2 = roll_a_dice() ;
						
						if ((dice1 != 1 && dice2 != 1) || (dice1 == 1 && dice2 == 1))
						{
							printf("\nYou got =  [Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
							printf("\n", computer_strategy_decider(dice1, dice2)) ;
							printf("\n\n ", play_user(answer)) ;
					
							if (answer == 0)
								break ;
							else if (answer == 1)
								continue ;
								roundplayer += 1 ;
						}
						else
						{
							printf("\nYou got =  [Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
					    	printf("\nYou got a single one. End of your turn!  ") ;	
					    	roundplayer += 1 ;
							break ;
						}		
					score1 = (int) computer_strategy_decider(dice1, dice2) ;	
					}	
				
					printf("\n\n\n\n") ;
					printf("\n\nRound %d   ----   My turn!", roundcounter) ;
					
					while (roundpc <=6 )
					{
						dice1 = roll_a_dice() ;
						dice2 = roll_a_dice() ;
						
						if ((dice1 != 1 && dice2 != 1) || (dice1 == 1 && dice2 == 1))
						{
							printf("\nI got =  [Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
							printf("\n", computer_strategy_decider(dice1, dice2)) ;
							printf("\n ", play_computer(answerpc)) ;
					
							if (answerpc == 'N')
								break ;
							else if (answerpc == 'Y')
								continue ;
							roundpc += 1 ;	
						}
						else
						{
							printf("\nI got =  [Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
					    	printf("\nI got a single one. End of my turn!  ") ;	
					    	roundpc += 1 ;
							break ;
						}
					score2 = (int) computer_strategy_decider(dice1, dice2) ;
					printf("\n", (score1, score2)) ;
					}
					printf("\n\n ---------------------- \n\n") ;
				roundcounter += 1 ;	
				}			
			}
			
			else if (randpc > randplayer)
			{
				printf("\nI got the higher number! \n") ;
					printf("\n\nRound %d   ----   My turn!", roundcounter) ;
					
					while (roundpc <=6 )
					{
						dice1 = roll_a_dice() ;
						dice2 = roll_a_dice() ;
						
						if ((dice1 != 1 && dice2 != 1) || (dice1 == 1 && dice2 == 1))
						{
							printf("\nI got =  [Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
							printf("\n", computer_strategy_decider(dice1, dice2)) ;
							printf("\n ", play_computer(answerpc)) ;
					
							if (answerpc == 'N')
								break ;
							else if (answerpc == 'Y')
								continue ;
							roundpc += 1 ;	
						}
						else
						{
							printf("\nI got =  [Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
					    	printf("\nI got a single one. End of my turn!  ") ;	
					    	roundpc += 1 ;
							break ;
						}
						score2 = (int) computer_strategy_decider(dice1, dice2) ;
					}
						
					printf("\n\n\n\n") ;	
					printf("\nRound %d   ----   Your turn!", roundcounter) ;
				
					while (roundplayer <= 6)
					{
						dice1 = roll_a_dice() ;
						dice2 = roll_a_dice() ;
						
						if ((dice1 != 1 && dice2 != 1) || (dice1 == 1 && dice2 == 1))
						{
							printf("\nYou got =  [Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
							printf("\n", computer_strategy_decider(dice1, dice2)) ;
							printf("\n\n ", play_user(answer)) ;
					
							if (answer == 0)
								break ;
							else if (answer == 1)
								continue ;
								roundplayer += 1 ;
						}
						else
						{
							printf("\nYou got =  [Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
					    	printf("\nYou got a single one. End of your turn!  ") ;	
					    	roundplayer += 1 ;
							break ;
						}
					score1 = (int) computer_strategy_decider(dice1, dice2) ;
					printf("\n", (score1, score2) );							
				    }
				roundcounter += 1 ;
			}
		}
	
		else
			printf("\nSame number. Please try again if you want to play! ") ;
		break ;	
		
	case 0 :
		printf("\nYou wanted to exit the game. Bye! ") ;
		break ;
	}	
	
	return 0 ;
}


int play_user(char answer)
{
	printf("\nDo you want to continue? (Y/N) ") ;
	scanf(" %c", &answer) ;
	
	if (answer == 'y' || answer == 'Y')
		answer = 1 ;
	else if (answer == 'n' || answer == 'N')
	  	answer = 0 ;
	else 
		printf("\nInvalid value entered! ") ;
 return answer ;	
}



int roll_a_dice() 
{ 
	int result ;

	result = 1 + (int)rand()%6 ;
	
 return result ;
}



char play_computer(int answerpc)
{
	if (answerpc == 0)
		answerpc = 'N' ;
	else 
		answerpc = 'Y' ;
	
	printf("\nDo you want to continue? (Y/N)   ") ;
	printf("\nMy decision: %c ", answerpc) ;
 return answerpc ;
}



int computer_strategy_decider(int dice1, int dice2)
{
	int score ;
	
	if (dice1 != 1 && dice2 != 1)
	{
		if (dice1 == dice2)
		{
			score = 4*dice1 ;
			printf("\nScore: %d \nDoubles! Roll again! \n", score) ;
			dice1 = roll_a_dice() ;
			dice2 = roll_a_dice() ;
			printf("\n[Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
			
			while (dice1 == dice2)
			{
				score = 4*dice1 ;
				printf("\nScore: %d \nDoubles! Roll again! \n", score) ;
				dice1 = roll_a_dice() ;
				dice2 = roll_a_dice() ;
				printf("\n[Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
			}
			score = dice1 + dice2 ;
			printf("\nScore: %d ", score) ;
		}
		else
		{
			score = dice1 + dice2 ;
			printf("\nScore: %d ", score) ;
		}	
	}
	else if  (dice1 == 1 && dice2 == 1)
	{
		score = 25 ;
		printf("\nDoubles! Roll again! \n") ;
		dice1 = roll_a_dice() ;
		dice2 = roll_a_dice() ;
		printf("\n[Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
		
		
		while (dice1 == dice2)
		{
			score = 4*dice1 ;
			printf("\nScore: %d \nDoubles! Roll again! \n", score) ;
			dice1 = roll_a_dice() ;
			dice2 = roll_a_dice() ;
			printf("\n[Dice1]: %d   [Dice2]: %d ", dice1, dice2) ;
		}
			score = dice1 + dice2 ;
			printf("\nScore: %d ", score) ;
	}
 return score ;	
}


void scoresheet (int score1, int score2)
{			
    int totalplayer=0, totalpc=0 ;

	totalplayer = totalplayer + score1 ;	
	totalpc = totalpc + score2 ;
	
	printf("\n\n--- Scoresheet ---\nYour Score: %d  My Score: %d", totalplayer, totalpc) ;
	totalpc = 0 ;
	totalplayer = 0 ;
}
