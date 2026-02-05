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
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include <string>
#include <iostream>
#include "Employee.h"

// declare constants

const double WORKWEEK = 40.0;
const double OVERTIMERATE = 1.5;

class HourlyEmployee : public Employee
	{ // start class definition
	private:
	// Data Members
		Employee emp;
		double wage;
		double hoursWorked;
		double weeklyPay = 0; // weekly pay always starts at 0
	public:
	// methods
		// Constructor
		HourlyEmployee(std::string fn, std::string ln, std::string id, double w, double h)
			: Employee(fn, ln, id)
			{ // start of constructor
				setWage(w);
				setHoursWorked(h);
			} // end of constructor		
		// setters
			void setWage(double w) {wage = w;}
			void setHoursWorked(double h) {hoursWorked = h;}
						
		// getters
			double getWage() {return wage;}
			double getHoursWorked() {return hoursWorked;}
			
		// determine weekly pay
			// FORMULA:  if hoursWorked <= 40: paycheck = Wage * hoursWorked
			// OVERTIME: Wage*1.5 for every hour beyond 40
			double getWeeklyPay()
			{ // start getWeeklyPay
				if (hoursWorked > WORKWEEK)
					weeklyPay = ((hoursWorked-WORKWEEK)*(wage*OVERTIMERATE)) + (WORKWEEK*wage);
				else
					{weeklyPay = hoursWorked*wage;}
				return weeklyPay;
			} // end getWeeklyPay
			
	}; // end class definition
#endif
