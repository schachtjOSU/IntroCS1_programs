#ifndef CARR_HPP
#define CARR_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/11/2015
** Description: This program will be using classes to ask 
**     the user for the year and make of the car.  The user 
**     will then be able to accelerate or put on the brakes 
**     until he/she decides to quit.  Each time the user 
**     decides to accelerate or brake the display will print 
**     the speed.  The car can only go between 0 and 80 speed.
***********************************************************/

#include <iostream>
#include <string>

using namespace std;


class Car
{
public:
	Car();				// Default constructor
	Car(int, string, int);			// Car constructor taking
	void setYear(int);		// set methods for Car object
	void setMake(string);
	void setSpeed(int);
	int getSpeed();			// get method for implementation file
	void accelerate();		// accelerate method
	void brake();			// brake method


private:
	int year,			// Car's Year made
		speed;			// Current speed of the car
	string make;		// Car's make
};


#endif