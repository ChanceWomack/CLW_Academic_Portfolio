/* Chance Womack
 * 8/25/22
 * Lab 2: Deck of Cards
 * UNCHANGED AS PROVIDED
 */

#ifndef CARD_H
#define CARD_H
//a class to model a typical playing card
//cards have suits and faces
//Ace through King for the faces and 
//Hearts, Diamonds, Clubs, and Spades for the suits
#include <string>
const std::string SUITS[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const std::string FACES[] = {"Two", "Three", "Four", "Five", "Six",
	 "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King",
	 "Ace"};

enum Suit {Hearts, Diamonds, Clubs, Spades};
enum Face {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
	       NINE, TEN, JACK, QUEEN, KING, ACE};


class CardType {
	private:
		//face
		Face cardFace;
		//suit
		Suit cardSuit;
	public:
		//methods to access the data
		//any other methods we want
		Face getFace() { return cardFace; }
		Suit getSuit() { return cardSuit; }
		void setFace(Face f) { cardFace = f; }
		void setSuit(Suit s) { cardSuit = s; }
		
		CardType() { 
			cardFace = ACE;
			cardSuit = Spades;
		} //default constructor
		
		std::string toString() {
			return FACES[cardFace] + " of " + SUITS[cardSuit];
		}
	// my addition after the lab, trying to overload operator-----------
		friend std::ostream& operator<<(std::ostream& out, const CardType& c)
		{	out << c.cardFace << " of " << c.cardSuit;
			return out; }

};//end class definition
#endif
