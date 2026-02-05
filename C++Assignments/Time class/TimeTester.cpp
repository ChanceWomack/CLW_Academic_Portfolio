/* Chance Womack
 * Proj 3: Time Class
 * Tester
 */

// include desire libraries
#include <iostream>
#include "Time.h"
using namespace std;

int main()
{ // start main
	TimeType TimeA;
	TimeType TimeB(10,8,24);
	TimeType TimeC(25,61,65);
	TimeType TimeD(-3,17,86);
	TimeType TimeE;
	
	cout << TimeD << endl;
	
	cout << "Time Types Made" << endl;
	cout << TimeB << endl;
	
	TimeB.setTime(11,8,24);
	
	cout << "TimeB Updated" << endl;
	cout << TimeB << endl;
	
	cout << "Time A tests" << endl;
	cout << TimeA << endl;
	TimeA.getTime();
	
	//~ cout << "Imput Time for TimeE: ";
	//~ cin >> TimeE;
	//~ cout << endl << TimeE;
	
	
	
	return 0;
} // end main
