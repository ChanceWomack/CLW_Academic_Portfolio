/* Chance Womack
 * 8/25/22
 * Lab 2: Deck of Cards
 * Goal: Write a class definition and test program that implements a deck of cards. Assume a normal 52-card
deck that consists of the 4 suits (Hearts, Diamonds, Clubs, Spades) and 13 values (2 – 10, J, Q, K, A).
You can utilize the Card class developed in the classroom (shared on Moodle).
*/

// include desired libraries
#include <iostream>
#include "Card.h"
#include "clw-lab2-deck.h"
using namespace std;

const int HAND = 5;

int main()
	{ // start main
		CardType card; // the card pulled from the deck into my hand
		DeckType deckA; // create my deck
		deckA.shuffleDeck(); // shuffles the deck


	// deals me a 5 card hand
	cout << "My Hand" << endl << endl; // display a header
		for (int i = 0 ; i < HAND; i++) // loop through until 5 cards has been dealt into my hand
		{ // start for loop
			card = deckA.deal(); // draws a card from deckA and sets the "Active Card" to the drawn card
			cout << card.toString() << endl; // displays drawn card
		} // end for loop

	cout << endl; // seperates the hands

	// deals them a 5 card hand...same as abpve, but prefaced as an "opponents" hand
	cout << "Their Hand" << endl << endl;
		for (int i = 0 ; i < HAND; i++)
		{ // start for loop
			card = deckA.deal();
			cout << card << endl;
		} // end for loop

	return 0;
	} // end main


