/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/25/2015
** Description: This program will be using classes to create
**     a Sphere object.  The user will input the radius of
**     the sphere and from there, the program will caluclate
**     the volume of the sphere and output the result for display.
***********************************************************/
#include <iostream>
#include "Sphere.hpp"
#include <cmath>


using namespace std;

/***********************************************************
**  Description:  Default Constructor
**  Parameters: None
************************************************************/
Sphere::Sphere()
{
	radius = 0.0;
}


/***********************************************************
**  Description: Constructor sends parameter to setRadius method
**  Parameters: One of double type
************************************************************/
Sphere::Sphere(double radIn)
{
	setRadius(radIn);
}


/***********************************************************
**  Description: Method to assign the radius field
**  Parameters: One of double type
************************************************************/
void Sphere::setRadius(double radIn)
{
	radius = radIn;
}


/***********************************************************
**  Description: Method to return the radius field
**  Parameters: None
************************************************************/
double Sphere::getRadius()
{
	return radius;
}


/***********************************************************
**  Description: Calculate the volume of the Sphere object.
**  Parameters: none
************************************************************/
double Sphere::getVolume()
{
	// Set variables
	double volume = 0.0;
	double calcRad;
	const double PI = 3.1415926535897932384626433832;

	//Get radius object
	calcRad = getRadius();

	/*Calculate the volume of the sphere
	Below code is partially in reference to:
	'Calculating volume for sphere in C++'
	Date found: 02/25/2015
	Source: http://stackoverflow.com/questions/2785306/calculating-volume-for-sphere-in-c
	Volume = (4.0/3.0) * pi * radius^3 */
	volume = ((4.0 / 3.0) *  PI) * pow(calcRad, 3.0);

	// Return volume
	return volume;
}