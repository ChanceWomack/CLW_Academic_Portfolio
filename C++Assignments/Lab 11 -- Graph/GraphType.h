/* Chance Womack
 * Lab 11 -- Graphs -- Using Adjacency Matrix
 * GOALS
 * You will need to create a class that implements a Graph, called GraphType. Your
class will use an array (pointer) that represents the graph. You must choose
whether you are using an adjacency matrix or an adjacency list for the storage.
 * 
 * Your class will read the graph information from a file. We will assume that the
vertex labels start at 1 and go up to the number of vertices. The first line of the
file contains the number of vertices in the graph. The remaining lines represent
each edge in the graph, using a comma separated listing. Here is an example file
(this one is named ‘mygraph.txt’)
 * 
 * Your class needs to have a method called “loadGraph()” that will ask the user for
the name of the file and will process the file correctly to store the graph.
 *
 * Your class also needs a method to print the graph to the screen, either as an
adjacency matrix or as a list.
 */
// include desired libraries
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>

class GraphType
{ // start def
	private:
		// data members
		int size = 0;
		int **matrix;
		// private mthods-----------------------------------------------
		void deleteGraph()
		{ // start deletion
			for(int i = 0 ; i < size ; i++)
			{ // start for loop
				delete [] matrix[i];
			} // end for loop
			delete [] matrix;
			return;
		} // end deletion
		
		void dft(int v, bool *visited) const
		{ // start dft
			visited[v] = true;
			std::cout << v+1 << ' ';
			// find adjecent nodes
			for(int u = 0 ; u < size ; u++)
			{ // start for
				if(matrix[v][u] == 1)
				{ // start outer if
					if(!visited[u])
					{ // start inner if
						dft(u, visited);
					} // end inner if
				} // end outer if
			} // end for
			return;
		} // end dft
	public:
		// methods
			// constructor
			GraphType()
			{ // start constructor
				// use the same method as in load to create an empty graph
				matrix = new int*[size];
				for(int i = 0 ; i < size ; i++)
				{ // start outer for loop
					matrix[i] = new int[size];
					for(int j = 0 ; j < size ; j++)
					{ // start inner for loop
						matrix[i][j] = 0; // initialize the arrays to 0
					} // end inner for loop
				} // end outer for loop
			} // end constructor
			
			// deconstructor
			~GraphType()
			{ // start deconstructor
				deleteGraph();
			} // end deconstructor
		
			// Load Graph-----------------------------------------------
			void loadGraph()
			{ // start load
				deleteGraph(); // delete old graph
				// declare inFile and file name variables
				std::ifstream inFile;
				std::string fName;
				// ask user for file name
				std::cout << "Please enter the name of the Graph File: ";
				std::cin >> fName; // get file name from user
				inFile.open(fName); // open inFile
				if ( !inFile ) // verify opening
				{ // open failed
					std::cerr << "Error opening file: terminating" << std::endl;
					return;
				}// end termination
				// get the size of the array for the file
				int newSize;
				inFile >> newSize;
				if(!inFile)
				{ // start if
					std::cout << "Graph Size not Found: Terminating";
				} // end if
				if(size > 0) deleteGraph(); // clear memory for new graph
				size = newSize; // set the graph size variable
				// allocate space for the graph
				matrix = new int*[size]; // 
				for(int i = 0 ; i < size ; i++)
				{ // start outer for loop
					matrix[i] = new int[size];
					for(int j = 0 ; j < size ; j++)
					{ // start inner for loop
						matrix[i][j] = 0; // initialize the arrays to 0
					} // end inner for loop
				} // end outer for loop
				
				int firstVertex, lastVertex; // declare stroage variables for the vertices
				// read initial set of vertices
				inFile >> firstVertex;
				inFile.ignore(1);
				inFile >> lastVertex;
				
				while(inFile)
				{ // start while
					matrix[firstVertex-1][lastVertex-1] = 1; // process edge
					// read next set
					inFile >> firstVertex;
					inFile.ignore(1);
					inFile >> lastVertex;
				} // end while
				inFile.close();
				return;
			} // end load
		
			// Print Graph----------------------------------------------
			void print()
			{ // start print
				for(int row = 0 ; row < size ; row++)
				{ // start for outer loop
					for(int col = 0 ; col < size ; col++)
					{ // start inner for loop
						std::cout << matrix[row][col] << ' ';
					} // end inner for loop
					std::cout << std::endl;
				} // end outer for loop
				return;
			} // end print
			
			// Depth First Traversal------------------------------------
			void depthFirstTraversal()
			{ // start DFT
				std::cout << "Depth First Traversal: ";
				bool *visited = new bool[size]{0};
				for(int v = 0 ; v < size ; v++)
				{ // start for loop
					if(!visited[v])
					{ // start if
						dft(v, visited);
					} // end if
				} // end for loop
				delete [] visited;			
				return;
			} // end DFT
			
			// Breadth First Traversal----------------------------------
			void breadthFirstTraversal()
			{ // start BFT
				std::cout << "Breadth First Traversal: ";
				bool *visited = new bool[size]{0};
				std::queue<int> que;
				for (int v = 0 ; v < size ; v++)
				{ // start for
					if (!visited[v])
					{ // start if
						que.push(v); // add to queue
						visited[v] = true; // visit
						std::cout << v+1 << ' ';
						while(!que.empty()) // while loop
						{ // start while
							int u = que.front(); // now equals v
							que.pop(); // remove v from queue
							for(int w = 0 ; w < size ; w++) // loop through and find adjacent nodes
							{ // start 2nd for
								if(matrix[u][w] == 1) // check to see if adjacent
								{ // start 2nd if
									if(!visited[w]) // check to see if not already visited
									{ // start 3rd if
										que.push(w); // add to queue
										visited[w] = true; // visit
										std::cout << w+1 << ' ';
									} // end 3rd if
								} // end 2nd if
							} // end 2nd for
						} // end while
					} // end if
				} // end for
				delete [] visited;
				return;
			} // end BFT
}; // end def
