#include <stdio.h>
#include <string.h>

int main()
{
	char word[12], rev[12];
	
	printf("Enter a word: ");
	gets(word); //input word[]
	
	strcpy(rev, word); //copy from word[] to rev[]
	strrev(rev); //reverse the rev[]
	
	printf("Reversed word: %s\n", rev); //shows rev[] words
	
	if (strcmpi(word, rev) == 0) //compare word[] to rev[] if it is same or not
		printf("It's a palindrome word!\n");
	else
		printf("It's not a palindrome word!\n");
	
	system ("pause");
	return 0;
}

