#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 5
#define ROW 5

int player1[ROW][COL], player2[ROW][COL], p1win=0, p2win=0; // create necessary variables and arrays
void generateTable(int), checkTable(int, int), printTable(int), bingoTable(int); // create a user-defined function

int main()
{
	int noplayer = 0, pick;
	srand(time(NULL)); //seeding the RNG is necessary
	while (noplayer<2) //versus mode; player 1 vs player 2
	{
		
		generateTable(noplayer); //to generate bingo table
		noplayer++;
	}
	do
	{
		system("cls"); // clear the screen for more ui friendly-ness
		
		pick = 1 + rand() % 25; // choose a random number to mark X
		printf("Chosen one: %d\n", pick);
		noplayer = 0;
		while (noplayer<2)
		{
			checkTable(pick, noplayer); //check the number to mark X
			printTable(noplayer); //display player's card
			noplayer++;
		}
		
		noplayer = 0;
		while (noplayer < 2)
		{
			bingoTable(noplayer); //check if one of the player wins (currently only check row and column)
			noplayer++;
		}
		
		if (p1win == 1 && p2win == 0) // if player 1 wins
			printf("Player one wins!\n");
		else if (p1win == 0 && p2win == 1) // if player 2 wins
			printf("Player two wins!\n");
		else if (p1win == 1 && p2win == 1) // if they both win (its a tie)
			printf("It's a draw!\n");
		
		sleep(1); // delay the match in one second(?)
		//system("pause"); // use this if user wants to press any key in each round
		
	} while (p1win == 0 && p2win == 0); // will loop infinitely until one of the player wins or draw
		
	system ("pause");
	return 0;
}

void generateTable(int no) // "no" variable is "noplayer" from main()
{
	int i, j, temp, rndindex, gen[25];
	for (i=1;i<=25;i++) //generate number in gen[]
	{
		gen[i-1] = i;
	}
	
	for (i=0;i<25;i++) //shuffle random gen[]
	{
	    temp = gen[i];
	    rndindex = 0 + rand() % 25;
	
	    gen[i] = gen[rndindex];
	    gen[rndindex] = temp;
	}
	
	for (i=0; i<ROW; i++) //insert gen[] into player's card
	{
		for (j=0;j<COL;j++)
		{
			if (no == 0) // for player 1
				player1[i][j] = gen[j+(i*5)];
			else // for player 2
				player2[i][j] = gen[j+(i*5)];
		}
	}
}

void checkTable(int np, int no) // "np" variable is "pick" from main()
								// "no" variable is "noplayer" from main()
{
	int i, j;
	for (i=0;i<ROW;i++)
	{
		for (j=0;j<COL;j++)
		{	// if the picked number matches with a number in the table,
			// replace it with -1 so it is printable with mark "X"
			if (no == 0)
			{ // for player 1
				if (player1[i][j] == np)
					player1[i][j] = -1;
			}
			else // for player 2
				if (player2[i][j] == np)
					player2[i][j] = -1;
		}
	}
}

void printTable(int no) // "no" variable is "noplayer" from main()
{
	int i, j;
	printf("Player %d card:\n", no+1); // display current player
	printf("B\tI\tN\tG\tO\t\n"); // ui friendly-ness
	for (i=0; i<ROW; i++)
	{
		for (j=0;j<COL;j++)
		{
			if (no == 0) // for player 1
				if (player1[i][j] == -1)
					// if one of the number in the table matches with picked number, mark "X"
					printf("X\t");
				else // print unmarked number
					printf("%d\t", player1[i][j]);
			else
			{ // for player 2
				if (player2[i][j] == -1)
					// if one of the number in the table matches with picked number, mark "X"
					printf("X\t"); 
				else// print unmarked number
					printf("%d\t", player2[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

void bingoTable(int no)  // "no" variable is "noplayer" from main()
{
	int i, j, match;
	
	for (i=0;i<ROW;i++) // check for column table
	{
		match=1;
		for (j=0;j<COL;j++)
		{
			if (no == 0)
			{
				if (player1[i][j] != -1) // for player 1
				{
					match = 0; // if one of the column is not the same as -1, it will not match
					break;
				}	
			}
			else
			{
				if (player2[i][j] != -1) // for player 2
				{
					match = 0; // if one of the column is not the same as -1, it will not match
					break;
				}
			}
		}
		if (match == 1)
			break;
	}
	
	if (match != 1) //if column is already matched, skip the row check
	{
		for (i=0;i<COL;i++) // check for row table
		{
			match=1;
			for (j=0;j<ROW;j++)
			{
				if (no == 0)
				{
					if (player1[j][i] != -1)
					{
						match = 0; // if one of the row is not the same as -1, it will not match
						break;
					}
				}
				else
				{
					if (player2[j][i] != -1)
					{
						match = 0; // if one of the row is not the same as -1, it will not match
						break;
					}
				}
			}
			if (match == 1)
				break;
		}
	}
	
	if (match == 1 && no == 0) //if mark X is matched row or column, player 1 wins
		p1win = 1;
	else if (match == 1 && no == 1) //if mark X is matched row or column, player 2 wins
		p2win = 1;
}
