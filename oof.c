#include <stdio.h>
#include <string.h>
#define MAX_SIZE 200

void delAll(char * str, char * todelete);

int main()
{
	int i;
	char str[MAX_SIZE], del[MAX_SIZE];
	////COPY DALAM IF CHOICE == 3////
	printf("Enter a sentence: \n");
	gets(str);
	printf("Enter a word to delete: \n");
	gets(del);
	
	delAll(str,del);
	
	printf("\nThe result is: \n");
	puts(str);
	///////////////////////////////////
	system ("pause");
	return 0;
}

// REPLACE VOID delAll ////////////
void delAll(char * str, char * todelete)
{
	char *token, tmp[100][MAX_SIZE];
	int i=0, len=0;
	
	token= strtok(str," ");
	if(strcmp(token, todelete) != 0)
	{
		strcpy(tmp[0],token);
	}
	
	while (token != NULL)
	{
		if(strcmp(token, todelete) != 0)
		{
			
			strcpy(tmp[i],token);
			i++;
		}
		token = strtok(NULL, " ");
	}

	len=i;
	strcpy(str, tmp[0]);
	for (i=1; i<len; i++)
	{
		strcat(str, " ");
		strcat(str, tmp[i]);
	}
}
///REPLACE SAMPAI SINI///////////
