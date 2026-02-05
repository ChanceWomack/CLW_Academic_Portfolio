/* Chance Womack
 * 8/25/22
 * Lab 2: Deck of Cards
 * Goal: Write a class definition and test program that implements a deck of cards. Assume a normal 52-card
deck that consists of the 4 suits (Hearts, Diamonds, Clubs, Spades) and 13 values (2 – 10, J, Q, K, A).
You can utilize the Card class developed in the classroom (shared on Moodle).
*/

// include desired headers
#ifndef H_DECK
#define H_DECK
#include "Card.h"
#include <iostream>
#include <ctime>

// declare constant values
const int DECKSIZE = 52;

class DeckType
{ // start class definition
	private:
	// class variable declarations
		CardType theDeck[DECKSIZE];
		int topCard;
	public:
	// class methods
		// constructor--------------------------------------------------
			DeckType()
			{ // start constructor
				int counter = 0;
				topCard = 0;
				for (int f = TWO; f <= ACE ; f++) // should loop through my faces
					for (int s = Hearts ; s <= Spades ; s++) // should then loop through my suits
					{ // start for loop
						theDeck[counter].setSuit((Suit)s);
						theDeck[counter++].setFace((Face)f);
					} // end for loop
			} // end constructor
				
		// shuffle method-----------------------------------------------
			void shuffleDeck()
			{ // start of the shuffle deck method
				srand(time(NULL)); // seed the random number generator
				for (int i = 0 ; i < 500 ; i++)
				// meant to randomly generate a card and swap it into the deck
				{ // start for loop
					int index1 = rand()%DECKSIZE;
					int index2 = rand()%DECKSIZE;
					CardType tempCard = theDeck[index1];
					theDeck[index1] = theDeck[index2];
					theDeck[index2] = tempCard;
				} // end for loop
				topCard = 0;
			} // end of the shuffle deck method
			
		// deal method--------------------------------------------------
		CardType deal()
		{ // start deal method
			if ( topCard < DECKSIZE ) // should go until it reaches the end of the deck
				return theDeck[topCard++];
			else 
			{ // start else; no cards remaining
				shuffleDeck();
				return deal();
			} // end else
		} // end deal method		
		
}; //end class definition
#endif
