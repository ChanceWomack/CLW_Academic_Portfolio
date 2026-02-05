/* Heap testing program
 * Jacob Somervell
 * March 25, 2021
*/
#include "MaxHeap.h"
#include <cstdlib>
#include <iostream>
using namespace std;

#define SIZE 10

int main() {
    srand(42);

    MaxHeap myHeap;//create a MaxHeap object

    //create an array with random numbers
    int array[SIZE];
    for(int i = 0; i < SIZE; i++) {
        int num = rand() % 1000 + 1;
        array[i] = num;
    }

    //now use your class to create the Heap
    myHeap.createHeap(array,SIZE);

    //print the heap to visually inspect it
    myHeap.printHeap();

    //now add some items to the heap
    myHeap.insert(99);
    myHeap.insert(82);
    myHeap.insert(6);

    myHeap.printHeap();

    return 0;

}
