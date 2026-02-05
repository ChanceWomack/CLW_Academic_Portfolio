 /* Chance Womack
 * Lab 6: Stacks
 * Goal
 * Given the abstract class UnorderedLinkedList (found on moodle,
UnorderedLinkedList.h), implement the template class StackList so that the test
program works correctly. You will need to derive the StackList class from the
UnorderedLinkedList class and provide methods for push(), pop(), and top().
*/
#ifndef STACKLIST_H
#define STACKLIST_H
// include desired libraries
#include <iostream>
#include "UnorderedLinkedList.h"
template<typename T>
class StackList : public UnorderedLinkedList<T>
{ // start def
	public:
	// methods
		// push method--------------------------------------------------
		void push(T item) { this->insert(item); }
		// pop method---------------------------------------------------
			// deletion but only deletes the top of the stack (first pointer)
		void pop() { if(this->isEmpty()) return; this->deleteItem(getStackTop()); }
		// getStackTop method-------------------------------------------
			// PRECONDIITON: stack is NOT empty
		T getStackTop() const {return this->first->data;}
}; // end def
#endif
