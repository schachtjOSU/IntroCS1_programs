/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/26/2015
** Description: This program will read in three integers 
**     from the user, print out the original order, sort 
**     the order from lowest to highest with a void 
**     function, then finally printing out the new order.
***********************************************************/

#include <iostream>

using namespace std;

//Void function
void sortNums(int &num1, int &num2, int &num3)
{
	int temp = 0;		// Need a temp integer to swap values around.

	if (num1 > num3)
	{
		temp = num3;
		num3 = num1;
		num1 = temp;
	}
	if (num2 > num3)
	{
		temp = num3;
		num3 = num2;
		num2 = temp;
	}
	if (num1 > num2)
	{
		temp = num2;
		num2 = num1;
		num1 = temp;
	}
}

// Main function
int main()
{
	// List of Variables
	int num1,
		num2,
		num3;			// Numbers
	
	
	// Brief description of the program
	cout << "Welcome to the Small Sort Program!" << endl;
	cout << "This program will take 3 integers and sort from lowest to highest\n";

	// Prompt the user for three values
	cout << "\nWhat is your first number: ";
	cin >> num1;
	cout << "\nWhat is your second number: ";
	cin >> num2;
	cout << "\nWhat is your third number: ";
	cin >> num3;

	// Print out order of the integers
	cout << "\nHere is the original order: " << endl
		<< num1 << endl << num2 << endl << num3 << endl;

	// Void function to sort numbers
	sortNums(num1, num2, num3);

	// Print out the new order of the numbers
	cout << "\nHere is the sorted order: " << endl
		<< num1 << endl << num2 << endl << num3 << endl;

	// Exit program
	cout << endl;
	return 0;
}