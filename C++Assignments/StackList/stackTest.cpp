#include "StackList.h"
#include <fstream>
#include <iostream>
using namespace std;


int main() {


    ifstream input("inputFile.txt");//create input stream from data file

    if (!input) { //something bad happened while opening file
        cout << "Error opening file (missing file?). Exiting." << endl;
        return 1;
    }

    StackList<int> myStack;//stores the data in the file

    int value;
    input >> value;//get first integer from file
    while(input) {//keeps going as long as we can read integers from file
        myStack.push(value);//add value to my list
        input >> value;//get next value from file
    }//end processing file        
    cout << "Stack created." << endl;
   
    //now print the list
    cout << "Length of stack is: " << myStack.getLength() << endl;
    cout << "Contents of stack: " << endl;
    myStack.printList();

    cout << "Top value is: " << myStack.getStackTop() << endl;

    //pop an element
    myStack.pop();
    
    //now print the list
    cout << "Length of stack is: " << myStack.getLength() << endl;
    cout << "Contents of stack: " << endl;

    myStack.printList();

    return 0;
}//end main
