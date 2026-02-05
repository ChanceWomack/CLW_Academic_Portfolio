/* Chance Womack
 * Proj 5 -- Appointment Manager
 * Goal
 * 
 * Utilize COMPOSITION
 * Create a program that will manage appointments from a text file.
 * The appointments will be located in a text file named “my_appointments.txt” and will have 3 lines per appointment
 * 		Date
 * 		Time
 * 		Description
 * 
 * Your manager should support viewing/listing all appointments,
 *  adding an appointment, deleting an appointment,
 *  and quitting your program (save all changes to the file “my_appointments.txt”)
 * 
 * You MUST use some dynamic data structure like a linked list, stack, or queue. 
 * 
 * Note that code for all three are available in your book, and examples are provided on Moodle,
 *  so you should only have to do minor editing to get that code to work.
 * You can also use any pre-existing dynamic structures (like vectors) available from C++,
 *  but check to make sure they are available on the instructor’s grading system.
 * 
 * Upload a zip file containing all of your code through moodle by 11:55pm on Friday November 11.
 */
// CHECKLIST						Progress (x = none, n = noted, s = started, f = functioning)
	/* Reads from File	(load)			f
	 * Constructs Vector				f
	 * Lists Appointments in File		f
	 * Adding							f
	 * Deleting							f
	 * Saves to file						f
	 */
#ifndef APPOINTMENTMANAGER_H
#define APPOINTMENTMANAGER_H
// include desired libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Appointment.h"

class AppointmentManager
{ // start def
	private:
		// data members
			//Using a vector to contain the appointments read from the file
			string fName;
			vector<AppointmentType> list;
	public:
		// methods
			// Default Constructor...No File is provided in call...-----
				AppointmentManager()
				{ // start default constructor
					fName = "default_appointments.txt";
					menu();
				} // end default constructor
			// Specific Constructor--------------------------------------
				// creates data storage and calls the Read File method to fill the vector
				// should take the file name as its parameter
				AppointmentManager(string s)
				{ // start specific constructor
					fName = s;
					load(fName);
				} // end specific constructor
			// Deconstructor--------------------------------------------
				~AppointmentManager() {}

			// Read File (Loading)--------------------------------------
			void load(string s)
				{ // start loading process
					list.clear(); // clears the vector before loading
					ifstream inFile;
					inFile.open(s);
					if ( !inFile )
					{ // open failed
						std::cerr << "Error opening file: terminating" << endl;
						return;
					}// end termination	
					// get data from inFile
					// put inside a while loop
					//int c = 0; //test
					AppointmentType current; // create new appointment
					//std::cout << "current made" << std::endl; //test
					inFile >> current;
					//std::cout << "filled initial current" << std::endl; //test
					while(inFile)
					{ // start while
						list.push_back(current); // push new appointment
						//std::cout << "added current " << c << std::endl; //test
						// after pushing the new appointment, loop back to start
						inFile >> current;
						//std::cout << "filled current " << ++c << std::endl; //test
					} // end while
					//close inFile after loading is done
					inFile.close();
					return;
				} // end loading process

			// Write to File (Saving)-----------------------------------
				// Separate Save && Exit option?
				// write the current vector to the file
				// override pre-existing file contents
				
				void save(string s)
				{ // start save process
					ofstream outFile;
					outFile.open(s);
					int size = list.size();
						for(int x=0; x < size; x++)
						{ // start while
							outFile	<< list.at(x).getDate() << std::endl
									<< list.at(x).getTime() << std::endl
									<< list.at(x).getDesc() << std::endl;
						} // end while
					outFile.close();
					return;
				} // end save process

			// Adding an Appointment------------------------------------
				// create appointment then add it to the vector
				void add()
				{ // start addition
					AppointmentType a;
					std::cout << "Enter your appointment (date, time, description): ";
					std::cin >> a;
					for(int i = 0 ; i < int(list.size()) ; i++)
					{ // start for -- conflict checking
						if(list.at(i).getDate() == a.getDate() && list.at(i).getTime() == a.getTime())
						{ // start if -- check for conflicting date and time
							std::cout << "ERROR: This Appointment Conflicts with an Existing Appointment" << std::endl;;
							return;
						} // end if
					} // end if
					list.push_back(a);
					return;
				} // end addition
				
			// Removing an Appointment----------------------------------
				// remove from vector by index
				void deleteAppointment()
				{ // start deletion
					int target;
					std::cout << "Please enter the number of the appointment you wish to delete (0 to abort): ";
					std::cin >> target;
					if (target <= 0) // abort deletion option
						return;
					if(target <= int(list.size())) // item found, proceed with deletion
					{ // start if
						std::cout << std::endl;
						list.erase(list.begin()+(target-1));
						return;
					} // end if
					else
					{ // start else -- item not found, terminate deletion
						std::cout << "Appointment not found" << std::endl << std::endl;
						return;
					} // end else
					
				} // end deletion
				
			// Overloaded Insertion-------------------------------------
					friend std::ostream& operator<<(std::ostream& out, AppointmentManager& m)
					{ // start of the operator overload
						int size = m.list.size();
						std::cout << "List of Appointments in " << m.fName << std::endl << std::endl;
						for(int x=0; x < size; x++)
						{ // start while
							out << "Appointment " << x+1 << std::endl
								<< m.list.at(x)
								<< std::endl;
						} // end while
						return out;
					} // end of the operator overload

			// Menu Display---------------------------------------------
				/* Display Options
				 * View Appointments
				 * Add Appointment
				 * Remove Appointments
				 * Save Changes
				 * Save & Exit
				 * Exit without saving
				 * Use a Switch statement to handle options by calling the appropriate methods
				 */
				void menu()
				{ // start menu
					int select; // declare selection variable
					do
					{ // start do
						// print menu
						std::cout << "---Appointment Manager Menu---" << std::endl << std::endl
								  << "1: Display Appointments" << std::endl
								  << "2: Load a File (Please save changes before loading a new file)" << std::endl
								  << "3: Add an Appointment" << std::endl
								  << "4: Delete an Appointment" << std::endl
								  << "5: Save Changes" << std::endl
								  << "6: Save Changes & Exit Manager" << std::endl
								  << "7: Exit Manager without Saving" << std::endl << std::endl
								  << "Please select an option using its number: ";
						std::cin >> select; // get value of selection variable from user
						std::cout << std::endl << "____________________________________________________" << std::endl << std::endl;
						// process selection
						switch(select)
						{ // start switch
							case 1: std::cout << *this;
									break;
							case 2: std::cout << "Please enter the name of the file with any extension: ";
									std::cin >> fName;
									load(fName);
									break;
							case 3: add();
									break;
							case 4: deleteAppointment();
									break;
							case 5: save(fName);
									break;
							case 6: save(fName);
									return;
							case 7: return;
						} // end switch
					} // end do
					while(select != 6 || select != 7);
					return;
				} // end menu		
}; // end def
#endif
