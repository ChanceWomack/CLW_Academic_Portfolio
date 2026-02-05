/* Chance Womack
 * Stack Type
 */

#ifndef H_STACKTYPE
#define H_STACKTYPE
#include <iostream>

// declare constants
const int DEFAULTSIZE = 25;

template<typename T>
class StackType
{ // start def
	private:
	// data members
		int currentSize;
		int top;
		T *data;
	public:
	// methods
		// constructor--------------------------------------------------
			StackType () {}
		// deconstructor------------------------------------------------
			~StackType () {delete [] data;}
		// insertion----------------------------------------------------
			void push(T item)
			{ // start puch
				if (top == currentSize)
				{ // start if
					T *temp = data; // point to existing data for storage
					currentSize *= 2; // double the size of the stack
					data = new T[currentSize];
					// copy exist data
					for (int i = 0 ; i < top ; i++)
						data[i] = temp[i];
					delete [] temp;
				} // end if
				data[top++] = item;
			} // end push
		// deletion-----------------------------------------------------
			void pop()
			{ // start pop
				if (top == 0) return;
				top--;
				data[top]=0;
			} // end pop
		// other methods------------------------------------------------
			T getStackTop() const { if (!isEmpty()) return data[top-1]; return (T)0;} // get the data of the top of the stack
			bool isEmpty() const {return top == 0;} // checks to see if the stack is empty
			bool isFull() const { if (top == currentSize) return;} // checks to see if the stack is full
			int getLength() const { return top + 1; } // returns the current size of the stack
			void printStack() const
			{ // start print
				for(int i = 0 ; i < top ; i++)
					std::cout << data[i] << " ";
				std::cout <<  std::endl;
			} // end print
}; // end def
#endif
