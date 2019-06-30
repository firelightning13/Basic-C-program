#include <stdio.h>
#include <string.h>

int main()
{
	char firstname[10][12] = {"azira", "azlina", "fatimah", "farhana", "bakhtiar", "bunyamin",
							  "zafrul", "hamka", "rohizi", "azhar"}; //list all the names
							  //NOTE: Don't do this in final exam
	char search[12]; //things to search
	int i, j, match=0, found=0; // all relevant variables
	
	//print all names in firstname[]
	for (i=0; i<10; i++)
		puts(firstname[i]);
	printf("\n");
	
	do
	{
		printf("Search names begin with?: ");
		gets(search); //input keyword search (such as "az")
		
		for (i=0; i<10; i++) //run a loop to check every name in firstname[i]
		{
			for (j=0;j<strlen(search); j++) // run a loop to match keyword[j] with firstname[i][j]
			{
				if (search[j] == firstname[i][j])
					match = 1; 	//if keyword matched, re-run the "for" loop until all 
				else			// keywords are used up	(the [j], not [i])
				{
					match = 0; //if not matched, break the "for" loop (the [j], not [i])
					break;
				}
			}
			
			if (match == 1) //if search is matched, print it
			{
				puts(firstname[i]);
				found++; //to count how many names are found (to break do-while loop)
			}
		}
		
		if (found == 0) //if search is not match
			printf("Sorry! We couldn't find anything!\n");
		
	} while (found == 0); //if search is not found, run do-while loop again
	
	system ("pause");
	return 0;
}

