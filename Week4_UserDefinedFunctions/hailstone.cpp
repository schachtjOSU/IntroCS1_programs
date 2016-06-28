/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/28/2015
** Description: This program will read an integer from the 
**     user, then start the hailstone sequence.  The hailstone 
**     sequence goes through to conditional steps until the 
**     number is wittled down to the number 1.  The conditional 
**     steps include if that integer is even, then you divide 
**     it by two to get the next integer in the sequence, but 
**     if it is odd, then you multiply it by three and add one 
**     to get the next integer in the sequence.  For each 
**     conditional step, the number of sequences is counted and 
**     that sequence will be displayed for the user.
***********************************************************/

#include <iostream>

using namespace std;

// Find sequence function
int findSequence(int number)
{
	// Set variables
	int i;

	// Start a loop, 'i' will be the hailstone sequence count
	for (i = 0; number != 1; ++i)
	{
		if (number % 2 == 0)
			number = number / 2;
		else
			number = (3 * number) + 1;
		cout << number << "\n";
	}

	// Return Sequence
	return i;
}

// Main function
int main()
{
	// Set variables
	int number,		// User input variable
		sequence;	// Returned value of sequence number

	// Briefly describe program
	cout << "Welcome to the Hailstone Program!\n";
	cout << "\nThis program will take an integer number and calculate the hailstone"
		<< "\nsequence until your number reaches 1.  For each number, the hailstone"
		<< "\nsequence will either divide the even number by 2, or for odd numbers,"
		<< "\n multiply them by 3 and add 1.  Your sequence number will display at the end.\n";

	// User inputs number
	cout << "\nPlease enter a positive integer: ";
	cin >> number;

	// Hailstone function
	sequence = findSequence(number);

	// Output hailstone sequence number.
	cout << "\nYour hailstone sequence is " << sequence << ".\n";

	// Exit program
	return 0;
}