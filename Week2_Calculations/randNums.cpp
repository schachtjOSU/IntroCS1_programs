/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/12/2015
** Description: This program asks the user for an upper 
**     bound and a lower bound (both integers).  Then it will
**     output 5 random numbers between the bounds.
***********************************************************/

#include <iostream>
#include <cstdlib>		// Header file used for rand
using namespace std;

int main()
{
	// Store variables
	int highNum,		// upper bound number
		lowNum,			// lower bound number
		number;			// random number generated

	// Describe briefly program to user
	cout << "This  program will ask you for a high integer and "
		<< "low integer, then generate 5 random numbers\n";
	// User enters numbers
	cout << "Please enter a high integer: ";
	cin >> highNum;
	cout << "\nPlease enter a low integer: ";
	cin >> lowNum;

	// Random numbers generated with user specified limited range
	number = rand() % highNum + lowNum;
	cout << "\nYour first number is: " << number;
	number = rand() % highNum + lowNum;
	cout << "\nYour second number is: " << number;
	number = rand() % highNum + lowNum;
	cout << "\nYour third number is: " << number;
	number = rand() % highNum + lowNum;
	cout << "\nYour fourth number is: " << number;
	number = rand() % highNum + lowNum;
	cout << "\nYour fifth number is: " << number;


	// Exit program
	return 0;
}