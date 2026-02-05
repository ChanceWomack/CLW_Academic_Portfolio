/* Test program for lab 3.
   Creates two employees (one salaried, one hourly)
   Prints out information for each
   Jacob Somervell
*/

#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    SalariedEmployee karen("Karen", "Jones",  "13579", 50000);
                           //name            //id   //salary
    HourlyEmployee chad("Chad", "Thompson", "24680", 12.75, 44);
                        //name             //id   //rate  //hours

    cout << "Employee: " << karen.getName() << endl
         << "Weekly pay: " << fixed << setprecision(2) << karen.getWeeklyPay() << endl;

     cout << "Employee: " << chad.getName() << endl
          << "Weekly pay: " << fixed << setprecision(2) << chad.getWeeklyPay() << endl;

    return 0;
}//end main
