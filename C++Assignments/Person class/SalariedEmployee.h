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
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H
#include <string>
#include <iostream>
#include "Employee.h"

// declare constants
const double ANNUAL = 52.0;

class SalariedEmployee : public Employee
	{ // start class definition
	private:
	// Data Members
		Employee emp;
		double salary;
		double weeklyPay = 0; // weekly pay always starts at 0
	public:
	// methods
		// Constructor--------------------------------------------------
		SalariedEmployee(std::string fn, std::string ln, std::string id, double s)
			: Employee(fn, ln, id)
			{ // start of constructor
				setSalary(s);
			} // end of constructor
			
		// setters------------------------------------------------------
			void setSalary(double s) {salary = s;}
		
		// getters------------------------------------------------------
			double getSalary() {return salary;}
	
		// determine weekly pay-----------------------------------------
			// FORMULA:  paycheck = Annual Salary / 52
			double getWeeklyPay()
			{ // start getWeeklyPay
				weeklyPay = salary / ANNUAL;
				return weeklyPay;
			} // end getWeeklyPay
	
	}; // end class definition
#endif
