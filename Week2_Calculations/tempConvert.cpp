/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/14/2015
** Description: This program asks the user for a 
**     temperature in Celsius, converts and then displays
**     to Fahrenheit temperature.
***********************************************************/

#include <iostream>
using namespace std;

int main()
{
	// Variables
	double c_temp,		// Store for Celsius temperature
		f_temp;			// Store for Fahrenheit temperature

	//Output brief description
	cout << "This program will convert Celsius to Fahrenheit.\n";
	// Ask user for temperature in Celsius and store value
	cout << "Enter a temperature in Celsius: ";
	cin >> c_temp;

	// Convert Celsius to Fahrenheit
	f_temp = ((9.0 * c_temp) / 5.0) + 32.0;

	// Output fahrenheit temperature
	cout << "The temperature of " << c_temp << " degrees Celsius\n"
		<< "is " << f_temp << " degrees Fahrenheit.";

	// Exit program
	return 0;
}