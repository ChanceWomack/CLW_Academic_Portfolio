/* Jacob Somervell
 * TimeType class - feel free to use this if you are not happy with your own
 *
 */
#ifndef TIME_H_
#define TIME_H_
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
//a time consists of hour, minute, second
//and AM/PM
//military time (24hour)
//normal/regular (12 hour)
//hour can have the value 0-23
//minute can have value 0-59
//second can have value 0-59
class TimeType {
private:
	int hour;
	int minute;
	int second;

public:
	friend ostream& operator<<(ostream&, const TimeType &);
	friend istream& operator>>(istream&, TimeType &);
	bool operator==(const TimeType&) const;
	bool operator!=(const TimeType&) const;
	void tick();//increments seconds by 1
	int getHour();
	int getMinute();
	int getSecond();
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	TimeType(int, int, int); //constructor
	//this constructor takes 3 pieces of information
	TimeType();	
	virtual ~TimeType();//deconstructor
	
	
	
	
	//added this
	//operator == overload
	bool operator==( TimeType& otherTime)  {
			return this->hour == otherTime.hour &&//checks if hours are same
				   this->minute == otherTime.minute &&//checks if minute are same
				   this->second == otherTime.second;//checks if seconds are same
				   
			//if all true then return
		}

};
//constructor takes hour (h), minute (m),
//and second (s) and uses that to initialize
//the private data members
TimeType::TimeType(int h, int m, int s)
{
	//we really should check that h, m, and s
	//are valid, how would we do that?
	setHour(h);
	setMinute(m);
	setSecond(s);
}
//default constructor
TimeType::TimeType() {hour=0;minute=0;second=0;}

TimeType::~TimeType()
{
    //empty
}
//tick function/method
void TimeType::tick(){
//need to increment seconds by 1
	second++;
	//did I go over 59?
	if (second > 59) {
		minute++;
		second=0;
		//did minutes go over 59, if so add to hour
		if (minute > 59) {
			hour++;
			minute=0;
			//did hour go over 23, if so reset to 0
			if(hour > 23){
				hour=0;
			}
		}
	}
}//end tick method

int TimeType::getHour() {
	return hour;
}
int TimeType::getMinute() {
	return minute;
}
int TimeType::getSecond() {
	return second;
}
void TimeType::setHour(int h) {
	hour = (h >= 0 && h<24)? h : 0;
}
void TimeType::setMinute(int m) {
	minute = (m >=0 && m < 60) ? m : 0;
}
void TimeType::setSecond(int s) {
	second = (s >= 0 && s < 60) ? s : 0;
}
bool TimeType::operator==(const TimeType &otherTime) const {
	return (otherTime.hour == hour &&
		otherTime.minute == minute &&
		otherTime.second == second);
}//end == operator
bool TimeType::operator!=(const TimeType &otherTime) const {
	return (otherTime.hour != hour &&
		otherTime.minute != minute &&
		otherTime.second != second);
}//end == operator
ostream& operator<<(ostream &out, const TimeType &t) {
    if (!out) return out;
	out << setw(2) << setfill('0');
	out << t.hour << ":"
	    << setw(2) << t.minute << ":"
	    << setw(2) << t.second;
	out << setfill(' ');
	return out;
}//end overloaded stream insertion operator

istream& operator>>(istream &in, TimeType &t) {
    int tempVal;
	in>>tempVal;
    if (!in) return in;
    t.setHour(tempVal);
	in.ignore(1);//ignore ':'
	in>>tempVal;
    if (!in) return in;
    t.setMinute(tempVal);
	in.ignore(1);//ignore ':'
	in>>tempVal;
    if (!in) return in;
    t.setSecond(tempVal);
	return in;
}
#endif /*TIME_H_*/
