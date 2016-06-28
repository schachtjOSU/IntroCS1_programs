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
#include "ShopCart.hpp"
#include <iomanip>
#include <cstdlib>

using namespace std;

/***********************************************************
**  Description: Add item to the end of the vector
**  Parameters: Takes the item object as a parameter
************************************************************/
void ShoppingCart::addItem(Item itemIn)
{
	items.push_back(itemIn);
}


/***********************************************************
**  Description: Print each item object from vector, printing name, price and quantity
**  Parameters: None
************************************************************/
void ShoppingCart::listContents()
{
	// Variables
	string nameField;		// For fields output
	double priceField;
	int quantField;
	int vecSize;			// Vector size

	// Get the size of the vector
	vecSize = items.size();
	// Loop through the vector and print out each field from each object.
	for (int i = 0; i < vecSize; i++)
	{
		nameField = items[i].getName();
		priceField = items[i].getPrice();
		quantField = items[i].getQuantity();
		//Output list
		cout << "\n\nItem: " << nameField;
		cout << "\nPrice: $" << fixed << setprecision(2) << priceField;
		cout << "\nQuantity: " << quantField;
	}
}


/***********************************************************
**  Description: Calculate total price in cart.  goes through vector taking price and quantity.  Multiply per each object
**  Parameters: None
************************************************************/
double ShoppingCart::totalPrice()
{
	// Variables
	double priceField;		// temp for fields
	int quantField;
	double total;			// Total Price
	int vecSize;			// Vector size

	// Get the size of the vector
	vecSize = items.size();

	// Loop through vector to get the price and quantity of each object
	for (int i = 0; i < vecSize; i++)
	{
		priceField = items[i].getPrice();
		quantField = items[i].getQuantity();
		total = priceField * quantField;
	}

	// return double total price
	return total;
}


/***********************************************************
**  Description:  Main function.  user menu goes to other functions and exits program at end
**  Parameters: None
************************************************************/
int main()
{
	// Variables
	bool looping = true;	// Is true in do/while loop until quit program
	char answer[1];			// Users Menu selection
	ShoppingCart cart;		// Initialize ShoppingCart object
	double total;			// total price
	string useName;			// User entered item name
	char usePrice[100];		// user entered item price
	char useQuantity[100];		// user entered item quantity
	double priceEnter;
	int quantEnter;
	char buffer[256];		// buffer for price user input
	bool loopCheck = true;		// Check loop for user entries are valid


	// Brief Title
	cout << "Welcome to the Shopping Cart Program!" << endl;

	// Start the loop
	do
	{
		// Output Menu Options
		cout << "\n\nSelect your shopping cart menu option"
			<< endl << "(A) to add a new item to the cart."
			<< endl << "(L) to list all items in the cart."
			<< endl << "(T) to display total cost in the cart."
			<< endl << "(Q) to quit the program."
			<< endl << "Enter the letter here: ";
		// Get selection from user
		cin.getline(answer, 2, '\n');
		answer[0] = toupper(answer[0]);

		// Start switch here
		switch (answer[0])
		{
		case 'A':
		{
			//Loop until user enters proper price and quantity
			do
			{
				loopCheck = true;
				// Ask user items to enter
				// Ask name
				cout << "\n\nEnter the item name here: ";
				getline(cin, useName);
				// Ask price
				cout << endl << "Enter the price of the item here: ";
				cin.getline(usePrice, 100, '\n');
				//priceEnter = stof(usePrice);
				//fgets(buffer, 256, stdin);
				priceEnter = atof(usePrice);
				/*for (int j = 0; j < 100; j++)
				{
					if ((!isdigit(usePrice[j])) && (usePrice[j] != '.'))
					{
						cout << "\nYou entered an invalid value in price.  Please Try again!";
						loopCheck = false;
						break;
					}
				}*/
				
				
				// Ask Quantity
				cout << endl << "Enter the quantity of the item here: ";
				cin.getline(useQuantity, 100, '\n');
				quantEnter = atoi(useQuantity);
				/*for (int k = 0; k < 100; k++)
				{
					if (!isdigit(useQuantity[k]))
					{
						cout << "\nYou entered an invalid value in quantity.  Please Try again!";
						loopCheck = false;
						break;
					}
				}
				quantEnter = stoi(useQuantity);*/
				
			} while (!loopCheck);

			// Check if item has been created, if not start one
			// Create item
			Item item(useName, priceEnter, quantEnter);

			// Use addItem method here.
			cart.addItem(item);
			break;
		}
		case 'L':
		{
			cart.listContents();
			break;
		}
		case 'T':
		{
			total = cart.totalPrice();
			cout << "\n\nTotal price in cart is: $" << fixed << setprecision(2) << total;
			break;
		}
		case 'Q':
		{
			looping = false;
			cout << "\nExiting the program...";
			break;
		}
		default:
		{
			cout << "\nYou did not enter A, L, T or Q!   Try Again!";
			break;
		}

		}
	} while (looping);

	// Exit the program
	cout << endl;
	return 0;
}
