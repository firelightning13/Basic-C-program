#include <stdio.h>
#include <string.h>

void bubbleSort(void); //function prototype
char names[5][12]; //initialize list names in global, so it's easy to modify

int main()
{
	int i;
	
	printf("Enter a name: ");
	for (i=0; i<5; i++)
		gets(names[i]); //input names 5 times
	
	bubbleSort(); //call the function
	
	printf("\nSorted names list:\n");
	for (i=0; i<5; i++)
		puts(names[i]); //prints the sorted names list
	
	system ("pause");
	return 0;
}

void bubbleSort() //algorithm taken from pg 170, except using string instead
{
	char temp[12];
	int i, j;
	for (i=0; i<4; i++)
	{
		for (j=1; j<5; j++)
		{
			if (strcmpi(names[j],names[j-1]) < 0)	//usually from A to Z means the
			{										//value is bigger (refer to pg 204)
				strcpy(temp, names[j]);
				strcpy(names[j], names[j-1]);
				strcpy(names[j-1], temp); 
			}
		}
	}
}
