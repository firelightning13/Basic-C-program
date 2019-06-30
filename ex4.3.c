#include <stdio.h> // EXERCISE CHAPTER 4 NO 3
#include <stdlib.h>
#include <time.h>
char letter();	//function prototype

int main ( )
{  	char huruf;
	int i;
	srand(time(NULL));
	
	printf("Your password is: ");
	for (i=0; i<6; i++) //run "for" loop six times to generate a password
	{
		huruf = letter(); //call function; to generate random letter
		printf("%c", huruf); //print every single generated character
	}
	printf("\n");
	
	system("pause");
	return 0;
}

char letter() //function definition; to generate random letter
{
	char random; //generate letter from 65 to 90 (from A-Z)
	random = 65 + rand() % (90-65+1); //formula for random letter generator
	return random; //NOTE: number return as a character (ASCII code, refer to pg 204)
} 

