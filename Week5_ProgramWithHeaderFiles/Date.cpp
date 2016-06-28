/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/07/2015
** Description: This program will be using classes to ask
**     the user the month, day and year.  The user will be
**     able to select which format within a loop until
**     she/he decides to quit the program.
***********************************************************/


#include <iostream>
#include "Date.hpp"
#include <string>


using namespace std;

// Default constructor
Date::Date()
{
	setMonth(1);
	setDay(1);
	setYear(2001);
}

// Constructor taking 3 arguments
Date::Date(int monthDate, int dayDate, int yearDate)
{
	setMonth(monthDate);
	setDay(dayDate);
	setYear(yearDate);
}


// For the 3 set methods
void Date::setMonth(int monthDate)
{
	month = monthDate;
}

void Date::setDay(int dayDate)
{
	day = dayDate;
}

void Date::setYear(int yearDate)
{
	year = yearDate;
}


// For the 3 print options
void Date::print1()
{
	int shortenYear;

	shortenYear = year - 2000;

	cout << "\nYour date is: " << month << "/" << day
		<< "/" << shortenYear << endl;
	cout << "__________________________________________\n";
}

void Date::print2()
{
	string newMonth = "";

	switch (month)
	{
	case 1:
		newMonth = "January";
		break;
	case 2:
		newMonth = "February";
		break;
	case 3:
		newMonth = "March";
		break;
	case 4:
		newMonth = "April";
		break;
	case 5:
		newMonth = "May";
		break;
	case 6:
		newMonth = "June";
		break;
	case 7:
		newMonth = "July";
		break;
	case 8:
		newMonth = "August";
		break;
	case 9:
		newMonth = "September";
		break;
	case 10:
		newMonth = "October";
		break;
	case 11:
		newMonth = "November";
		break;
	case 12:
		newMonth = "December";
		break;
	default:
		newMonth = "Unknown Month";
		break;
	}

	// Print option 2
	cout << "\nYour date is: " << newMonth << " "
		<< day << ", " << year << endl;
	cout << "__________________________________________\n";
}

void Date::print3()
{
	string newMonth = "";

	switch (month)
	{
	case 1:
		newMonth = "January";
		break;
	case 2:
		newMonth = "February";
		break;
	case 3:
		newMonth = "March";
		break;
	case 4:
		newMonth = "April";
		break;
	case 5:
		newMonth = "May";
		break;
	case 6:
		newMonth = "June";
		break;
	case 7:
		newMonth = "July";
		break;
	case 8:
		newMonth = "August";
		break;
	case 9:
		newMonth = "September";
		break;
	case 10:
		newMonth = "October";
		break;
	case 11:
		newMonth = "November";
		break;
	case 12:
		newMonth = "December";
		break;
	default:
		newMonth = "Unknown Month";
		break;
	}

	// Print Option 3
	cout << "\nYour date is: " << day << " " << newMonth
		<< " " << year << endl;
	cout << "__________________________________________\n";
}

int main()
{
	// Variables
	int monthDate,
		dayDate,
		yearDate;

	bool leapYear = false;		// Check if leap year
	string loopExit = "";
	string option = "";

	// Brief Description of Program
	cout << "Welcome to the Date Program." << endl;
	cout << "\nThis program will take your month, day and year"
		<< "\n then output into different print options.\n";

	// Ask the user for month, day and year
	cout << "\nPlease enter the month as integer: ";
	cin >> monthDate;
	cout << "\nPlease enter the day as an integer: ";
	cin >> dayDate;
	cout << "\nPlease enter the year as integer: ";
	cin >> yearDate;

	// Conditionals for checking date
	// Is it a leap year
	if (yearDate % 100 == 0)
	{
		leapYear = true;
		cout << "\nThis is a leap year\n";
	}
		
	else if (yearDate % 4 == 0)
	{
		leapYear = true;
		cout << "\nThis is a leap year\n";
	}
	else
	{
		cout << "\nNot a leap year\n";
	}
	
	// Validate month
	if ((monthDate < 1) || (monthDate > 12))
	{
		cout << "\nError: The month set is not valid"
			<< "\nSetting month to 0";
		monthDate = 0;
	}
	
	// Validate days
	if ((monthDate == 1) || (monthDate == 3) || (monthDate == 5) || (monthDate == 7) || (monthDate == 8) || (monthDate == 10) || (monthDate == 12))
	{
		if ((dayDate < 1) || (dayDate > 31))
		{
			cout << "\nError: The day set is not valid"
				<< "\nSetting day to 0";
			dayDate = 0;
		}
	}
	else if ((monthDate == 4) || (monthDate == 6) || (monthDate == 9) || (monthDate == 11))
	{
		if ((dayDate < 1) || (dayDate > 30))
		{
			cout << "\nError: The day set is not valid"
				<< "\nSetting day to 0";
			dayDate = 0;
		}
	}
	
	// Validate the month of February date and leap year
	else
	{
		if (leapYear == true)
		{
			if ((dayDate < 1) || (dayDate > 29))
			{
				cout << "\nError: The day set is not valid"
					<< "\nSetting day to 0";
				dayDate = 0;
			}
		}
		else if (leapYear == false)
		{
			if ((dayDate < 1) || (dayDate > 28))
			{
				cout << "\nError: The day set is not valid"
					<< "\nSetting day to 0";
				dayDate = 0;
			}
		}
	}
	
	// Send values to constructor
	Date date(monthDate, dayDate, yearDate);

	// Start a loop, to go through print options until user quits
	do
	{
		// Print menu
		cout << "*********************************************************";
		cout << "\nPrint Option Menu!\n";
		cout << "\nEnter the option number below to format print of date "
			<< "\nOR type quit to exit program.\n";
		cout << "\nOption 1: Month/Day/Year (e.g. 3/15/13)" << endl;
		cout << "\nOption 2: Month Day, Year (e.g. March 15, 2013)" << endl;
		cout << "\nOption 3: Day Month Year (e.g. 15 March 2013)" << endl;
		cout << "\nYour selection: ";
		cin >> option;
		if (option == "1")
			date.print1();
		else if (option == "2")
			date.print2();
		else if (option == "3")
			date.print3();
		else if (option == "quit")
			loopExit = option;
		else
			cout << "\nError: Invalid entry.  Try Again!\n";

	} while (loopExit != "quit");


	// Exit Program
	return 0;
}