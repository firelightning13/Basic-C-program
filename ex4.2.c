#include <stdio.h> // EXERCISE CHAPTER 4 NO 2

int even_or_odd(int); //function prototype

int main()
{
	int num;
	
	printf("Enter a number: ");
	scanf("%d", &num); //input a number
	
	if ( (even_or_odd(num)) == 1) //call function and compare
		printf("The number is even\n");
	else
		printf("The number is odd\n");
	
	system ("pause");
	return 0;
}

int even_or_odd(int x) //function definition
{
	int result; 
	if (x%2==0)
		result = 1; //true (even)
	else
		result = 0; //false (odd)
		
	return result; //return a value back to main
}

