/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/07/2015
** Description: This program will be using classes to ask 
**     the user for the height, width, and length of a box.  
**     Input validation will result for numbers less than 0.  
**     The program will output total volume and surface 
**     area of the box.
***********************************************************/

#include <iostream>

using namespace std;

class Box
{
private:
	double height,		// Height of box
		width,			// Width of box
		length;			// Length of boxd

public:
	// Default constructor for box
	Box();

	// Constructor accepting 3 parameters (height, width, length)
	Box(double, double, double);

	// Set methods for initializing the fields for Box
	void setHeight(double);
	void setWidth(double);
	void setLength(double);

	// Method for returning the volume of the box
	double getVolume();

	// Method for returning the surface area of the box
	double getSurfaceArea();
};