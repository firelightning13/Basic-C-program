#include <stdio.h> //EXERCISE CHAPTER 4 NO 1
//function prototypes for sum, diff and display 
void display(int);
int sum(int,int), diff(int,int);

int main ( )
{ 	int num1, num2, result;
	int choice;
	
	printf("Please enter two numbers: ");
	scanf("%d %d", &num1, &num2);
	printf("Now choose what you would like to do:\n ");
	printf("1 - Sum, 2 - Difference : ");
	scanf("%d", &choice);
	
	if (choice ==1)
	{	result = sum(num1, num2);
		display (result);
	}
	else if (choice == 2)
	{	result = diff(num1, num2);
		display (result);
	}
	else
		printf("Invalid choice\n");

	system("pause");
	return 0;
}
//function definition for sum, diff and display
int sum(int x, int y)
{
	return x+y;
}

int diff(int x, int y)
{
	return x-y;
}

void display(int r)
{
	printf("The result is: %d\n", r);
}

