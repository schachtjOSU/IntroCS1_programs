/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/12/2015
** Description: This program will be using classes to input
**     x and y coordinate points, calculate the length of
**     the line segment, and calculate the slope of the line
**     between two points.
***********************************************************/

#include <iostream>
#include <cmath>
#include "Point.hpp"

using namespace std;

/***********************************************************
**  Description: Default Constructor for Point Class
**  Parameters: None
************************************************************/
Point::Point()
{
	setXCoord(0);
	setYCoord(0);
}

/***********************************************************
**  Description: Constructor for Point Class setting x and y coordinates
**  Parameters: Takes 2 double parameters
************************************************************/
Point::Point(double xcoord, double ycoord)
{
	setXCoord(xcoord);
	setYCoord(ycoord);
}

/***********************************************************
**  Description:  Sets the x_coordinate for the Point object
**  Parameters: Takes a double type value
************************************************************/
void Point::setXCoord(double xcoord)
{
	x_coordinate = xcoord;
}

/***********************************************************
**  Description:  Set the y_coordinate for the Point object
**  Parameters:  Takes a double type value
************************************************************/
void Point::setYCoord(double ycoord)
{
	y_coordinate = ycoord;
}

/***********************************************************
**  Description: Returns the x_coordinate from the Point object as a constant reference
**  Parameters: None
************************************************************/
double Point::getXCoord()
const {
	return x_coordinate;
}

/***********************************************************
**  Description:  Returns the y_coordinates from the Point object as a constant reference
**  Parameters:  None
************************************************************/
double Point::getYCoord()
const {
	return y_coordinate;
}

/***********************************************************
**  Description:  Gathers the x and y coordinates from 2 Point objects,
**     then calculates the length of the line between two points using
**     Pythagorem Theorem
**  Parameters: Takes in a constant reference Point object
************************************************************/
double Point::distanceTo(const Point &point2)
{
	// Variables
	double length;		// length of line
	double x_coord1,	// Coordinate list
		y_coord1,
		x_coord2,
		y_coord2;
	double xcoordDiff,	// Difference in x and y Coordinates
		ycoordDiff;
	double xPowerDiff,	// Difference of x and y coordinates to the power of 2
		yPowerDiff;

	// Extract x-coord and y-coord from point
	x_coord1 = x_coordinate;
	y_coord1 = y_coordinate;
	
	// get x-coord and y-coord from reference object
	x_coord2 = point2.getXCoord();
	y_coord2 = point2.getYCoord();

	// Differences in x and y coordinates
	xcoordDiff = x_coord2 - x_coord1;
	ycoordDiff = y_coord2 - y_coord1;

	// Take difference to the power of 2
	xPowerDiff = pow(xcoordDiff, 2);
	yPowerDiff = pow(ycoordDiff, 2);

	// Find length from all 4 coordinates with Pythagorean Theorem equation
	length = sqrt(xPowerDiff + yPowerDiff);

	// Return length
	return length;
}
