#ifndef SPHERE_HPP
#define SPHERE_HPP

/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/25/2015
** Description: This program will be using classes to create 
**     a Sphere object.  The user will input the radius of 
**     the sphere and from there, the program will caluclate 
**     the volume of the sphere and output the result for display.
***********************************************************/
#include <iostream>

using namespace std;

class Sphere
{
private:
	double radius;		// Sphere member field

public:
	Sphere();			// Default Constructor
	Sphere(double);		// Constructor with 1 parameter
	void setRadius(double);		// Set the member field
	double getRadius();		// Get method for member field
	double getVolume();		// Method to calculate and return volume of sphere
};

#endif