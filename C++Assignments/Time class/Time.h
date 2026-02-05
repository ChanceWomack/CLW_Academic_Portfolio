/* Chance Womack
 * Proj 3: Time Class
 * Goal-----------------------------------------------------------------
 * A time consists of an hour, minute, and second.
 * Your class needs to support creating instances of "time" objects;
 * -> both by supplying the three values and by supplying no information (default constructor).
 * You need to provide methods for reading a time from an input stream and for writing a time to an output stream.
 * -> (stream overloading)
 * You also need to have a method for setting the time to new values: (setTime(h,m,s)).
 * You should verify that information provided to your class is valid
 * -> (no negative values, can’t go past hour 23, minute 59, second 59).
 *--------------------------------------------------------------------*/
#ifndef TIMET_H
#define TIMET_H
// include desire libraries
#include <iostream>
#include <iomanip>
// class definition
class TimeType
	{ // start def
	private:
		// data members
		int hour;
		int minute;
		int second;
	public:
		// methods
			// default constructor
				TimeType() {setHour(0); setMinute(0); setSecond(0);}
			// specific constructor
				TimeType(int h, int m, int s) {setHour(h); setMinute(m); setSecond(s);}
			// setters
				// input validation is managed with the setters
				// if an error is found, an error message is displayed and the default (0) is used
				// to ensure validation, all value setting is handled through the THREE CORE setters
				void setHour(int h) {if (h<24 && h>0) hour = h; else {std::cerr << "ERROR: Invalid Value for Hour: Using Default" << std::endl; hour = 0;}}
				void setMinute(int m) {if (m<60 && m>0) minute = m; else {std::cerr << "ERROR: Invalid Value for Minute: Using Default" << std::endl; minute = 0;}}
				void setSecond(int s) {if (s<60 && s>0) second = s; else {std::cerr << "ERROR: Invalid Value for Second: Using Default" << std::endl; second = 0;}}
				// NON-CORE setter, relies on the core setters above
				// used to set all values at once, rather than individually 
				void setTime(int h, int m, int s) {setHour(h); setMinute(m); setSecond(s);}
			// getters
				int getHour() const {return hour;}
				int getMinute() const {return minute;}
				int getSecond() const {return second;}
				// a simple print method
				void getTime() const {std::cout << hour << ':' << minute << ':' << second;}
			// overload ostream <<
				friend std::ostream& operator<<(std::ostream& out, TimeType& t)
				{ // start of the operator overload
					out << t.getHour() << ':' << t.getMinute() << ':' << t.getSecond();
					return out;
				} // end of the operator overload
			// overload istream >>
				friend std::istream& operator>>(std::istream& is, TimeType& t)
				{ // start of the operator overload
					int h; int m; int s;
					is >> h;
					is.ignore(1,':');
					is >> m;
					is.ignore(1,':');
					is >> s;
					t.setTime(h,m,s);	
					return is;
				} // end of the operator overload
	}; // end def
#endif
