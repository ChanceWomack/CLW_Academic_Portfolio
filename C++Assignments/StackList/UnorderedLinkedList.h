#ifndef UNORDERED_H
#define UNORDERED_H

#include "LinkedList.h"

template <typename T>
class UnorderedLinkedList : public LinkedList<T> {
	public:
	
	   void insert(T item) { 
		   NodeType<T> *newNode = new NodeType<T>(item);
		   
		   if ( this->isEmpty() ) {
			   this->first = newNode;
			   this->last = newNode;
		   } else {
			   //add at front
			   newNode->next = this->first;
			   this->first = newNode;
		   }
	   }//end insert method
	   
	   void deleteItem(T item) { 
		   //find the item first
		   NodeType<T> *current = this->first;
		   NodeType<T> *trail = nullptr;
		   while ( current != nullptr && current->data != item) {
			   trail = current;
			   current = current -> next;
		   }//end while
		   //what if list was empty, or not in the list?
		   if ( current == nullptr ) return;
		   //what if item was the only item in the list?
		   if ( this->first == this->last ) {
			   this->first = nullptr;
			   this->last = nullptr;
			   delete current; return;
		   }
		   //what if item was the first item in the list?
		   if ( current == this->first ) {
			   this -> first = current->next;
			   delete current; return;
		   }
		   //what if item was the last item in the list?
		   if ( current == this->last ) {
			   trail->next = current-> next;
			   this->last = trail;
			   delete current; return;
		   }
		   //what if item is in the middle?
		   trail->next = current-> next;
		   delete current;
		   return;
	   }//end delete method
	   bool search(T item) const { 
		   NodeType<T> *current = this->first;
		   while ( current != nullptr && current->data != item) {
			   current = current -> next;
		   }//end while
		   return current != nullptr;
	   }//end search method
};//end class definition
#endif
