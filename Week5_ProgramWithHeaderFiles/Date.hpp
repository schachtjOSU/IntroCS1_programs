/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/07/2015
** Description: This program will be using classes to ask
**     the user the month, day and year.  The user will be 
**     able to select which format within a loop until 
**     she/he decides to quit the program.
***********************************************************/


#include <iostream>

using namespace std;

class Date
{
private:
	// Data members
	int month,
		day,
		year;


public:
	// Default constructor
	Date();

	// Constructor taking 3 parameter
	Date(int, int, int);

	// Methods to set the month, day and year.
	void setMonth(int);
	void setDay(int);
	void setYear(int);

	// Methods for the different print options
	void print1();
	void print2();
	void print3();


};