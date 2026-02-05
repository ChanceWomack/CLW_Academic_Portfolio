#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <iostream>
#include <string>
//This class illustrates inheritance. A Student "is a" Person.

class Student : public Person {
	private:
		std::string idNum;
		double GPA;
	public:
	//getters
		double getGPA() const { return GPA; }
		std::string getIdNum() const { return idNum; }
	//setters
		void setGPA(double gpa) { GPA = gpa; }//need verification?
		void setIdNum(std::string id) { idNum = id; }//verify?
	//constructor
		Student() { 
			//empty body
			GPA = 0.0;
			idNum = "*";
		}
	//overloads
		friend std::ostream& operator<<(std::ostream& out, const Student& s) {
			//std::cerr << "Inside the stream insertion function." << std::endl;
			//std::cin.get();//wait for the user to type something
			out << (Person)s << std::endl;
			out << s.idNum << "--" << s.GPA;
			return out;
		}//end overloaded stream insertion
};//end class
#endif
