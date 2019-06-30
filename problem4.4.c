#include <stdio.h>
#define TICKET_PRICE 15 //fixed ticket price
#define DISCOUNT_RATE 0.05 //fixed discount rate

void Capture(int), Display(void); //function prototype, no return value
float TicketPay(int), CalcDiscount(float), CalcNetPay(float, float); //funtion prototype, return value
float total_price, discount_price, net_price; //defined in global so it's easy to display
int no_tickets; //defined in global so it's easy to display

int main()
{	
	do //do-while loop, to capture more than one customer
	{  //but you can exit by type "-1"
		printf("~~Welcome To CFS Ticketing System~~\n");
		printf("Enter number of tickets: ");
		scanf("%d", &no_tickets); //input number of tickets
		
		if (no_tickets != -1)
		{
			Capture(no_tickets); //call function, let Capture() do the work
			Display(); //display all information
			
			system("pause");
			system("cls"); //clear screen, for ui-friendly-ness
		}
	} while (no_tickets != -1); //if there is no customer, exit the program
								//else repeat again for another customer
	
	system ("pause");
	return 0;
}

void Display() //function to display info, no return value
{
	printf("\nPAYMENT INFORMATION\n");
	printf("Number of Tickets: %d\n", no_tickets);
	printf("Total price: RM%.2f\n", total_price);
	printf("Discount: RM%.2f\n", discount_price);
	printf("Nett pay: RM%.2f\n", net_price);
}

void Capture(int tickets) //function to do some calculation; "tickets" is "no_tickets" from main(), no return value
{
	total_price = TicketPay(tickets); //pass the value to TicketPay(), to calculate total price
	discount_price = CalcDiscount(total_price); //same as above, do i need to explain again
	net_price = CalcNetPay(total_price, discount_price); //pass two values into CalcNetPay(), to calculate net price
}

float TicketPay(int tickets) //function to calculate total price;
{							 //"tickets" is "tickets" from Capture() (i used the same variable, oops)
	float total;
	total = tickets * TICKET_PRICE;
	return total; //return the value "total_price" back to Capture() 
}

float CalcDiscount(float total) //function to calculate discount price;
{								//"total" is "total_price" from Capture()
	float discount;
	discount = total * DISCOUNT_RATE;
	return discount; //return the value "discount_value" back to Capture()
}

float CalcNetPay(float total, float discount) //function to calculate net price;
{											  //"total" and "discount" is "total_price" and "discount_price"
	float net;								  //respectively from Capture() 
	net = total - discount;
	return net; //return the value "net_price" back to Capture()
}


