/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/24/2015
** Description: This program will ask the user for three 
**     numbers and will print out the original order.  Then, 
**     assigning those values as pointers, will pass to a 
**     function and sort the values in acsending order.
***********************************************************/
#include <iostream>

using namespace std;

/***********************************************************
**  Description: Sorts the pointers into acsending order and prints to display
**  Parameters: 3 integer pointers
************************************************************/
void sortNums(int *num1, int *num2, int *num3)
{
	// Set variables
	int temp;

	// Sort the numbers
	if (*num1 > *num3)
	{
		temp = *num3;
		*num3 = *num1;
		*num1 = temp;
	}
	if (*num2 > *num3)
	{
		temp = *num3;
		*num3 = *num2;
		*num2 = temp;
	}
	if (*num1 > *num2)
	{
		temp = *num2;
		*num2 = *num1;
		*num1 = temp;
	}

	// Output the sorted order
	cout << "\n\nSorted Order:" << endl;
	cout << *num1 << endl;
	cout << *num2 << endl;
	cout << *num3 << endl;
}


/***********************************************************
**  Description: Main to start program and ask for 3 values from user.
**  Parameters: None
************************************************************/
int main()
{
	// Set variables
	int *num1,			// 3 pointers to have address of values
		*num2,
		*num3;
	int userNum1,		// User entered numbers
		userNum2,
		userNum3;

	// Brief Program Title
	cout << "Welcome to the Small Sort 2 Program!" << endl << endl;

	// Ask the user for the 3 numbers
	cout << "Please enter an integer: ";
	cin >> userNum1;
	cout << "\nPlease enter the second integer: ";
	cin >> userNum2;
	cout << "\nPlease enter the final integer: ";
	cin >> userNum3;

	// Assign the addresses of the numbers to the pointers
	num1 = &userNum1;
	num2 = &userNum2;
	num3 = &userNum3;

	// Print out the Original order
	cout << "\n\nOriginal Order:" << endl;
	cout << *num1 << endl;
	cout << *num2 << endl;
	cout << *num3 << endl;

	// Call the sort function
	sortNums(&userNum1, &userNum2, &userNum3);

	// Exit Program
	return 0;
}