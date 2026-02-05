#include "UnorderedLinkedList.h"
#include <fstream>
#include <iostream>
using namespace std;


int main() {


    ifstream input("inputFile.txt");//create input stream from data file

    if (!input) { //something bad happened while opening file
        cout << "Error opening file (missing file?). Exiting." << endl;
        return 1;
    }

    UnorderedLinkedList<int> myList;//stores the data in the file

    int value;
    input >> value;//get first integer from file
    while(input) {//keeps going as long as we can read integers from file
        myList.insert(value);//add value to my list
        input >> value;//get next value from file
    }//end processing file        
    cout << "List created." << endl;
    //delete first occurence of the value 50
    myList.deleteItem(50);  

    //search for a value (not in the list)
    if(myList.search(256)) cout << "Found 256" << endl;
    else cout << "256 not in the list" << endl;
    
    //now print the list
    cout << "Length of list is: " << myList.getLength() << endl;
    cout << "Contents of list: " << endl;

    myList.printList();

    return 0;
}//end main
