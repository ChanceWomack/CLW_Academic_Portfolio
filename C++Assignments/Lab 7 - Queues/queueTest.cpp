#include "QueueList.h"
#include <fstream>
#include <iostream>
using namespace std;


int main() {


    ifstream input("inputFile.txt");//create input stream from data file

    if (!input) { //something bad happened while opening file
        cout << "Error opening file (missing file?). Exiting." << endl;
        return 1;
    }

    QueueList<double> aQueue;//stores the data in the file

    double value;
    input >> value;//get first value from file
    while(input) {//keeps going as long as we can read values from file
        aQueue.add(value);//add value to queue
        input >> value;//get next value from file
    }//end processing file 
    input.close();       
    cout << "Queue created." << endl;
   
    //now print the list
    cout << "Length of queue is: " << aQueue.getLength() << endl;
	if (!aQueue.isEmpty()) {
    cout << "Value of front is: " << aQueue.front() << endl;
    cout << "Value of back is: " << aQueue.back() << endl;}
    cout << "Contents of Queue: " << endl;
    aQueue.printList();

    //remove an element
    aQueue.remove();
    
    //now print the list
    cout << "Length of queue is: " << aQueue.getLength() << endl;
    cout << "Contents of queue: " << endl;

    aQueue.printList();

    return 0;
}//end main
