/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/26/2015
** Description: This program will read a positive integer 
**     from the user, passed as a parameter to a boolean 
**     function, then the function will return true or false 
**     to whether the number was a prime number.
***********************************************************/

#include <iostream>
#include <math.h>

using namespace std;

// Boolean function to return if number is prime
// Reference: Part of this code taken from 'C - determine if a number is prime'
// www.http://stackoverflow.com/questions/1538644/c-determine-if-a-number-is-prime
// Date: January 27, 2015
bool primeDecision(int num)
{
	if (num == 1)
		return false;
	for (int n = 2; n < num; n++)
	{
		if (num % n == 0 && n != num)
			return false;
	}
	return true;
}


int main()
{
	// Set variables
	int num;			// Number entered by user
	bool decision;

	// Brief program description
	cout << "Welcome to is prime program!" << endl;
	cout << "\nThis program will take a positive integer and decide wheter the number is prime.";

	// Ask for the number
	cout << "\nWhat is the number: ";
	cin >> num;

	// Boolean function here
	decision = primeDecision(num);

	// Conditionals for output when boolean is true or false
	// If true, output number is prime.
	if (decision)
		cout << "\nYour number " << num << " is a prime number." << endl;
	// If false, output number is not prime.
	else
		cout << "\nYour number " << num << " is not a prime number." << endl;

	// Exit program
	cout << endl;
	return 0;
}