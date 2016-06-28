/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/12/2015
** Description: This program will be using classes to track
**     inventory changes of the thingamajigs, watchamacalits,
**     and framistats.  The program will allow the user to
**     produce more inventory, print a parts order or quit
**     the program.
***********************************************************/

#include <iostream>
#include "Supplies.hpp"

using namespace std;

// Default Constructor
Supplies::Supplies()
{
	setNumThingamajigs(100);
	setNumWatchamacalits(70);
	setNumFramistats(50);
}

// Constructor
Supplies::Supplies(int thingas, int watchas, int framistats)
{
	setNumThingamajigs(thingas);
	setNumWatchamacalits(watchas);
	setNumFramistats(framistats);
}

// set the thingamajigs
void Supplies::setNumThingamajigs(int thingas)
{
	thingamajigs = thingas;
}

// set the watchamacalits
void Supplies::setNumWatchamacalits(int watchas)
{
	watchamacalits = watchas;
}

// set the framistats
void Supplies::setNumFramistats(int framists)
{
	framistats = framists;
}

// print the parts order
void Supplies::printPartsOrder(const Supplies &inventory)
{
	// Variables
	int maxThingys = 100,			// Max inventory
		maxWatchas = 70,
		maxFramistas = 50,
		needThingys,				// Needed inventory
		needWatchas,
		needFramistas;

	// Subtract current inventory with what should be full inventory to get what is needed
	needThingys = maxThingys - inventory.thingamajigs;
	needWatchas = maxWatchas - inventory.watchamacalits;
	needFramistas = maxFramistas - inventory.framistats;

	// Output what is needed
	cout << "\nParts Order Report" << endl << endl;
	cout << "Thingamajigs needed: " << needThingys << endl;
	cout << "Watchamacallits needed: " << needWatchas << endl;
	cout << "Framistats needed: " << needFramistas << endl;

	// Done
}


// produce thing 1
void Supplies::produceThing1(int produce)
{
	// Variables
	int costPerThingy = 1,		// Costs of producting thing 1
		costPerWatchas = 2,
		costPerFramistats = 1;
	int totalCostThingy,		// Total cost for each item
		totalCostWatchas,
		totalCostFramstats;

	// Take number to produce thing 1 and multiply each inventory item for 
	// total cost of each inventory
	totalCostThingy = produce * costPerThingy;
	totalCostWatchas = produce * costPerWatchas;
	totalCostFramstats = produce * costPerFramistats;

	// Subtract cost of each item to current inventory
	totalCostThingy = thingamajigs - totalCostThingy;
	totalCostWatchas = watchamacalits - totalCostWatchas;
	totalCostFramstats = framistats - totalCostFramstats;

	// Set new inventory
	setNumThingamajigs(totalCostThingy);
	setNumWatchamacalits(totalCostWatchas);
	setNumFramistats(totalCostFramstats);
	
	// Done
}


// produce thing 2
void Supplies::produceThing2(int produce)
{
	// Variables
	int costPerThingy = 2,		// Costs of producting thing 1
		costPerFramistats = 1;
	int totalCostThingy,		// Total cost for each item
		totalCostFramstats;

	// Take number to produce thing 1 and multiply each inventory item for 
	// total cost of each inventory
	totalCostThingy = produce * costPerThingy;
	totalCostFramstats = produce * costPerFramistats;

	// Subtract cost of each item to current inventory
	totalCostThingy = thingamajigs - totalCostThingy;
	totalCostFramstats = framistats - totalCostFramstats;

	// Set new inventory
	setNumThingamajigs(totalCostThingy);
	setNumFramistats(totalCostFramstats);

	// Done
}


// Main function
int main()
{
	// variables
	bool looping = true;		// Flag to stop looping when it turns false
	char answer;				// User menu selection
	int produce;				// Items to produce

	// Initialize inventory
	Supplies supply(100, 70, 50);

	// Briefly describe program
	cout << "Welcome to the Supplies Program" << endl << endl;
	cout << "This program will allow you to produce thing 1 or thing 2, "
		<< "\nthen track inventory progress after each production." << endl << endl;

	// Loop menu until quit
	do
	{
		// Print menu
		cout << "\nWhat would you like to do?"
			<< endl << "(A) to produce Thing 1."
			<< endl << "(B) to produce Thing 2."
			<< endl << "(P) to print Parts Order."
			<< endl << "(Q) to quit the program."
			<< endl << "Enter the letter here: ";
		cin >> answer;
		answer = toupper(answer);

		// Conditionals to which user selection
		switch (answer)
		{
		case 'A':
		{
			cout << "\nHow many of Thing 1 to produce: "; 
			cin >> produce;
			supply.produceThing1(produce);
			break;
		}
		case 'B':
		{
			cout << "\nHow many of Thing 2 to produce: ";
			cin >> produce;
			supply.produceThing2(produce);
			break;
		}
		case 'P':
		{
			supply.printPartsOrder(supply);
			break;
		}
		case 'Q':
		{
			looping = false;
			break;
		}
		default:
		{
			cout << "\nYou did not enter A, B, or Q!";
			break;
		}
		}

	} while (looping == true);

	// Exit the program
	return 0;
}