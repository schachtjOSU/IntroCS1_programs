/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/13/2015
** Description: This program asks the user for how many 
**     tickets for each classs of seats were sold, given 
**     there are 3 different classes.  Then displays the 
**     amount of income sold from ticket sales.
***********************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//List of variables
	double a_class = 15.0,		// Set seat class prices
		b_class = 12.0,
		c_class = 9.0,
		a_sales,				// Calculated sales for each class
		b_sales,
		c_sales,
		total_sales;			// Total sales
	int a_purch,				// Input of tickets purchased
		b_purch,
		c_purch;

	// Program Welcome
	cout << "Welcome to the Ticket Income Program!\n";
	cout << "This program will calculate sales for "
		<< "the softball game at the stadium\n";
	
	// Ask user how many tickets were purchased for each class
	cout << "Cost for Class A seats is $" << fixed << showpoint 
		<< setprecision(2) << a_class << endl;
	cout << "How many Class A tickets were sold :";
	cin >> a_purch;
	cout << "Cost for Class B seats is $" << fixed << showpoint
		<< setprecision(2) << b_class << endl;
	cout << "How many Class B tickets were sold :";
	cin >> b_purch;
	cout << "Cost for Class C seats is $" << fixed << showpoint
		<< setprecision(2) << c_class << endl;
	cout << "How many Class C tickets were sold :";
	cin >> c_purch;

	// Calculate sales for each class and total sales
	a_sales = a_class * a_purch;
	b_sales = b_class * b_purch;
	c_sales = c_class * c_purch;
	total_sales = a_sales + b_sales + c_sales;

	// Output sales results
	cout << "Sales for Class A is $" << fixed << showpoint 
		<< setprecision(2) << a_sales << endl;
	cout << "Sales for Class B is $" << fixed << showpoint
		<< setprecision(2) << b_sales << endl;
	cout << "Sales for Class C is $" << fixed << showpoint
		<< setprecision(2) << c_sales << endl;
	cout << "Total sales is $" << fixed << showpoint
		<< setprecision(2) << total_sales << endl;

     system("pause");

	return 0;
}