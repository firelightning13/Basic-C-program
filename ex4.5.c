#include <stdio.h> // EXERCISE CHAPTER 4 NO 5

int FindCube(int); //function prototype

int main()
{
	int num, times, result, i;
	
	printf("How many times to call cunftion FindCube() ?: ");
	scanf("%d", &times);
	
	for (i=0;i<times;i++) //how many times you want to calculate
	{
		printf("Function call %d:\n", i+1); //display current times
		printf("Enter a number: ");
		scanf("%d", &num); //input a number
		
		result = FindCube(num); //call function
		printf("%d x %d x %d = %d\n\n", num, num, num, result); //display result
	}
	
	system ("pause");
	return 0;
}

int FindCube(int x) //function definition
{
	return x*x*x; //can return directly to main()
}
