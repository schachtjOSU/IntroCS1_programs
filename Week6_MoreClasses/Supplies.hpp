#ifndef SUPPLIES_HPP
#define SUPPLIES_HPP
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

using namespace std;

class Supplies
{
private:
	int thingamajigs,	// Inventory
		watchamacalits,
		framistats;

public:
	Supplies();			// Defualt constructor
	Supplies(int, int, int);	// Constructor with arguments
	void setNumThingamajigs(int);
	void setNumWatchamacalits(int);
	void setNumFramistats(int);
	void printPartsOrder(const Supplies&);
	void produceThing1(int);
	void produceThing2(int);
};
#endif