/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 03/03/2015
** Description: This program will ask the user how many 
**     numbers of double type to be entered, ask the user 
**     for those numbers, and then add them up in a 
**     recursive function.
***********************************************************/
#include <iostream>

using namespace std;

/***********************************************************
**  Description: Recursive function to sum values
**  Parameters: Array of double type numbers, and integer of size of the array.
************************************************************/
double recurseSum(double *arryDoubl, int size)
{
	// Pre-modify size
	--size;

	// Base Case
	if (size < 0)
		return 0;
	
	// Keep summing to result with recursive functioning
	if (size > 0)
	{
		return arryDoubl[size] + recurseSum(arryDoubl, size);
	}
	else
	{
		return arryDoubl[size];
		
	}
}

/***********************************************************
**  Description: Main function to ask number of elements and to fill array with values.
Pass to recurseSum fucntion.
**  Parameters: None
************************************************************/
int main()
{
	// Set variables
	int size;			// size of array
	double *arrDoubs;		// Pointer to array
	int recurSize;		// Temp for size of array
	double numSum;		// Total of the sum of all numbers

	// Brief program Title
	cout << "Welcome to the Recursive Summing Program!" << endl << endl;

	// Ask the user for number of numbers
	cout << "Enter the number of numbers to be summed: ";
	cin >> size;

	// Create Dynamic array here
	arrDoubs = new double[size];

	// Loop to enter all double type numbers
	for (int i = 0; i < size; i++)
	{
		cout << "\nEnter a number for the element " << i << ": ";
		cin >> arrDoubs[i];
	}

	// Start recursive function
	recurSize = size;
	numSum = recurseSum(arrDoubs, recurSize);
	cout << endl << "Total Sum of all numbers is: " << numSum << endl;

	// Delete dynamic array here
	delete[] arrDoubs;
	arrDoubs = 0;

	// Exit program
	return 0;
}