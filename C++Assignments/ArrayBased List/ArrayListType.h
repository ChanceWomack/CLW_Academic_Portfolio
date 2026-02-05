/* Chance Womack
 * Lab 4: Array Based Lists
 * Goal:
 * Create an ArrayListType class that implements a list using an array (pointer).
 * Allocate the storage for the data on the heap. You should choose a default size for the list of 25.
 * Include methods for insertion (insert), deletion (deleteItem), and searching (search) for an item.
 * Also include a method for getting the length of the list (getLength) and printing the contents (printList).
 */

#ifndef H_ARRAYLISTTYPE // rename to current class name
#define H_ARRAYLISTTYPE
#include <iostream>
#include <iomanip>

template <class T>
class ArrayListType
	{ // start class definition
	private:
	// Data Members
		T *data; // pointer for the array on the heap
		int length; // current length of "filled" indices
		int currentSize; // used for setting the "max" size of the array
	public:
	// methods	
		// Constructors/Deconstructor-----------------------------------
			ArrayListType()
				{ // start default
					currentSize = 25;
					data = new T[currentSize];
					length = 0;
				} // end default
				
			ArrayListType(int s)
				{ // start specific
				if ( s > 0 ) currentSize = s;
				else currentSize = 25;
					data = new T[currentSize];
					length = 0;
				} // end specific

			~ArrayListType() {delete [] data;} // deconstructor

		// Class Specific Methods---------------------------------------
			bool isEmpty() const {return length == 0;}
			void insert(T item)
				/* must increment length counter
				 * must account for going beyond the size of the array
				 */
			{ // start insert
				if ( length == currentSize )
				{ // start outer if
					T *temp = data; // copy current array
					currentSize *= 2; // double array size
					data  = new T[currentSize];
					for (int i = 0 ; i < length ; i++)
					{ // start inner if
						data[i] = temp[i]; // copy over data
					} // end inner if
				} // end outer if
				data[length++] = item; // adds item and increments length
			} // end insert
			
			void deleteItem(T item)
				/* must decrement length counter
				 * return error if the deleted item doesn't exist
				 * should move all items back 1 to fill
				 * delete via override
				 */
			{ // start delete method
				int foundIndex = -1;
				for (int i = 0 ; i < length ; i++) // cycle through each index
				{ // start deletion
					if ( data[i] == item ) // check if current index is matches the item
						{ // start found
						foundIndex = i;
						for (int m = foundIndex; m < length ; m++)
							{
								data[m] = data[m+1]; // move all data down one index --- overriding the deleted item in the process
							}
						length--; // decrement length counter
						break;	 // stop searching once the first instance is found
						} // end found
					} // end deletion
			} // end delete method
			
			bool search(T item) const
			{ // start search
				for (int i = 0 ; i < length ; i++) // cycle through each index
					if ( data[i] == item ) // check if current index is matches the item
						return true; // return true if they match
				return false; // return false if no matches are found ----- error message???
			} // end search

			void printList() const
			{ // start print
				for (int i = 0 ; i < length ; i++)
					std::cout << "Slot " << i+1 << " : " << data[i] << std::endl;
			} // end print
			
			// getters
			int getLength() const {return length;} // returns the current value of length
			int getCurrentSize() const {return currentSize;} // returns the current value of currentSize
			

	}; // end class definition
#endif
