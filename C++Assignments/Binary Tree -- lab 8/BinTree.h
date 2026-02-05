/* Chance Womack
 * Lab 8:  Binary Trees
 * Goal
 * You will need to create a class to implement a Binary Tree.
 * Call your class BinTree and save it in a file called “BinTree.h”.
 * You should use the provided BTNode class (BTNode.h).
 * 
 * Your class needs to support insertion, deletion, and searching; so you will need to create methods for each of these.
 * 
 * You also need to have a method to print the contents of the tree.
 * This will require a traversal, either inorder, preorder, or postorder.
 */
#ifndef BINTREE_H
#define BINTREE_H
// include desired libraries
#include <iostream>
#include "BTNode.h"
#include <queue>

template<typename T>
class BinTree
{ // start def
	protected:
		// data members
			BTNode<T> *root = 0; // initialize to null
	public:
		// methods				
			// insertion--
				void insert(T item)
				{ // start insert
					BTNode<T> *NewNode = new BTNode<T>; // create my pointers
					NewNode -> data = item;
					if(root == nullptr)
						{ // start if, empty tree
							root = NewNode;
							return;
						} // end if
					std::queue<BTNode<T> *> list;
					BTNode<T> *current = 0;
					list.push(root); // put root on the queue
					while ( !list.empty() )
					{ // start while
						current = list.front(); // sets current to the front of the queue, as pops happen, it will shift current to the next node to be evaluated
						if (current -> leftC != nullptr && // checks if both children ar null
							current -> rightC != nullptr)
							{ // start if
								list.push(current -> leftC); // if null, adds them to the queue
								list.push(current -> rightC);
								list.pop(); // remove front item/current from the queue
							} // end if
						else
							break;
					} // end while						
					// attachment
						if(current -> leftC == nullptr) // if left is null, attach to the left child
							current -> leftC = NewNode;
						else // if left is NOT null, attach to the right child
							current -> rightC = NewNode;
				} // end insert
		
							
			// deletion
				void deleteItem(T item)
				{ // start deletion
					return;
				} // end deletion
				
				
			// searching
				bool search(T item) const
				{ // start search
					return false;
				} // end search
				
				
			// printing--
				void print() const
				{ // start print
					inordertraversal(root);
				} // end print
				
			private:
			// inorder traversal--
				void inordertraversal(BTNode<T> *p) const
				{ // start traversal
					if (p != nullptr)
						{ // start if
							inordertraversal(p ->leftC); //			L
							std::cout << p -> data << std::endl; //	V
							inordertraversal(p -> rightC); //		R
						} // end if
				} // end traversal	
				
			// preorder traversal--
				void preordertraversal(BTNode<T> *p) const
				{ // start traversal
					if (p != nullptr)
						{ // start if
							std::cout << p -> data << std::endl; //	V
							preordertraversal(p ->leftC); //			L
							preordertraversal(p -> rightC); //		R
						} // end if
				} // end traversal	
}; // end def
#endif
