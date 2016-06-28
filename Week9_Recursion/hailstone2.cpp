/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 03/04/2015
** Description: This program will read an integer from the
**     user, then start the hailstone sequence.  The hailstone
**     sequence goes through conditional steps until the
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

/***********************************************************
**  Description: Calculates the Hailstone sequence as described above
**  Parameters: Takes in an integer number.
************************************************************/
int findSequence(int number, int sequence)
{
	// Base case
	if (number == 1)
	{
		return sequence;
	}
	if (number % 2 == 0)
	{
		return findSequence((number/2), ++sequence);
	}
	else if (number % 2 != 0)
	{
		return findSequence(((3 * number) + 1), ++sequence);
	}

}


/***********************************************************
**  Description: Main function to ask a positive integer and send it through a hailstone
**                    sequence through recursive function.
**  Parameters: None
************************************************************/
int main()
{
	// Set variables
	int number,		// User input variable
		sequence = 0;	// Returned value of sequence number

	// Briefly describe program
	cout << "Welcome to the Hailstone Program!\n";

	// User inputs number
	cout << "\nPlease enter a positive integer: ";
	cin >> number;

	// Hailstone function
	sequence = findSequence(number, sequence);

	// Output hailstone sequence number.
	cout << "\nYour hailstone sequence is " << sequence << ".\n";

	// Exit program
	return 0;
}
