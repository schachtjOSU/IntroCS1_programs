#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/12/2015
** Description: This program will be using classes to input
**     x and y coordinate points, calculate the length of
**     the line segment, and calculate the slope of the line
**     between two points.
***********************************************************/

#include <iostream>
#include "Point.hpp"

using namespace std;


class LineSegment
{
private:
	Point endpoint1,	// endpoints
		endpoint2;

public:
	LineSegment();		// Default Constructor
	LineSegment(Point, Point);	// Constructor
	void setEnd1(Point);		// set endpoints
	void setEnd2(Point);
	Point getEnd1();			// get endpoints
	Point getEnd2();
	double length(Point &point2, Point point1);			// Calculate length of line
	double slope();				// Calculate slope between points
};


#endif