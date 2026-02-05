#include "LinkedList.h"
#include <iostream>
using namespace std;
int main() {
	
	LinkedListType<int> myList;

	myList.insertFront(13);
	myList.insertFront(86);
	myList.insertFront(17);
	
	myList.printList();
	
	//~ int i = 1;
	//~ while( i < 10) {
		//~ myList.insertFront(i*i);
		//~ i++;
	//~ }//end while
	if (myList.search(256)) cout << "Found." << endl;
	else cout << "Not found." << endl;
	
	//delete 17 from list
	myList.deleteItem(17);
	
	myList.printList();
	return 0;
}//end main
