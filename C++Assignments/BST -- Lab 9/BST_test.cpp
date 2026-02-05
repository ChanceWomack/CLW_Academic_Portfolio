/* Program to test Binary Search Trees
 * Jacob Somervell
*/

#include "BSTree.h"
#include <cstdlib> //for random numbers
#include <iostream>
using namespace std;

int main() {
    srand(42);//seed the random number generator

    BSTree<int> myTree;

    myTree.insert(40);

    for(int i = 0; i < 10; i++) {
        //create a random number
        int random = (rand() % 100) + 1;
        cout << "Adding " << random << " to tree." << endl;
        //add number to the tree
        myTree.insert(random);
    }

    //now print the nodes
    myTree.print();
    myTree.printPreorder();
    myTree.printPostorder();
	cout << endl;
    //now search for a value
    if (myTree.search(90))
        cout << 90 << " found in tree." << endl;
    else
        cout << 90 << " not found in tree." << endl;

    //now delete a value

    myTree.deleteItem(40);
    myTree.deleteItem(67);

    //print tree again
    myTree.print();
    myTree.printPreorder();
    myTree.printPostorder();

    return 0;
}//end main
