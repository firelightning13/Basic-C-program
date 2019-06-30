#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char sentence[100];
	int i, vow=0, con=0;
	
	printf("Enter your sentence: ");
	gets(sentence); //input sentence[]
	
	for (i=0; i<strlen(sentence); i++) //run a loop to check every single character in sentence[]
	{
		switch(tolower(sentence[i])) //switch case to detect vowels and consonants (first, convert letters to lowercase for easy coding)
		{ //we can use if-else, but the code will be lengthy
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': vow++; break; //if detects vowel, count vow++
			case ' ': break; //if detects spaces, don't count anything
			default: con++; //if detects consonant, count con++
		}
		
		// we can use strlwr or strupr, but it changes the "whole" sentence to lower or upper case simultaneously,
		// which what not the question wants
		
		if (islower(sentence[i])==0) // if a character is upper case, convert it to lower case
			sentence[i] = tolower(sentence[i]);
		else if (isupper(sentence[i])==0) // if a character is lower case, convert it to upper case
			sentence[i] = toupper(sentence[i]);
	}
	
	// print number of vowels and consonants and the conversion
	printf("Number of vowels: %d\n", vow);
	printf("Number of consonants: %d\n", con);
	printf("After conversion: %s\n", sentence);
	
	system ("pause");
	return 0;
}

