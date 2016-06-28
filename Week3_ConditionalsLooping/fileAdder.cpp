/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/20/2015
** Description: This program will read an input 
**     file(nums.txt) with double value integers and add 
**     all the integers together into a total variable.  
**     The total variable will written into an output 
**     fiel(sum.txt)
***********************************************************/

#include <iostream>
#include <fstream>		// for file operations

using namespace std;

int main()
{
	// Varaibles
	ifstream inputFile;		// input file
	ofstream outputFile;	// output file
	double totalSum = 0.0;		// total sum from nums.txt
	double nums;			// values input to this variable


	// Attempt to open input file for reading
	inputFile.open("nums.txt");

	// Conditional for if the inputFile opened successfully
	if (inputFile)
	{
		// Loop until the EOF is reached
		while (inputFile >> nums)
		{
			// Read line from file into nums and add to totalSum
			// inputFile >> nums;
			totalSum += nums;
		}

		// Code for opening output file for writing
		outputFile.open("sum.txt");

		// Conditional to make sure output file opens correctly.
		if (outputFile)
		{
			// Write to the sums.txt file
			outputFile << "The sum of the values is " << totalSum << "." << endl;

			// Close the output file
			outputFile.close();
		}
		// Error message when sum.txt is unable to open
		else
		{
			cout << "Error opening the sum.txt file.\n";

			// Exit program
			return 0;
		}

		// Close the input file
		inputFile.close();
	}
	else
	{
		// Error message when program has trouble opening input file
		cout << "Error opening the nums.txt file.\n";
		
		// Exit program
		return 0;
	}
        // Output saying file has been processed
        cout << "Output file sum.txt has been created.\n";	
	// Exit program
	return 0;

}
