/* Chance Womack
 * Lab 7 - Queues
 * Goal:
 * Given the abstract class UnorderedLinkedList (found on moodle,
	UnorderedLinkedList.h), implement the template class QueueList so that the test
	program works correctly.
 * You will need to derive the QueueList class from the
	UnorderedLinkedList class and provide methods for add(), remove(), front()
	[returns the value at the front of the list], and back() [returns the value at the end of the list].
 */
#ifndef QUEUELIST_H
#define QUEUELIST_H
// include desired libraries
#include <iostream>
#include "UnorderedLinkedList.h"
template<typename T>
class QueueList : public UnorderedLinkedList<T>
{ // start def
	public:
		// methods
			// deconstructor
				~QueueList() {}
			// add------------------------------------------------------
				// adds an item to the BACK of the queue
				void add(T item)
				{ // start add
						if(this->isEmpty())
							{ // if queue is empty
								this->insert(item);
								return;
							} // end if
						else
							{ // if not empty
								NodeType<T> *newNode = new NodeType<T>(item);
								this->last->next = newNode;
								this->last = newNode;
								return;
							} // end else					
				} // end add
			// remove---------------------------------------------------
				// removes an item from the FRONT of the queue
				void remove()
				{ // start remove
					if (this->isEmpty())
						{return;} // nothing to remove
					else
						// use the delete method from the parent class and pass it the front item
						{this->deleteItem(this->front());
						 return;}
				} // end remove
			// getfront-------------------------------------------------
				// returns the value of the FRONT position
				T front() const
				{ // start front
					return this->first->data;
				} // end front
			// getback--------------------------------------------------
				// returns the 
				T back() const
				{ // start back
					return this->last->data;
				} // end back
}; // end def
#endif
