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

using namespace std;

class DiceCup
{
private:
	int numDice;			// Number of Dice
	int numFaces;			// Number of Faces

public:

	// Constructor accepting 2 parameters - CORRECTED
	DiceCup(int, int);
	// Default Constructor - CORRECTED
	DiceCup();

	// Set Number of Dice and faces on Dice - CORRECTED
	void setNumDice(int);

	// Set Number of Faces on a die - Corrected
	void setNumFaces(int);

	// Void function for rolling dice, as nothing is being returned
	void rollDice(int);
};