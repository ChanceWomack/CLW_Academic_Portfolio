/* Chance Womack
 * Project 2:  Inheritance/Composition
 * Goal:
	 * Using the provided Point class, create a Circle class. A circle is defined by a point and a radius.
	 * Your implementation must use the Point class in some way.
	 * You can use either inheritance or composition to use the Point in creating your circle class.
	 * Be sure to include constructors for passing the X and Y coordinates and the radius for your Circle class.
	 * Also provide methods for the area and circumference of the circle. Use the value 3.1415926 for PI.
	 * Overload stream insertion to print a circle by printing the point, the radius, and the area.
	 * 
	 * I will be using Composition for this project.
 */

#ifndef H_CIRCLE
#define H_CIRCLE
// include desired libraries
#include <iostream>
#include <iomanip>
#include <cmath> // to handle the Double multiplications...may not be needed
#include "Point.h"

// declare constant variables
const double PI = 3.1415926; // prescribed value for PI as given in the Goals

class CircleType
	{ // start class definition
	private:
	// Data Members
		int radius;
		Point center;
	public:
	// methods
		// Default Constructor--------------------------------------------------
			CircleType()
			{ // start constructor
				setCenter(0, 0);
				setRadius(0);
			} // end constructor
	
		// Specific Constructor--------------------------------------------------
			CircleType(int r, int x, int y)
			{ // start constructor
				setCenter(x, y);
				setRadius(r);
			} // end constructor

		// setters------------------------------------------------------
			void setRadius(int r) {radius = r;}
			void setCenter (int v1, int v2) {center.setX(v1); center.setY(v2);}			
		
		// getters------------------------------------------------------
			int getRadius() const {return radius;}
			Point getCenter() const {return center;}
	
		// Area Method--------------------------------------------------
			// FORMULA:   A = PI*(radius*radius)
			double findArea()
			{ // start findArea
				double area = PI*radius*radius;
				return area;
			} // end findArea
		
		// Circumference Method--------------------------------------------------
			// FORMULA:   A = 2*PI*radius
			double findCircum()
			{ // start findCircum
				double circumference = 2*PI*radius;
				return circumference;
			} // end findCircum
		
		// Overloaded Operators-----------------------------------------
			// ostream <<
				friend std::ostream& operator<<(std::ostream& out, CircleType& c)
				{ // start of the operator overload
					out << "Center of Circle is at point: " << c.center << std::endl
						<< "The Radius of the Circle is: " << c.getRadius() << std::endl
						<< "The Area of the Circle is: " << c.findArea() << std::endl
						<< "The Circumference of the Circle is: " << c.findCircum();	
					return out;
				} // end of the operator overload
				
			// istream >>
				friend std::istream& operator>>(std::istream& is, CircleType& c)
				{ // start of the operator overload
					is >> c.radius >> c.center;	// i modified Point.h to overload >>		
					return is;
				} // end of the operator overload
	
	
	}; // end class definition
#endif
