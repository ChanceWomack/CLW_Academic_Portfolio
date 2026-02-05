/* Chance Womack
 * Lab 3: Inheritance
 * Goal:
	 * Write class definitions for Employee, SalariedEmployee, and HourlyEmployee.
	 * An Employee is a Person (use the Person class we developed), with a work id (not necessarily their SSN)
	 * A Salaried Employee is an Employee with an annual salary.
	 * An Hourly Employee is an Employee with an hourly pay rate, and hours worked.
	 * Both types of employee need to calculate their weekly pay. The Salaried Employee simply gets their annual salary divided by 52.
	 * The Hourly Employee gets paid their hourly rate times the number of hours worked that week, accounting for overtime (any hours over 40 are paid at 1.5 times the hourly rate).
 */

// include desired libraries
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>
#include "Person.h"

class Employee : public Person
	{ // start class definition
	private:
	// Data Members
		std::string idNum;
	public:
	// methods
		// default Constructor------------------------------------------
		Employee()
			: Person()
			{ // start default constructor
				setIdNum("NULL");
			} // end default constructor
			
		// Specific Constructor-----------------------------------------
		Employee(std::string fn, std::string ln, std::string id)
			: Person(fn, ln)
		{ // start specific constructor
			setIdNum(id);
		} // end specific constructor
		
		// setters------------------------------------------------------
			void setIdNum(std::string n) {idNum = n;}
				
		// getters------------------------------------------------------
			std::string getIdNum() {return idNum;}
			
	}; // end class definition
#endif
