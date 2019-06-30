#include <stdio.h>
#include <string.h>

int main()
{
	char username[3][10] = {"Ahmad", "Nur", "Fahmi"}; //usernames list (in order with password)
	char password[3][10] = {"hello123", "welcome", "$frt#a26"}; //passwords list (in order with username)
	char inputname[10], inputpass[10]; //for user input
	int i, match = 0;	//match = 0, username doesn't match; match = -1, password doesn't match
						//match = 1, username and password are matched;
	
	do
	{
		match = 0; //re-initialize the match variable if username or password don't match
		
		printf("Input username: ");
		gets(inputname); // input username
		
		for (i=0; i<3; i++) //run a loop to check if inputpass matched the available username
		{
			if (strcmp(inputname, username[i]) == 0) //compare if inputname match username[i]
			{
				printf("Input password: ");
				gets(inputpass); //input password if username is matched
				
				if (strcmp(inputpass, password[i]) == 0) //compare if inputpass match password[i]
				{
					printf("Login Successfully for %s\n", username[i]); //if password is matched
					match = 1;
					break; // break "for" loop
				}
				else
					{
						printf("Invalid Password!\n"); //if password doesn't match
						match = -1;
					}
			}
		}
		
		if (match == 0) 
			printf("Invalid User!\n"); //if username doesn't match
			
	} while (match != 1); //if password and username don't match, run do-while loop again
	
	system ("pause");
	return 0;
}

