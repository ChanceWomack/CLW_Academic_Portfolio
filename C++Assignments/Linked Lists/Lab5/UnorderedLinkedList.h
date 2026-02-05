/* Chance Womack
 * Lab 5: Linked Lists (not array based)
 * Given the abstract class LinkedList (found on moodle in the lab section, LinkedList.h),
 * -> implement the template class UnorderedLinkedList so that the test program works correctly.
 * You will need to derive the UnorderedLinkedList class from the LinkedList class
 * -> and provide methods in the derived class for any virtual methods that exist in the base class.
 */

#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

// include desired libraries and the base class
#include <iostream>
#include "LinkedList.h"

template <class T>
class UnorderedLinkedList: public LinkedList<T>
{ // start class def
	public:
		// methods
			// defined virtual methods
				
				void insert(T item)
				{ // start insert
					NodeType<T> *newNode = new NodeType<T>(item);
					if (this->isEmpty()) // if list was empty
					{ // start if
						this->first = newNode;
						this->last = newNode;
					} // end if
					else // adding an item to the front of the list
					{ // start else					
						newNode -> next = this->first;
						this->first = newNode;
					} // end else
				}//end insert
			
				void deleteItem(T item)
				{ // start delete
					//find the item to delete, keeping track of previous node
					NodeType<T> *current = this->first;
					NodeType<T> *trail = nullptr;
					while (current != nullptr && current->data != item)
					{ // start while
						trail = current;
						current = current -> next;
					}//end while
					if (current == nullptr) { return; } // what if list is empty or item not in the list
					
					if (current == this->first) // What if the item is first on the list
					{ // start if
						this->first = current -> next;
						delete current; return;
					} // end if
					
					if (this->first == this->last) // what if item is the only item in the list
					{ // start if
						this->first = nullptr;
						this->last = nullptr;
						delete current; return;
					} // end if
					
					if (current -> next == nullptr) // what if item was last on the list
						{ //start if
							trail -> next = nullptr;
							this->last = trail;
							delete current; return;
						} // end if
						
					else // what if item was in the middle
						{ // start inner else
							trail -> next = current -> next;
							delete current;
						} // end inner else
				}//end delete 
			
			
				bool search(T item) const
				{ // start search
					NodeType<T> *current = this->first; //start at beginning
					//check if found
					while (current != nullptr && current -> data != item) 
						current = current -> next; //not found, go to next
					// once the while loop returns false, the item has been found
					return (current != nullptr);
				}//end search 
			
	
}; // end class def
#endif
