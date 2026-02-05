#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
#include "NodeType.h"

//notice that this class has virtual methods for insert, deleteItem, and searching

template <class Type>
class LinkedList {
	protected:
    //notice that we are keeping a pointer to the last item in the list
    // (it simplifies some things)
        NodeType<Type> *first = 0;//point at first item
        NodeType<Type> *last = 0;//point at last item
    public:
        ~LinkedList();//destructor to ensure memory is reclaimed
        virtual void insert(Type) = 0;
        virtual void deleteItem(Type) = 0;
        virtual bool search(Type) const = 0;
        bool isEmpty() const;
        void clearList();//reset list to empty
        int getLength() const ;//return length of list
        void printList() const;//print the list to the screen
};
template<class Type>
LinkedList<Type>::~LinkedList(){
    clearList();//using method to clear list
}
template<class Type>
bool LinkedList<Type>::isEmpty() const {
    return first == 0;
}

template <class Type>
void LinkedList<Type>::clearList() {
    NodeType<Type> *current = first;
    while (first != nullptr) {
        first = current -> next;//point at next node
        delete current; //free up the memory
        current = first;//move current along
    };//end while
    last = nullptr; //make sure last is also pointing at null
    //at this point the list should be empty
}//end clearList method

template <class Type>
int LinkedList<Type>::getLength() const {
    int count = 0;
    NodeType<Type> *current = first;
    while (current != nullptr) {
        count++;//add one to size
        current = current -> next;//move along to next
    }//end while
    return count;
}//end getLength method

template <class Type>
void LinkedList<Type>::printList() const {
    NodeType<Type> *current = first;
    while (current != nullptr) {
        cout << current -> data << endl;
        current = current -> next;//move along to next
    }//end while
}//end printList method
#endif
