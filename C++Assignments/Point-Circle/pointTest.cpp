#include "Point.h"
#include "Circle.h"
#include <iostream>
using namespace std;

// expaned on to test additional functions and overloaded operators

int main() {

    Point p(5, 10);

    cout << p << endl;

	CircleType c;
	
	cout << "DEFAULT VALUES" << endl;
	cout << "Radius " << c.getRadius() << endl;
	cout << "Center " << c.getCenter() << endl;
	cout << "Area " << c.findArea() << endl;
	cout << "Circumference " << c.findCircum() << endl << endl;

	c = CircleType(3, 2, 4);
	
	cout << "SET VALUES" << endl;
	cout << "Radius " << c.getRadius() << endl;
	cout << "Center " << c.getCenter() << endl;
	cout << "Area " << c.findArea() << endl;
	cout << "Circumference " << c.findCircum() << endl << endl;

	cout << "Enter the radius and x and y point for the center: ";
	cin >> c;
	
	cout << "CIN SET VALUES" << endl;
	cout << "Radius " << c.getRadius() << endl;
	cout << "Center " << c.getCenter() << endl;
	cout << "Area " << c.findArea() << endl;
	cout << "Circumference " << c.findCircum() << endl << endl;

	cout << "PRINT C METHOD" << endl;
	cout << c;

    return 0;

}//end main
