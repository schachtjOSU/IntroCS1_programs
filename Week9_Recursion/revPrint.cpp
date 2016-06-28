/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 03/03/2015
** Description: This program will ask the user how many 
**     integers to be entered, ask the user for those 
**     integers, and then prints out the integers in 
**     reverse order.
***********************************************************/
#include <iostream>

using namespace std;

/***********************************************************
**  Description: Recursive function to print out the elements in reverse order.
**  Parameters: Array of integers, and integer of size of the array.
************************************************************/
int reverseArray(int *arrInts, int size)
{
	// Base condition
	if (size < 0)
	{
		return 0;
	}
	// Condition if size is not 0 yet
	else
	{
		cout << endl << arrInts[size];
		reverseArray(arrInts, --size);
	}
}

/***********************************************************
**  Description: Main function to ask number of elements and to fill array with values.  
                    Pass to reverseArray fucntion.
**  Parameters: None
************************************************************/
int main()
{
	// Set variables
	int size;			// size of array
	int *arrInts;		// Pointer to array
	int recurSize;		// Temp for size of array

	// Brief program Title
	cout << "Welcom to the Reverse Print Program" << endl << endl;

	// Ask the user for number of integers
	cout << "Enter the number of integers to print: ";
	cin >> size;

	// Create Dynamic array here
	arrInts = new int[size];
	
	// Loop to enter all integers
	for (int i = 0; i < size; i++)
	{
		cout << "\nEnter an integer for the element " << i << ": ";
		cin >> arrInts[i];
	}

	// Start recursive function
	recurSize = size;
	reverseArray(arrInts, --recurSize);
	cout << endl;

	// Delete dynamic array here
	delete[] arrInts;
	arrInts = 0;
     system("pause");
	// Exit program
	return 0;
}