/* Program to test Binary Trees
 * Jacob Somervell
*/

#include "BinTree.h"
#include <cstdlib> //for random numbers
#include <iostream>
using namespace std;

int main() {
    srand(42);//seed the random number generator

    BinTree<int> myTree;

    //myTree.insert(40);

    for(int i = 1; i <= 10; i++) {
        //create a random number
        //int random = (rand() % 100) + 1;
       // cout << "Adding " << random << " to tree." << endl;
        //add number to the tree
        myTree.insert(i);
    }

    //now print the nodes
    myTree.print();

    //now search for a value
    //~ if (myTree.search(90))
        //~ cout << 90 << " found in tree." << endl;
    //~ else
        //~ cout << 90 << " not found in tree." << endl;

    //now delete a value

    //~ myTree.deleteItem(40);
    //~ myTree.deleteItem(67);

    //print tree again
    //myTree.print();

    return 0;
}//end main
