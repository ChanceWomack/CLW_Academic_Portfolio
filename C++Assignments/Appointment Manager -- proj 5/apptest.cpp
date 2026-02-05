#include "Appointment.h"
#include "DateType.h"
#include "TimeType.h"
#include <iostream>
using namespace std;

int main() {
	TimeType aTime(3,20,00);
	DateType aDate(5,4,3000);
	
	AppointmentType myAp, yourAppt(aDate,aTime,"something cool");
	
	cout << "The starting appointments are: " << endl;
	cout << myAp << endl << yourAppt;
	cout << endl;
	cout << myAp.getDate();
	cout << "Enter your appointment (date, time, description):";
	cin >> myAp;
	cout << "You entered the following data:\n";
	cout << myAp << endl;
	//yourAppt = myAp;

	if(myAp == yourAppt)
		cout << "They are the same!" << endl;
	else
		cout << "They are different!" << endl;

	return 0;
}
