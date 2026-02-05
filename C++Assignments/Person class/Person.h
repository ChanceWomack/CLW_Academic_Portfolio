#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class Person {
	private:
		std::string fName;//composition!
		std::string lName;//composition!
	public:
		std::string getFName() const { return fName; }
		std::string getLName() const { return lName; }
		void setFName(std::string fn) { fName = fn; }
		void setLName(std::string ln) { lName = ln; }
		
		Person() {
			fName = "*";
			lName = "*";
		}//default constructor
		Person(std::string fn, std::string ln)// : fName(fn), lName(ln)
		{ 
			fName = fn;
			lName = ln;
		}
		friend std::ostream& operator<<(std::ostream& out, const Person& p)
		{
			out << p.fName << " " << p.lName;
			return out;
		}//end overloaded stream insertion
		friend std::istream& operator>>(std::istream& in, Person& p) {
			in >> p.fName;
			in.ignore(1);//ignore space??
			in >> p.lName;
			return in;
		}//end overloaded stream extraction
		
		std::string getName() {return fName + " " + lName;} // modification adding getName function
		
};//end class definition
#endif
