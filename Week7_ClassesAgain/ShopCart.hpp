#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP
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
#include <vector>
#include "Item.hpp"

using namespace std;

// Class ShoppingCart
class ShoppingCart
{
private:
	vector <Item> items;			// Vector for items

public:
	void addItem(Item item);	// Method to add items
	void listContents();		// Method to list shopping cart object
	double totalPrice();		// Method to total price in shopping cart object
};

#endif