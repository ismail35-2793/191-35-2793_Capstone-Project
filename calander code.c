#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define TRUE    1 //Define true 1 because of Checking the year is leap-year or not

#define FALSE   0 //Define FALSE 0 because of Checking the leap-year. if it wasn't, then it will be 0 means FALSE

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //Here insert the days of per month
int a,b; //Declare 2 integer type value
char *months[]= //Declare the months
{  //12 months of a year
	" ",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

int inputyear(void) //Year input function
{
	int year;

	printf("\n\t\tPlease enter a year (e.g: 2019): ");
	scanf("%d", &year); //input the year
	return year;
}

int determinedaycode(int year) //Declare day-code on years function
{
	int daycode;
	int d1, d2, d3;
    //Day calculation by using Tomohiko Sakamoto's Algorithm
	d1 = (year - 1)/ 4;
	d2 = (year - 1)/ 100;
	d3 = (year - 1)/ 400;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}

int determineleapyear(int year) // In this function it check the input year is leap-year or not
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE) //Here control statement used for checking leap-year
	{
		days_in_month[2] = 29; //If it's leaper, then 2nd month will be 29 days
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;  //Otherwise 28
		return FALSE;
	}
}

void calendar(int year, int daycode) //Here declare a return type function of calender
{
    //the below is to show the hole calender(year,month,day)

	int month, day; //integer type variable
	system("cls");
	for ( month = a; month <= a+b; month++ ) //looping the increasing of month
	{
	    system("color 7D");   //Selecting the color which color will show on calender

	    printf("\n\n\n   \xB2\xB2\xB2\xB2\xB2\xB2\xB2 %s \xB2\xB2\xB2\xB2\xB2\xB2\xB2",months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu" );
		printf("  Fri  Sat\n");
		for ( day = 1; day <= 1 + daycode * 5; day++ ) //looping the increment of days
		{
			printf(" ");
		}

		for ( day = 1; day <= days_in_month[month]; day++ ) //weekly days of month arrived by this control statement
		{
			printf("%2d", day );

			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			// Set position for next month
			daycode = ( daycode + days_in_month[month] ) % 7;
	}

printf("\n\nPress any key to go main menu\n");
getch();
system("cls");
main();
}


int main(void)
{
    //Declare all the proses and inputs
    char choice;
	int year, daycode, leapyear;
    system("color 3");
    printf("\n\n\n\n\n\n\t\t1.Year\n\t\t2.Month\n\t\tEnter Your Choice");
    choice=getch();
    if(choice=='1')
    {
	year = inputyear();
	a=1;
	b=11;
    }
    else if(choice=='2')
    {
    year = inputyear();
    printf("\nEnter Month\n");
    scanf("%d",&a);
    b=0;
    }
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
printf("\n");
}
