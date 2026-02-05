/* Chance Womack
 * Example of a Templated Class
 */

#pragma once
#include <iostream>
#include <iomanip>

template <class T>
class Pair
	{ // start class definition
	private:
	// Data Members
	T first;
	T second;
	
	public:
	// methods
		// Constructor
	Pair (T f, T s)
	{	setFirst(f);
		setSecond(s);	}
		
		// setters
	void setFirst(T f) { first = f; }
	void setSecond(T s)	{ second = s; }
	
		// getters
	T getFirst() const { return first; }
	T getSecond() const { return second; }
	
	}; // end class definition
