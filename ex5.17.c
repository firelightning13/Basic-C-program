#include <stdio.h>

int main()
{
	int Number[5], sum=0, largest, smallest, i;
	float average;
	
	printf("Enter 5 numbers: ");
	for (i=0;i<5;i++)
		scanf("%d", &Number[i]); //input number 5 times
	
	//initialize smallest and largest number at index 0
	//before do the checking
	smallest = Number[0]; 
	largest = Number[0];
	
	for (i=0;i<5;i++) //run a loop to check every single number
	{
		sum+=Number[i]; //Add the Number[] to "sum" every loop
		
		if (smallest > Number[i]) //if the Number[i] happens to be smaller than
			smallest = Number[i]; //"smallest", assign it to "smallest"
			
		if (largest < Number[i]) //if the Number[i] happens to be larger than
			largest = Number[i]; //"largest", assign it to "largest"
	}
	
	average = (float)sum / 5; //convert "sum" to float type before calc average
	
	//Print the result
	printf("The sum is %d\n", sum);
	printf("The average is %.1f\n", average);
	printf("The largest is %d\n", largest);
	printf("The smallest is %d\n", smallest);
	
	system ("pause");
	return 0;
}

