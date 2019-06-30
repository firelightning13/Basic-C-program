#include <stdio.h>
#include <string.h>

int main()
{
	char words[30], rep, sub;
	int i;
	
	printf("Enter a sentence: ");
	gets(words); //input words[]
	
	printf("Enter a character to be replaced: ");
	rep = getchar(); // what character to be replaced
	
	fflush(stdin);
	
	printf("Enter a character to substitute: ");
	sub = getchar(); // what character to substitute
	
	for (i=0;i<30; i++) //run a loop to check every single character in words[]
	{
		if (words[i] == rep) // if a character words[i] is same as rep, replace it with sub 
			words[i] = sub;
	}
	
	printf("After replaced: %s\n", words); //print the result
	
	system ("pause");
	return 0;
}

