/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/18/2015
** Description: This program takes two integer numbers and 
**     then adds all integers between them.
***********************************************************/

#include <iostream>

using namespace std;

int main()
{
	// Variables
	int userNum1,		// User numbers
		userNum2,
		highBound,		// Defined after deciding what is high and low
		lowBound,
		loopNum,			// Keeping track of the number we are on in the loop
		tempNum = 0,		// Flag for both numbers being the same
		totalSum = 0;		// Total sum between digits		


	// Brief description of the program
	cout << "Welcome to the Range Sum Program!" << endl;
	cout << "This program will take the sum of all integers between user's entered 2 integer.\n";
	
	// User enters first number to be stored
	cout << "Please enter the first integer: ";
	cin >> userNum1;
	// User enters second number to be stored
	cout << "\nPlease enter the second number: ";
	cin >> userNum2;

	// find out which is highest and lowest bound numbers
	if (userNum1 > userNum2) 
	{
		highBound = userNum1;
		totalSum = loopNum = lowBound = userNum2;
	}
	else if (userNum1 < userNum2)
	{
		totalSum = loopNum = lowBound = userNum1;
		highBound = userNum2;
	}
	else
	{
		highBound = lowBound = userNum1;
		tempNum = 1;
	}

	// Loop to add numbers between the lowest and highest numbers
	if (tempNum != 1)
	{
		do
		{
			loopNum += 1;
			totalSum += loopNum;
		} while (loopNum < highBound);

		// Output the numbers low, high, and total
		cout << "Your lowest number is: " << lowBound << endl;
		cout << "Your highest number is: " << highBound << endl;
		cout << "The total Sum between two numbers is: " << totalSum;
	}
	// Output for when the numbers are the same.
	else
	{
		cout << "You entered the same numbers, so the total sum is: " << totalSum << endl;
	}

	// Exit the program
	return 0;
}
