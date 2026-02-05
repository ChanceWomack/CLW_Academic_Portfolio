/* Chance Womack
 * Proj 4: Appointment Class
 * Goal:
 * Using the DateType and TimeType classes, create an AppointmentType class (like in an appointment book or calendar application). 
 * An appointment consists of a Date, Time, and a description (a string?).
 * Make sure your class includes overloaded methods for input (stream extraction) and output (stream insertion) of an appointment.
 * Also include constructor(s) for providing a Date, Time, and description; and default values.
 * You also need to provide a method for determining if two Appointments are the same (operator==).
 * 
 * You also need to update the DateType and TimeType classes with overloaded equality operators (operator==).
 */
#ifndef APPOINTMENT_H
#define APPOINTMENT_H
// include desired libraries
#include "DateType.h"
#include "TimeType.h"
#include <iostream>
class AppointmentType
{ // start def
	private:
		// data members
		DateType date;
		TimeType time;
		string desc; // description of appointment
	public:
		// methods
			// default constructor--------------------------------------
			AppointmentType()
			{ // start default constructor
				// Date and Time headers supply their own default constructors for those data members
				setDesc("Default");
			} // end default constructor
			// specific constructor--------------------------------------
			AppointmentType(DateType d, TimeType t, string s)
			{ // start speciifc constructor
				setDate(d);
				setTime(t);
				setDesc(s);
			} // end speciifc constructor
			// getters--------------------------------------------------
				string getDesc() const {return desc;}
				DateType getDate() const {return date;}
				TimeType getTime() const {return time;}
			//setters---------------------------------------------------
				void setDesc(string s) {desc = s;}
				void setTime(TimeType t) {time = t;}
				void setDate(DateType d) {date = d;}
			// overloads------------------------------------------------
				// extraction >>
					friend std::istream& operator>>(std::istream& is, AppointmentType& a)
					{ // start of the operator overload
						is >> a.date; is.ignore(1, ','); // ignores commas if the user puts them in as shown in the entry request in the apptest.cpp
						is >> a.time; is.ignore(1, ',');
						getline(is, a.desc); // allows for a full sentence to be provided for the description
						return is;
					} // end of the operator overload
				// insertion <<
					friend std::ostream& operator<<(std::ostream& out, AppointmentType& a)
					{ // start of the operator overload
						out << "On: " << a.date << " at: " << a.time << std::endl
							<< "Description of Appointment: " << a.getDesc() << std::endl;
						return out;
					} // end of the operator overload
				// equality ==
					bool operator==(const AppointmentType& otherApp) const
					{ // start checker
						return  this->date == otherApp.date &&
								this->time == otherApp.time &&
								this->desc == otherApp.desc;
					} // end checker
				// inequality !=
					bool operator!=(const AppointmentType& otherApp) const
					{ // start checker
						return  this->date != otherApp.date &&
								this->time != otherApp.time &&
								this->desc != otherApp.desc;
					} // end checker
}; // end if
#endif
