#ifndef DateType_H_
#define DateType_H_
#include <iostream>
#include <iomanip>
using namespace std;
class DateType
{
private:
	int month;
	int day;
	int year;
public:
	friend istream& operator>>(istream&, DateType&);
	bool isLeapYear();
	bool operator==(const DateType&) const;
	friend ostream& operator<<(ostream&, const DateType&);
	DateType();
	DateType(int,int,int);
	void setDate(int,int,int);
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	 ~DateType();
};
istream& operator>>(istream& in, DateType& d) {
	char dummy;
	int value;
	in >> value;
	d.setMonth(value);
	in >> dummy; //read the '/'
	in >> value;
	d.setDay(value);
	in >> dummy; //read the '/'
	in >> value;
	d.setYear(value);
	return in;
}//end >> input
bool DateType::operator==(const DateType& otherDate) const
{return (otherDate.month == month &&
		otherDate.day == day &&
		otherDate.year == year);}
ostream& operator<<(ostream& out, const DateType& d) {
	out << setfill('0') << setw(2) << d.getMonth()
	    << "/"
	    << setw(2) << d.getDay()
	    << "/"
	    << setw(4) << d.getYear();
	out << setfill(' ');//return fill to the space
	return out;
}//end << output
DateType::DateType() {
	setMonth(1);
	setDay(1);
	setYear(2009);
}
DateType::DateType(int m, int d, int y){
	setMonth(m);
	setDay(d);
	setYear(y);
}
void DateType::setDate(int m, int d, int y){
	setMonth(m);
	setDay(d);
	setYear(y);
}
int DateType::getMonth() const { return month; }
int DateType::getDay() const { return day; }
int DateType::getYear() const { return year; }
void DateType::setMonth(int m) {
	if (m > 0 && m < 13)
		month = m;
	else {
		std::cerr << "INVALID MONTH, using default 1\n";
		month = 1;
	}
}
void DateType::setDay(int d) {
	bool bad_day = false;
	switch(month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: if(d > 0 && d < 32)
					day = d;
				 else bad_day = true;
				 break;
		case 2: if(d > 0 && d < 29)
					day = d;
				else bad_day = true;
				break;
		case 4:
		case 6:
		case 9:
		case 11: if(d > 0 && d < 31)
					day = d;
				 else bad_day = true;
				 break;
		default: std::cerr << "Unknown month!\n";
	}
	if(bad_day) {
		std::cerr << "INVALID DAY, using default 1\n";
		day = 1;
	}
}//end setDay
void DateType::setYear(int y) {
	year = y;
}
bool DateType::isLeapYear() {
	
	if((year % 400 == 0 && year % 100 != 0) || year % 4 == 0)
		return true;
	else
		return false;
}
DateType::~DateType() {
}
#endif /*DateType_H_*/
