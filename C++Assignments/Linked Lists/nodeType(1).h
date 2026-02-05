/* Chance Womack
 * Node for Linked Lists
 */
 
// include desired libraries and define class

#ifndef H_NODETYPE
#define H_NODETYPE
#include <iostream>
#include <iomanip>

	template <typename T>
	class NodeType
	{ // start def
	public:
		T data; // variable declaration
		NodeType<T> *next; // variable declaration
		NodeType(T d=0) { data = d; next = nullptr; } // constructor
	}; // end def
#endif
