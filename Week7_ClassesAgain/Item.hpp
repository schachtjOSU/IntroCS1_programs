#ifndef ITEM_HPP
#define ITEM_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/20/2015
** Description: This program will be using classes to store 
**     items into an Item class vector.  The user will be 
**     able to add items, list contents, calculate total 
**     price in the shopping cart, or quit the program.
***********************************************************/

#include <iostream>
#include <string>

using namespace std;

// Class Item
class Item
{
private:
	string name;			// Member fields
	double price;
	int quantity;

public:
	Item();						// Default Constructor
	Item(string, double, int);	// Constructor with Params
	void setName(string);		// Set methods for each field
	void setPrice(double);
	void setQuantity(int);
	string getName();			// Methods to return fields
	double getPrice();
	int getQuantity();
};

#endif