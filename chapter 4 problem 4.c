#include<stdio.h>
#define TICKETPRICE 15
#define DISCOUNTRATE 0.05

int number_tickets; 
float total_price, discount, nett_pay,n,i,k;
float TicketPay(int);
void Capture(void);
void Greeting(void);
void Display (void);
float CalcDiscount (float);
float CalcNetPay(float, float);

int main ()
{
	
	Greeting();
	
	Capture();//function call for capture
	
	Display ();
	system ("pause");

	return 0;
}

void Greeting(void)
{
	printf("~~Welcome to CFS Ticketing System~~\n");
}

void Capture(void)
{

	printf("Enter number of tickets: ");
	scanf("%d", &number_tickets);
	n=TicketPay(number_tickets);//t is the number of tickets
	i=CalcDiscount(n);//calcdiscount n is the total price
	k=CalcNetPay(n,i); // sebab dia nak total price dengan discount value so n=total price, i=discount
}

float TicketPay(int m)
{
	
	total_price = TICKETPRICE*m;//m is number of ticket
	return total_price;
	
}

float CalcDiscount(float r)
{
	
	discount= r * DISCOUNTRATE;
	
	return discount;// pegi balik kat function call pastu i jadi discount
}

float CalcNetPay(float b, float c)
{
	
	nett_pay = b-c;
	
	return nett_pay; 
	
}

void Display(void)
{
	printf("PAYMENT INFORMATION\n");
	
	printf("Number of tickets: %d\n",number_tickets );
	printf("Total price: %.2f\n",n);
	printf("Discount: %.2f\n" ,i);
	printf("Nett pay: %.2f\n",k);
	
}	
	










