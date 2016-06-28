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
#include "Item.hpp"

using namespace std;

/***********************************************************
**  Description: Default Constructor
**  Parameters: None
************************************************************/
Item::Item()
{
	name = "";
	price = 0.0;
	quantity = 0;
}


/***********************************************************
**  Description: Constructor and sends parameters to set methods
**  Parameters: Takes a string, double and integer type parameters
************************************************************/
Item::Item(string nameIn, double priceIn, int quantityIn)
{
	setName(nameIn);
	setPrice(priceIn);
	setQuantity(quantityIn);
}


/***********************************************************
**  Description: Sets the name field
**  Parameters: Takes string type for parameter
************************************************************/
void Item::setName(string nameIn)
{
	name = nameIn;
}


/***********************************************************
**  Description: Sets the price field
**  Parameters: Takes double type for parameter
************************************************************/
void Item::setPrice(double priceIn)
{
	price = priceIn;
}


/***********************************************************
**  Description: Sets the quantity field
**  Parameters: Takes integer for parameter
************************************************************/
void Item::setQuantity(int quantityIn)
{
	quantity = quantityIn;
}


/***********************************************************
**  Description: Returns name field
**  Parameters: None
************************************************************/
string Item::getName()
{
	return name;
}


/***********************************************************
**  Description: Returns price field
**  Parameters: None
************************************************************/
double Item::getPrice()
{
	return price;
}


/***********************************************************
**  Description: Returns quantity field
**  Parameters: None
************************************************************/
int Item::getQuantity()
{
	return quantity;
}