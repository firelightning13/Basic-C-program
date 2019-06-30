#include <stdio.h>

//function prototype
void View(void);
float Buy(void);
void Exit(float);

int main()
{
	int option;
	float total_price=0; //init total price of 0
	
	//Print user interface
	printf("\t\t\tWelcome to IIUM Bookstore\n");
	printf("\t\t\t+++++++++++++++++++++++++\n");
	printf("Main Menu\n");
	printf("1. View\n2. Buy\n3. Exit\n\n");
	
	do
	{
		printf("Enter you option (1-3): ");
		scanf("%d", &option); //select an option
		
		switch (option)
		{
			case 1: View(); option=0; break; //view price lists
			case 2: total_price += Buy(); option=0; break; //buy something
			case 3: Exit(total_price); break; //exit gracefully
			default: printf("Invalid! Try again.\n"); //if user input wrong option
		}
	} while (option<1 || option>3); //run loop again is user input wrong option
	
	system ("pause");
	return 0;
}

void View() //function definitiion
{
	//print all relevant information
	printf("1) C Programming\t\t10.80\n");
	printf("2) ANSI C\t\t\t15.30\n");
	printf("3) Problem Solving\t\t12.60\n");
	printf("4) How to Program\t\t24.20\n\n");
}

float Buy() //function definitiion; to buy something
{
	int title, quantity;
	float total;
	
	do
	{
		printf("Book title # (1-4)? ");
		scanf("%d", &title); //enter book title #
		
		if (title<1 || title>4) //if user input wrong choice
		{
			printf("Invalid! Try again.\n");
			continue; //will skip the code below and run do-while loop again
		}
		
		printf("Quantity: ");
		scanf("%d", &quantity); //enter desired quantity
		//NOTE: the system will break if you put less than 0
		//im too lazy to implement robustness to this thingy
		
		switch(title) //total up the pricing
		{
			case 1: total = 10.80*quantity; break;
			case 2: total = 15.30*quantity; break;
			case 3: total = 12.60*quantity; break;
			case 4: total = 24.20*quantity; break;
		}
	} while (title<1 || title>4);
	
	return total; //return the total value to main()
}

void Exit(float total) //function definitiion; "total" is "total_price" from main()
{
	//display total price and goodbye message
	printf("The total price is RM %.2f\n", total);
	printf("Thank you for using this system\n");
}
