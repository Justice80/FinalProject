#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#include "Hand.h"

using namespace std;

int Hand::size() { return cards.size(); }

void Hand::discard(size_t i) {

	for (i; i < cards.size()-1; i++) {
		cards[i] = cards[i + 1];
	}
	cards.pop_back();
}

Hand& Hand::operator+(Card* c) {
	cards.push_back(c);

	return *this;
}

Hand& Hand::operator+=(Card* c) {
	return *this + c;
}

Card* Hand::operator[](int i) {
	return cards[i];
}

ostream& operator<<(ostream& str, Hand& hand) {
	for (int c = 0; c < hand.size(); c++)
		str << (*hand[c]) << endl;

	return str;
}
