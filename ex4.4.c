#include <stdio.h> // EXERCISE CHAPTER 4 NO 4

void draw(int,char); //function prototype

int main()
{
	char symbol;
	int side;
	
	//Input side and symbol
	printf("Input side: ");
	scanf("%d", &side);
	printf("Input symbol: ");
	scanf(" %c", &symbol);
	
	draw(side, symbol); //call function; to draw a square with symbol
	
	system ("pause");
	return 0;
}

void draw(int side, char symbol) //function definition
{
	int i, j;
	
	for (i=0; i<side; i++) //row
	{
		for (j=0; j<side;j++) //column
		{
			printf("%c ", symbol); //make a column
		}
		printf("\n"); //make a new line then make a column again
	}
}
