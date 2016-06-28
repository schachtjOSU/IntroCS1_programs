/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 03/04/2015
** Description: This program will ask the user to decide 
**     whether they would like to convert a binary number 
**     to decimal format or a decimal into binary.  This 
**     program will use recursive function to display the 
**     number in the format choice of the user.
***********************************************************/
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/***********************************************************
**  Description: Converts number into a binary array
**  Parameters: Integer number
************************************************************/
int convertToBinary(int number, int *binArray, int size)
{
	int remainder = 0;		// Remainder
	int result = 0;			// Result of division

	// Base case
	if (number == 0)
		return binArray[size];
	
	// Other cases
	else
	{
		++size;						// Increase the size of the array
		remainder = number % 2;		// Find remainder
		number = number / 2;		// Divide the number by two.
		if (remainder == 1)
		{
			binArray[size] = remainder;
			return binArray[size] + convertToBinary(++number, binArray, size);
		}
		else
		{
			binArray[size] = remainder;
			return binArray[size] + convertToBinary(number, binArray, size);
		}
	}
}


/***********************************************************
**  Description: Converts binary array into a number
**  Parameters: Integer dynamic number array
************************************************************/
int convertToDecimal(int *number, int size, int value)
{
	// Base case
	if (size < 0)
		return value;
	// Beyond the base case
	if (size >= 0)
	{
		// If binary is set to 1
		if (number[size] == 1)
		{
			return value + (pow(2, size)) + convertToDecimal(number, --size, value);
		}
		// If binary is set to 0
		else
			return value + convertToDecimal(number, --size, value);
	}
}


/***********************************************************
**  Description: Main function, with user to choose menu, input validation, send
**                    data to recursive functions, and output result.
**  Parameters: None
************************************************************/
int main()
{
	// Set variables
	bool exit = false;		// Flag to exit the program
	int menuOpt;			// Menu Option
	string userDec;			// User entered decimal
	char *chArrDec;		// Take the string and put it into a char array
	int sizeDec;			// Size of Decimal array plus new line
	int numDec;				// User Decimal
	int *resultBin = 0;			// Binary array from 
	string userBin;			// User enters binary array
	int *chArrBin;
	int sizeBin;
	int resultDec = 0;
	

	// Brief Descpriptive title
	cout << "Welecome to the Binary and Decimal Conversion Program!" << endl << endl;

	// Start Loop for user selection until quit
	do
	{
		// Loop variables
		bool invalidIn = false;   // For valid input
		int sizeToBin = -1;			// Counter for recursive funciton to convert to Binary
		
		// Display Menu
		cout << "Menu Options" << endl;
		cout << "1) Convert a binary string to a decimal number." << endl;
		cout << "2) Convert a decimal number into a binary string." << endl;
		cout << "3) Exit the program." << endl << endl;

		// Get user selection
		cout << "Enter the number from the menu options above here: ";
		cin >> menuOpt;

		// Switch cases for each option
		switch (menuOpt)
		{
		case 1:
		{
			// Ask the user for a positive integer in a binary representation.
			cout << "\nEnter your binary number here: ";
			getline(cin, userBin);
			sizeBin = userBin.length();
			chArrBin = new int[sizeBin];

			// If binary input is valid
			for (int k = 0; k < sizeBin; k++)
			{
				chArrBin[k] = userBin[k];
				if (userBin[k] == 0 || userBin[k] == 1)
				{
					continue;
				}
				else
					invalidIn = true;
			}

			// If binary input is valid
			if (invalidIn == false)
			{
				resultDec = convertToDecimal(chArrBin, sizeBin, resultDec);
			}
			else
				cout << "\nThere has been an invalid input.  Please Try Again!" << endl << endl;

			// Remove dynamic memory
			delete chArrBin;
			chArrBin = 0;

			// Break out of the switch and continue main loop
			break;
		}
		case 2:
		{
			// Ask the user for a positive integer in a decimal representation.
			cout << "\nEnter a positive integer here: ";
			getline(cin, userDec);
			sizeDec = userDec.length();
			chArrDec = new char[sizeDec];
			
			// Input validation
			for (int i = 0; i < sizeDec; i++)
			{
				chArrDec[i] = userDec[i];
				if (chArrDec[i] > 47 && chArrDec[i] < 58)
					continue;
				else if (chArrDec[i] == '\n')
					continue;
				else
				{
					invalidIn = true;
				}
			}

			// If decimal input is valid
			if (invalidIn == false)
			{
				// Convert to Integer
				numDec = atoi(chArrDec);

				// Recursive function to convert to binary
				*resultBin = convertToBinary(numDec, resultBin, sizeToBin);
			}
			// Else if bad input
			else
			{
				cout << "\nThere has been an invalid input.  Please Try Again!" << endl << endl;
			}

			// Delete array
			delete chArrDec;
			chArrDec = 0;

			// Break out of the switch and continue main loop
			break;
		}
		case 3:
		{
			exit = true;
			// Break out of the switch.
			break;
		}
		default:
		{
			cout << "Number entered doesn't not match.  Please Try Again!" << endl << endl;
			break;
		}
		}
	} while (!exit);

	// Exit Program
	system("pause");
	return 0;
}