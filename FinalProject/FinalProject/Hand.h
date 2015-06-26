#ifndef HAND_H
#define HAND_H
#include "Card.h"

using namespace std;

class Hand {
private:
	vector <Card*> cards;
public:
	int size();

	void Hand::discard(size_t i);
	Hand& Hand::operator+(Card* c);
	Hand& Hand::operator+=(Card* c);
	Card* operator[](int i);
	friend ostream& operator <<(ostream& str, Hand& hand);
};

#endif