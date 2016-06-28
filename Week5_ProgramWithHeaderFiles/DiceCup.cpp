/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/04/2015
** Description: This program will be using classes to ask
**     the user for the number of dice and the number of
**     faces on each dice.  Then the program will ask the
**     number of rolls of the dice cup and will output
**     each total value of all dice for each roll of the dice.
***********************************************************/

#include <iostream>
#include <cstdlib>		// Header file used for rand
#include "DiceCup.hpp"

using namespace std;

// Default constructor
DiceCup::DiceCup()
{
	numDice = 1;
	numFaces = 2;
}

// Constructor taking parameters
DiceCup::DiceCup(int numberDice, int numberFace)
{
	setNumDice(numberDice);
	setNumFaces(numberFace);
}


// Function to set Number of Dice
void DiceCup::setNumDice(int numberDice)
{
	numDice = numberDice;
}


// Function to set Number of Faces on die
void DiceCup::setNumFaces(int numberFace)
{
	numFaces = numberFace;
}

void DiceCup::rollDice(int numrRolls)
{
	int totalRoll = 0,		// Total value count of all dice
		roll;			// Count of die
	const int MINFACES = 1;	// Minimum number of faces on die


	for (int i = 1; i <= numrRolls; i++)
	{
		for (int i = 1; i <= numDice; i++)
		{
			roll = rand() % (numFaces - MINFACES + 1) + MINFACES;
			totalRoll += roll;
		}
		cout << "Total value of roll is: " << totalRoll << "\n";
	}
}


int main()
{
	// Variables
	int numrDice,
		numrFace,
		numrRolls;
	//DiceCup cup;

	// Brief Introduction to Program
	cout << "Welcome to the Dice Cup Program!" << endl;
	cout << "This program will ask you for the number of faces on the dice,\n"
		<< "number of dice in the cup, and number of rolls of the dice cup\n";

	// Ask the user for number of dice and faces on dice
	cout << "How many faces are on a die: ";
	cin >> numrFace;
	// Validate faces are valid
	if (numrFace < 1)
	{
		numrFace = 0;
		cout << "\nERROR: Input should be greater than 0.";
	}

	cout << "\nHow many dice are in the cup: ";
	cin >> numrDice;
	// Validate dice are valid
	if (numrDice < 1)
	{
		numrDice = 0;
		cout << "\nERROR: Input should be greater than 0.";
	}

	// Ask the user for number of rolls
	cout << "\nHow many rolls of the dice cup: ";
	cin >> numrRolls;

	// Call Default Constructor for any instance where error
	if ((numrDice == 0) || (numrFace == 0))
	{
		DiceCup cup;
		cup.rollDice(numrRolls);
	}
	// else call the Constructor and send two arguments
	else
	{
		DiceCup cup;
		cup.setNumDice(numrDice);
		cup.setNumFaces(numrFace);
		if (numrRolls > 0)
		{
			cup.rollDice(numrRolls);
		}
		else
		{
			cout << "\nERROR: Rolls should be more than 0.";
			return 0;
		}
	}
     system("pause");
	// Exit Program
	return 0;
}