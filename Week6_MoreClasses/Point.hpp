#ifndef POINT_HPP
#define POINT_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/12/2015
** Description: This program will be using classes to input 
**     x and y coordinate points, calculate the length of 
**     the line segment, and calculate the slope of the line 
**     between two points.
***********************************************************/

#include <iostream>

using namespace std;

class Point
{
private:
	double x_coordinate,	// Point coordinates
		y_coordinate;

public:
	Point();				// Default Constructor
	Point(double, double);	// Constructor
	void setXCoord(double);	// set methods
	void setYCoord(double);
	double getXCoord() const;		// get methods
	double getYCoord() const;
	double distanceTo(const Point &point1);	// Calculate length method
};
#endif