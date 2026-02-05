//program to test the graph

#include "GraphType.h"
#include <iostream>


using namespace std;

int main() {

    //create an empty graph
	GraphType myGraph;
	
    //this will load the graph from the file (ask user for file name)
	myGraph.loadGraph();
	
	myGraph.print();//print the graph as a matrix or as an adjacency list (just checking)

    //now print using the depth first traversal
    myGraph.depthFirstTraversal();
    cout << endl;
    myGraph.breadthFirstTraversal();//calls the method to perform the depth first traversal algorithm
	
	return 0;
}//end main
