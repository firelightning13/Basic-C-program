#include <stdio.h>

int main()
{
	int num[] = {12, 3, 10, 30, 25}; //init array
	int i, smallest, biggest;
	
	smallest = num[0]; //init at index 0
	biggest = num[0]; //init at index 0
	
	for (i=0; i<5; i++) //start a loop to check every single number
	{
		if (smallest > num[i]) //if the num[i] happens to be smaller
			smallest = num[i]; //than "smallest" variable
			
		if (biggest < num[i]) //if the num[i] happens to be bigger
			biggest = num[i]; //than "biggest" variable
	}
	
	//Print the result
	printf("Smallest number: %d\n", smallest);
	printf("Biggest number: %d\n", biggest);
	
	system ("pause");
	return 0;
}

