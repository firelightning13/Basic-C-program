#include <stdio.h>
#include <string.h>
#define SIZE 3 //can define any SIZE if you want to add more names

int main()
{
	char todelete[12], student_name[SIZE][12] = {"Ali", "Fatimah", "Umar"}; //can store any name (in order with age[])
	int i, j, match, age[SIZE] = {23,22,21}; //can store any age (in order with student_name[][])
	
	//print the names list
	printf("Name\t\tAge\n");
	printf("====\t\t===\n");
	for(i=0;i<SIZE;i++)
		printf("%s\t\t%d\n", student_name[i], age[i]);
	printf("\n");
	
	do
	{
		match = 0; //re-initialize if wrong input name
		
		printf("Input name to delete: ");
		gets(todelete); //input name to delete
		
		for (i=0; i<SIZE; i++) //run a loop to check if todelete match with student_name[i]
		{
			if (strcmp(todelete, student_name[i]) == 0) //if todelete matched with student_name[i]
				{
					match = 1;
					for (j=i; j<=SIZE-i;j++) 	//run a loop to delete the wanted name and move everything
					{							//starting from its right to the left (in array student_name[])
						age[j] = age[j+1];		//kalau x paham blh tanya aku
						strcpy(student_name[j],student_name[j+1]);
					}
				}
		}
		
		if (match == 0)
			printf("Invalid name!\n"); //if user input wrong name
		
	} while (match != 1);
	
	//Show the new list
	printf("The new list is: \n");
	printf("Name\t\tAge\n");
	printf("====\t\t===\n");
	for(i=0;i<SIZE-1;i++) //SIZE-1, because one data has been removed
		printf("%s\t\t%d\n", student_name[i], age[i]);
	
	system ("pause");
	return 0;
}

