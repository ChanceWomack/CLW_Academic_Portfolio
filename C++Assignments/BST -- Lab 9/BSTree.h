/* Chance Womack
 * Lab 9 -- BST
 * Goal
 * You will need to create a class to implement a Binary Search Tree.
Call your class BSTree and save it in a file called “BSTree.h”. You should use the
provided BTNode class (BTNode.h).
 *
 * our class needs to support insertion, deletion, and searching; so you will need to
create methods for each of these.
 * 
 * You also need to have a method to print the contents of the tree using an inorder
traversal. This allows for checking if the tree is truly a BST.
 * 
 * Also provide methods for the preorder and postorder traversals.
 * 
 * Your class needs to work with the provided test program (BST_test.cpp)
 */
#ifndef BSTREE_H
#define BSTREE_H
// include desired libarraies
#include <iostream>
#include <queue>
#include "BTNode.h"

template <typename T>
class BSTree
{ // start def
	protected:
		// data members
		BTNode<T> *root = 0; // initialize to null...Root pointer, NOT root Node
	public:
		// methods
			// insertion------------------------------------------------
				void insert(T item)
				{ // start insertion
					// check if item is in tree already
						if (search(item))
						{ // start if
							std::cerr << "Dupilcates are not allowed" << std::endl;
							return;
						} // end if
							// if tree is empty
								BTNode<T> *NewNode = new BTNode<T>; // create my pointers & new node
								NewNode -> data = item;
								if (root == nullptr)
									{ // start if, empty tree
										root = NewNode;
										return;
									} // end if
							// if tree is NOT empty
								BTNode<T> *current = root; // create pointers
								BTNode<T> *trail = 0;
								while (current != nullptr)
								{ // start while
									trail = current;
									if (item > current -> data) // go right
										current = current -> rightC;
									else 						// go left
										current = current -> leftC;
								} // end while				
							// attachment
								if (NewNode -> data < trail -> data) // if item is less than current->data, attach to the left child
									trail -> leftC = NewNode;
								else // if item is greater than current->data, attach to the right child
									trail -> rightC = NewNode;
				} // end insertion	
			// deletion-------------------------------------------------
			// I give up boss, I tried...
				void deleteItem(T item)
				{ // start deletion
					BTNode<T> *current = root; // create pointers
					BTNode<T> *trail = 0;
					// if tree is empty
						if (current == nullptr) return;
					// find target
						while (current != nullptr)
						{ // start while
							if (current -> data != item)
							{ // start outer if
								if (current -> data > item) // if data is greater, go left
									current = current -> leftC;
								else //(item < current -> data) // if data is lesser, go right
									current = current -> rightC;
							} // end outer if
							else
							{ // start else / item found
								// if target is a leaf
									if (current -> rightC == nullptr &&
										current -> leftC == nullptr)
									{ // start if
										if (current == root) // if item is root and has no children
										{ // start if
											root = nullptr;
											delete root;
											return;
										} // end if
										else
										{ // start else
											current = nullptr;
											delete current;
											return;
										} // end else
									} // end if
								// if target is a parent
									trail = current;
									if (current -> rightC != nullptr) // if target has a right subtree
									{ // start if
										BTNode<T> *smallest = current-> rightC;
										while (smallest->leftC != nullptr)
										{ // start while
											trail = smallest;
											smallest = smallest -> leftC;
										} // end while
										current -> data = smallest -> data;
										if (smallest -> rightC != nullptr)
											trail -> leftC = smallest -> rightC;
										else
											trail -> rightC = nullptr;
										delete smallest;
										return;
									} // end if
									else
									{ // start else / no right subtree
										current -> data = current -> leftC -> data;
										current -> leftC = current -> leftC -> rightC;
										return;
									} // end else
							} // end else
						} // end while
				} // end deletion
			// searching------------------------------------------------
				bool search(T item) const
				{ // start search
					BTNode<T> *current = root; // create a pointer to track current
					while (current != nullptr)
					{ // start while
						if (current -> data != item)
						{ // start outer if
							if (current -> data > item) // if data is greater, go left
								current = current -> leftC;
							else //(item < current -> data) // if data is lesser, go right
								current = current -> rightC;
						} // end outer if
						else
							return true;
					} // end while
					return false;
				} // end search
			// print inorder--------------------------------------------
				void print() const // printInorder
				{ // start print
					std::cout << std::endl;
					std::cout << "Inorder: ";
					inordertraversal(root);
				} // end print			
			// print preorder-------------------------------------------
				void printPreorder() const
				{ // start print
					std::cout << std::endl;
					std::cout << "Preorder: ";
					preordertraversal(root);
				} // end print				
			// print postorder------------------------------------------
				void printPostorder() const
				{ // start print
					std::cout << std::endl;
					std::cout << "Postorder: ";
					postordertraversal(root);
				} // end print	
		private:
			// inorder traversal LVR------------------------------------
				void inordertraversal(BTNode<T> *p) const
				{ // start inorder
					if (p != nullptr)
						{ // start if
							inordertraversal(p -> leftC); //		L
							std::cout << p -> data << ' '; //		V
							inordertraversal(p -> rightC); //		R
						} // end if
				} // end inorder			
			// preorder traversal VLR-----------------------------------
				void preordertraversal(BTNode<T> *p) const
				{ // start traversal
					if (p != nullptr)
						{ // start if
							std::cout << p -> data << ' '; //		V
							preordertraversal(p ->leftC); //		L
							preordertraversal(p -> rightC); //		R
						} // end if
				} // end traversal				
			// postorder traversal LRV----------------------------------
				void postordertraversal(BTNode<T> *p) const
				{ // start traversal
					if (p != nullptr)
						{ // start if
							postordertraversal(p ->leftC); //		L
							postordertraversal(p -> rightC); //		R
							std::cout << p -> data << ' '; //		V
						} // end if
				} // end traversal			
}; // end def
#endif
