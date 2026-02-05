/* Chance Womack
 * Lab 10 - Max Heap
 * GOALS
 * You will need to create a class that implements a MaxHeap (MaxHeap.h).
 * 
 * Your class will keep/store an array (pointer) that represents the heap, along with its size.
 * 
 * Your class needs to provide a method that allows inserting an item into the heap.
 * 
 * Your class needs to provide methods to allow a user to provide any array (with its
size), and your class will convert that to a heap.
 * 
 * You also need a method to print the array for visual inspection to verify that it is a heap.
 * 
 * Your class needs to work with the provided test program (HeapTest.cpp).
 */
#ifndef MAXHEAP_H
#define MAXHEAP_H


// Include Desired Libaries
#include <iostream>

class MaxHeap
{ // start def
	private:
		// date members
			int *heap; // array to hold data
			int size; // size of the array
			int heapSize; // size of the heap
			void heapify()
			{ // start
				/*steps
				 * 1: Find index of last non-leaf node
				 * 2: verify that the max heap property holds
				 * 3: check all non-leaf nodes, back to the root
				 * 4: repeat steap 1-3 enough times to guarantee a heap
				 */
				int nonleaf = heapSize / 2 - 1; // Find index of last non-leaf node
				int largest = 0; // keep track of the largest index
				for (int j = 0 ; j <= nonleaf+1 ; j++)
				{ // start for loop
					for (int index = nonleaf ; index >= 0 ; index--)
					{ // start for
						int left = index * 2 +1; // left child
						int right = index * 2 +2; // right child
						if (left < heapSize && heap[largest] < heap[left])
							largest = left;
						if (right < heapSize && heap[largest] < heap[right])
							largest = right;
						if (largest != index)
						{ // start if
							int temp = heap[index];
							heap[index] = heap[largest];
							heap[largest] = temp;
						} // end if
					} // end for
				} // end for loop
				return;  
			} // end
	public:
		// methods
			// constructor----------------------------------------------
				MaxHeap()
				{ // start constructor
					size = 25; // default size
					heapSize = 0;
					heap = new int[size];
				} // end constructor
				
			// deconstructor--------------------------------------------
				~MaxHeap()
				{ // start deconstructor
					delete [] heap;
				} // end deconstructor
				
			// creation-------------------------------------------------
				void createHeap(int *arr, int s)
				{ // start creation
					delete [] heap;
					size = s; // set size to the given value
					heapSize = size;
					heap = new int[size];
					for(int i=0 ; i < heapSize ; i++)
						heap[i] = arr[i]; // copy the data from the given array into my array					
					heapify();
					return;
				} // end creation
			
			// insertion------------------------------------------------
				void insert(int item)
				{ // start insertion
					for (int j = 0; j <= heapSize ; j++)
						if (heap[j] == item) return; // duplicate item strying to be inserted					
					if (heapSize == size) // if full, double size and copy data
					{ // start if -- heap full
						int *old = heap;
						size *= 2;
						heap = new int[size];
						for(int i = 0; i < heapSize ; i++)
						{ // start for -- copy old data to the new heap
							heap[i] = old[i];
						} // end for
					} // end if
					heap[heapSize++] = item;
					heapify();
					delete [] old;
					return;
				} // end insertion
			
			// deletion-------------------------------------------------
				void deleteItem(int item)
				{ // start deletion
					return;
				} // end deletion
			
			// printing-------------------------------------------------
				void printHeap()
				{ // start print
					for(int i = 0 ; i < heapSize ; i++)
						std::cout << heap[i] << ' ';
					std::cout << std::endl;
					return;
				} // end print
}; // end def
#endif
