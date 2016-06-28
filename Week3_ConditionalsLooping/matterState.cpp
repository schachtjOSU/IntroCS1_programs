/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/18/2015
** Description: This program takes a temperature (integer) 
**     submitted by the user and will output the state of 
**     the substances with the given temperature.
***********************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Constants for Freeze and Boiling point of substances
	const int ETHYL_ALCOHOL_FREEZE = -173,
		ETHYL_ALCOHOL_BOIL = 172,
		MERCURY_FREEZE = -38,
		MERCURY_BOIL = 676,
		OXYGEN_FREEZE = -362,
		OXYGEN_BOIL = -306,
		WATER_FREEZE = 32,
		WATER_BOIL = 212;

	
	// Varaibles
	int userTemp;	// value input by user

	// Strings for output display on state of substance
	string ethylAlcoholState,
		mercuryState,
		oxygenState,
		waterState;


	// Brief description of the program
	cout << "Welcome to the Matter State Program!\n"
		<< "This program will take an integer temperature from the \n"
		<< "user and output the state of ethyl alcohol, mercury, oxygen, and water.\n";


	// Ask user for temperature and store to variable.
	cout << "Please enter the integer temperature (in degrees Fahrenheit): ";
	cin >> userTemp;

	// Conditionals for each substance to decide if solid, liquid or gas.
	// Conditional for Ethyl Alcohol
	if (userTemp >= ETHYL_ALCOHOL_BOIL)
		ethylAlcoholState = "gas";
	else if (userTemp <= ETHYL_ALCOHOL_FREEZE)
		ethylAlcoholState = "solid";
	else
		ethylAlcoholState = "liquid";

	// Conditional for Mercury
	if (userTemp >= MERCURY_BOIL)
		mercuryState = "gas";
	else if (userTemp <= MERCURY_FREEZE)
		mercuryState = "solid";
	else
		mercuryState = "liquid";

	// Conditional for oxygen
	if (userTemp >= OXYGEN_BOIL)
		oxygenState = "gas";
	else if (userTemp <= OXYGEN_FREEZE)
		oxygenState = "solid";
	else
		oxygenState = "liquid";

	// Conditional for water
	if (userTemp >= WATER_BOIL)
		waterState = "gas";
	else if (userTemp <= WATER_FREEZE)
		waterState = "solid";
	else
		waterState = "liquid";


	// Display output of the given temperature for each substance what state it is in.
	cout << "\nThe temperature you entered was " << userTemp
		<< " degrees." << endl;
	cout << "This puts ethyl alcohol in a " << ethylAlcoholState << " state.\n";
	cout << "This puts mercury in a " << mercuryState << " state.\n";
	cout << "This puts oxygen in a " << oxygenState << " state.\n";
	cout << "This puts water in a " << waterState << " state.\n";

	// Exit the program
	return 0;
}