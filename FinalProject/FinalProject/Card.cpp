#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#include "Card.h"
using namespace std;

Card::Card(int s, int v) {
	setSuit(s);
	setValue(v);
}

int Card::getSuit() { return suit; }

void Card::setSuit(int s) {
	suit = (s >= SPADES && s <= HEARTS) ? s : SPADES;
}

int Card::getValue() { return value; }
void Card::setValue(int v) {
	value = (v >= 1 && v <= 13) ? v : 1;
}

bool Card::operator==(Card& c) {
	return (getSuit() == c.getSuit() && getValue() == c.getValue());
}

ostream& operator<<(ostream& str, const Card& c) {
	if (c.value == 13) str << "King";
	else if (c.value == 12) str << "Queen";
	else if (c.value == 11) str << "Jack";
	else if (c.value == 1) str << "Ace";
	else str << c.value;

	str << " of ";

	switch (c.suit) {
	case Card::SPADES:
		str << "Spades";
		break;
	case Card::DIAMONDS:
		str << "Diamonds";
		break;
	case Card::CLUBS:
		str << "Clubs";
		break;
	case Card::HEARTS:
		str << "Hearts";
		break;
	}

	return str;
}

Card Card::largest(vector<Card>& discard) {
	Card largest = discard[0];
	for (int i = 1; i < 4; i++) {
		if (largest.getValue() > discard[i].getValue()) {
			largest = discard[i];
		}
	}

	return largest;
}