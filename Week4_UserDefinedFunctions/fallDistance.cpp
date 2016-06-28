/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/28/2015
** Description: This program will read a number as the 
**     falling time for an object.  The number will be 
**     calculated to determine the object's distance to 
**     fall and the distance will be output to display.
***********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

// Calculate Distance Function
double calcDistance(double sec)
{
	// Constant
	const double GRAVITY = 9.80;
	
	// set variables
	double distance = 0.0;	// calculated distance

	// Distance calculation is (1/2)*g*t^2
	// g is gravity and t is time in seconds
	distance = ((pow(sec, 2.0))*GRAVITY)/2.0;

	// return the distance
	return distance;
}


// Main function
int main()
{
	// set variables
		double sec = 0.0;			// User input seconds.  
						// I Assume seconds could be integer or fractional whole

	// Brief Program Description
	cout << "Welcome to the Falling Distance Calculator!" << endl;
	cout << "This program will ask for time object took to fall in seconds.\n"
		<< "Then will calculate total distance the object took to fall in meters.\n";

	// User Enters in time in seconds.
	cout << "What is the time in seconds, it took for the object to fall: ";
	cin >> sec;

	// Calculate distance function
	double distance = calcDistance(sec);

	// Output Distance
	cout << "\nTotal distance for object to fall is " << distance
		<< " meters." << endl;

	// Exit the program
	return 0;
}