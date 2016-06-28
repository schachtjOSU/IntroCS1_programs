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
#include "LineSegment.hpp"

using namespace std;

// Default Constructor
/*LineSegment::LineSegment()
{
	Point point1();
	Point point2();
	setEnd1(point1());
	setEnd2(point2());
}*/

/***********************************************************
**  Description:  Constructor for Line Segment object setting End points
**  Parameters: Takes 2 Point objects as parameters
************************************************************/
LineSegment::LineSegment(Point point1, Point point2)
{
	setEnd1(point1);
	setEnd2(point2);
}

/***********************************************************
**  Description:  Sets the first endpoint for the Line Segment object
**  Parameters:  Takes a Point Object as a parameter
************************************************************/
void LineSegment::setEnd1(Point point1)
{
	endpoint1 = point1;
}

/***********************************************************
**  Description:  Sets the second endpoint for the Line Segment object
**  Parameters:  Takes a Point Object as a parameter
************************************************************/
void LineSegment::setEnd2(Point point2)
{
	endpoint2 = point2;
}

/***********************************************************
**  Description:  Returns the first endpoint from Line Segment as a Point object
**  Parameters: None
************************************************************/
Point LineSegment::getEnd1()
{
	return endpoint1;
}

/***********************************************************
**  Description:  Returns the second endpoint from Line Segment as a Point object
**  Parameters:  None
************************************************************/
Point LineSegment::getEnd2()
{
	return endpoint2;
}

/***********************************************************
**  Description:  Captures the length of the line by using the first point
**     and sending the second point as a parameter. through the distanceTo function
**     in the Point class.  Returns the length.
**  Parameters:  Takes a constant reference Point object and another Point object
************************************************************/
double LineSegment::length(Point &point2, Point point1)
{
	double lengthCalc = point1.distanceTo(point2);
	return lengthCalc;
}

/***********************************************************
**  Description:  Gets both endpoints and extracts the x and y coordinates.
**     Calculates the slope of the line segment between both endpoints
**     and then returns the slope value as a double type.
**  Parameters:  None
************************************************************/
double LineSegment::slope()
{
	// Variables
	double slope;		// Calculated slope value
	Point point1,
		point2;
	double x_coord1,	// X and Y coordinates
		x_coord2,
		y_coord1,
		y_coord2;
	double yCoordDiff,
		xCoordDiff;

	// Get both x and y coordinates from first object
	point1 = getEnd1();
	point2 = getEnd2();
	x_coord1 = point1.getXCoord();
	y_coord1 = point1.getYCoord();
	x_coord2 = point2.getXCoord();
	y_coord2 = point2.getYCoord();

	// Apply slope equation
	yCoordDiff = y_coord2 - y_coord1;
	xCoordDiff = x_coord2 - x_coord1;
	slope = yCoordDiff / xCoordDiff;

	// Return the slope value
	return slope;
}


/***********************************************************
**  Description:  This is the Main function.  Takes in user data,
**     creates the Point and Line Segment objects from user entered data,
**     calls functions to calculate length and slope, and finally prints
**     the output.
**  Parameters: None
************************************************************/
int main()
{
	// Variables
	double x_coord1,		// Coordinates for Points
		y_coord1,
		x_coord2,
		y_coord2;
	double lengthCalc,
		slopeCalc;
	bool infinity;

	// Brief program description
	cout << "Welcome to the Line Segment length and Slope Program." << endl << endl;
	cout << "\nThis program will ask you to enter in point coordinates,"
		<< "\n and then will calculate the line length and slope between the two points."
		<< endl << endl;

	// Ask the user for the first coordinates, pass to first Point object
	cout << "Please enter the x-coordinate for the first point: ";
	cin >> x_coord1;
	cout << "\nPlease enter the y-coordinate for the first point: ";
	cin >> y_coord1;

	// Ask the user for the second coordinates, Pass to second Point object
	cout << "\nPlease enter the x-coordinate for the second point: ";
	cin >> x_coord2;
	cout << "\nPlease enter the y-coordinate for the second point: ";
	cin >> y_coord2;

	// Pass the x and y coordinates as Point objects.
	Point point1(x_coord1, y_coord1);
	Point point2(x_coord2, y_coord2);

	// Pass the Point objects and create Line Segment object
	LineSegment line(point1, point2);

	// Call length method with constant reference Point as argument
	lengthCalc = line.length(point2, point1);
	slopeCalc = line.slope();

	// Conditional check if slope is infinity
	infinity = isinf(slopeCalc);

	if (infinity)
	{
		cout << "\nLength of the line is: " << lengthCalc;
		cout << "\n\nSlope of the line is infinity.\n";
	}
	else
	{
		// Print return of the length of slope
		cout << "\nLength of the line is: " << lengthCalc;
		cout << "\n\nSlope of the line is: " << slopeCalc << endl;
	}

	// Exit program
	return 0;
}