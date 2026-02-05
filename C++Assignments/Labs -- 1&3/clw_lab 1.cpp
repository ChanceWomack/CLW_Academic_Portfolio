/* Chance Womack
 * Lab 1: Frequency Distribution
 * August 18th, 2022
 * Goal: Write a program that takes a file name for a text file, determines the distribution of the characters in the
English language for that text, and presents a histogram of the frequency for each letter.
 */

// include desired libraries
#include <iostream>
#include <iomanip>
#include <string> // needed for strings
#include <fstream> // needed for files
#include <cctype>
#include <cmath>
using namespace std;

const int SIZE = 26;

int main() { // start main
	// declare variables
	string fileName;
	ifstream inFile;
	ofstream outFile;
	int letterCount[SIZE] = {0};
	int letterTotal = 0;
	char currentLetter;
	int numAsterisks = 0;
//--------------------------------------------------------------
	// get inFile from user
	cout << "Enter file name: "; // assuming NO whitespace in fileName
	cin >> fileName;
//--------------------------------------------------------------
	// open file
	inFile.open(fileName);
	if ( !inFile )
	{ // open failed
		cerr << "Error opening file: terminating" << endl;
		cin.get();
		return -1;
	}// end termination
//--------------------------------------------------------------
	// count occurences of each letter
	currentLetter = inFile.get(); // prime while loop
	while (inFile)
	{ // start while loop - will persist until inFile ends
		currentLetter = tolower(currentLetter);
		if (currentLetter >= 'a' && currentLetter <= 'z')
		{ // start if...what is the letter
			letterCount[currentLetter - 'a']++;
			letterTotal++;
		} // end if
		currentLetter = inFile.get();
	} // end while loop
//--------------------------------------------------------------
	// calculate the percentage of each letter
	// display output
	for (int i = 0 ; i < SIZE ; i++)
	{ // start for loop
		cout << (char)(i + 'A') << " - ";
		numAsterisks = (int)(ceil((float)letterCount[i]/(float)letterTotal*100));
		for (int a = 0 ; a < numAsterisks ; a++)
			cout << "*";
		cout << endl;
	} // end for loop
//--------------------------------------------------------------
	// close files and end main
	inFile.close();	
	return 0;
} // end main
