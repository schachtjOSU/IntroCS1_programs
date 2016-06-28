/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/25/2015
** Description: This program will ask the user for the number
**     of values to be entered.  The user will enter the 
**     values in and the mode value(s) will be displayed.  
**     To do so will create dynamic allocated memory to 
**     store the array of integers.
***********************************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/***********************************************************
**  Description: Loops through the array to find mode.
**  Parameters: Takes the array of values and size of array value
************************************************************/
void getMode(int *arrVal, int arrSize)
{
	// Set Variables
	int modeTally = 1;		// tally tne current number
	int number = 0;			// Current number
	vector<int> tallyArr;			// Dynamic array for tally
	vector<int> numArr;
	vector<int> mode;
	int tallyNum;
	int tallyElements;
	int modeSize;

	// Sort the array ascending
	sort(arrVal, arrVal + arrSize);

	// Get the first number in array
	number = arrVal[0];
	
	// Loop through elements in array and tally numbers in new arrays
	for (int i = 1; i < arrSize; i++)
	{
		// Tally number of the same numbers
		if (arrVal[i] == number)
		{
			modeTally++;
			continue;
		}
		// Save the numbers and tallys
		else
		{
			tallyArr.push_back(modeTally);
			numArr.push_back(number);
			modeTally = 1;
			number = arrVal[i];
			continue;
		}
	}
	// Add the last number and tally to the array
	tallyArr.push_back(modeTally);
	numArr.push_back(number);

	
	// If size of elements in tally Num is 1, then set the mode and done.
	tallyElements = tallyArr.size();
	if (tallyElements == 1)
	{
		mode.push_back(numArr[0]);
		cout << "I Went here for some reason!!!!!!!!" << endl;
	}
	// Determine which are the mode
	else
	{
		// Get the current
		tallyNum = tallyArr[0];
		mode.push_back(numArr[0]);
		// Loop through the tallys to find which is the greatest
		for (int j = 1; j < tallyElements; j++)
		{
			// Disregard number if the tally is less then the current
			if (tallyArr[j] < tallyNum)
			{
				continue;
			}
			// Found a number that is greater than what is in the array already
			else if (tallyArr[j] > tallyNum)
			{
				mode.clear();
				mode.push_back(numArr[j]);
				tallyNum = tallyArr[j];
			}
			// Number is same as what is already there, add it
			else
			{
				mode.push_back(numArr[j]);
			}
		}
	}

	// Get the mode size
	modeSize = mode.size();

	// Print Mode
	cout << "\n\nThe mode is:";
	for (int k = 0; k < modeSize; k++)
	{
		cout << "  " << mode[k];
	}

	cout << endl;
}

/***********************************************************
**  Description: Main function to ask number of elements and to fill array with values.  Pass to getMode function
**  Parameters: None
************************************************************/
int main()
{
	// Set variables
	int arrSize;		// Size of the array
	int myArray;		// The array of values
	int *arr;			// Pointer to the array

	arr = &myArray;		// Assign the address to pointer

	// Brief Title
	cout << "Welcome to the Find Mode Program" << endl << endl;

	// Ask the user for the size fo the array
	cout << "Enter the number for the size of the list: ";
	cin >> arrSize;
	cout << endl;

	// Create dynamic memory array
	arr = new int[arrSize];

	// Start a loop to have user enter values
	for (int i = 0; i < arrSize; i++)
	{
		cout << "\nEnter a number for the element " << i << ": ";
		cin >> arr[i];
	}

	// Pass array and array size to getMode
	getMode(arr, arrSize);

	// Purge memory
	delete arr;
	arr = 0;

	// Exit program
	system("pause");
	return 0;
}