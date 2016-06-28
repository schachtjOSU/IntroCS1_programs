/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/18/2015
** Description: This program will ask the user how many 
**     numbers they would like to enter.  The program will 
**     have the user enter in that many values.  After all 
**     numbers have been entered, the program will display 
**     the smallest and largest of those numbers.
***********************************************************/

#include <iostream>

using namespace std;

int main()
{
	// Variables
	int userIteration,		// Number of iterations for user to enter in values
		iteration = 1;

	double userNumber,		// User entered value
		highNum,			// Highest number
		lowNum;				// Lowest number

	// Brief Introduction to the program
	cout << "Welecome to the Maximum/Minumum Program!" << endl;
	cout << "This program will display the highest and lowest values entered by the user.\n";

	// User is asked to enter how many numbers to be put in
	cout << "How many values would you like to enter: ";
	cin >> userIteration;

	// Conditional if zero numbers are to be entered or negative number.  Output
	if (userIteration <= 0)
	{
		cout << "\nYou have decided to enter 0 or less numbers in the program.\n"
			<< "This program will now exit.";
	}
	// Conditional if one number is to be entered.  Output.
	else if (userIteration == 1)
	{
		cout << "\nWhat is the number you would like to enter: ";
		cin >> userNumber;
		cout << "\nThe highest and lowest number is: " << userNumber;
	}
	// Conditional if more than one number is to be entered
	else
	{
		// Ask the user for the number and store it as the highest before entry.
		cout << "\nWhat is the number you would like to enter: ";
		cin >> highNum;
		lowNum = highNum;
		
		// Loop starts while true until reached the value of numbers to be entered.
		do
		{
			// Ask user for the next number and store it.
			cout << "\nWhat is the number you would like to enter: ";
			cin >> userNumber;
			
			// Conditional inside loop to ask if number entered is the lowest or highest.
			if (userNumber > highNum)
				highNum = userNumber;
			if (userNumber < lowNum)
				lowNum = userNumber;
			iteration += 1;
		} while (iteration < userIteration);
		
		// Output the highest and lowest numbers.
		cout << "\nThe lowest number you entered is: " << lowNum;
		cout << "\nThe highest number you entered is: " << highNum;
	}


	// Exit program
	return 0;
}