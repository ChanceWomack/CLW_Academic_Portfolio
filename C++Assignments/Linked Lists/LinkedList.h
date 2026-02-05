// made by professor

#ifndef LINKEDL_H
#define LINKEDL_H
#include "NodeType.h"
#include <iostream>
template <typename T>
class LinkedListType {
	
	public:
		NodeType<T> *head = nullptr;
		
		void insertBack(T item) {
			NodeType<T> *current = head;
	
			NodeType<T> *newNode = new NodeType<T>(item);

			//newNode -> data = item;
			//std::cout << newNode->data << std::endl;//print the address?
			
			if ( head == nullptr )//list is empty
				head = newNode;
			else { //not empty so add at end
				current = head;
				while ( current->next != nullptr) {
					current= current->next;
				}//end while
				//attach at end
				current->next = newNode;
			}
		}//end insert Back Method
		
		void insertFront(T item) {
	
			NodeType<T> *newNode = new NodeType<T>(item);
			
			newNode -> next = head;
			head = newNode;
			
		}//end insert Front Method
		
		void deleteItem(T item) {
			//find the item to delete, keeping track of previous node
			NodeType<T> *current = head;
			NodeType<T> *trail = current;
			while (current != nullptr && current->data != item) {
				trail = current;
				current = current->next;
			}//end while
			//at this point, current is pointing at the item to delete,
			//trail is pointing at the previous node
			//what if not found, current will be NULL
			//check if we are deleting the first item in the list
			if (current == nullptr) { std::cout << "ERROR: Dereferencing NULL Pointer"; return; } // error catch
			
			if (current == head) { //trying to delete the first item
				head = current ->  next;
				delete current;
			} else {
				trail -> next = current -> next;
				delete current;
			}//end else clause

		}//end deleteItem method
		
		bool isEmpty() const {
			return (head == nullptr);
		} //is list empty or not
		
		bool search(T item) const {
			NodeType<T> *current = head; //start at beginning
			//check if found
			while (current != nullptr && current -> data != item) 
				current = current -> next;//not found, go to next
			//at this point we found the item so current points at that
			//node, otherwise, current is null
			return (current != nullptr);
		}//end search method
		
		void printList() const {
			NodeType<T> *current = head;
			while ( current != nullptr ) {
				std::cout << current -> data << std::endl;
				current = current -> next;
			}//end while
		}//end printList method
		
		void clearList() {
			NodeType<T> *current =head;
			while ( head != nullptr ) {
				current = head;
				head = head -> next;
				delete current;
			}// end while
		} // end clearList
		
};//end class
#endif
