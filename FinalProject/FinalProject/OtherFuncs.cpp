#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include "Card.h"
#include "Hand.h"
#include "OtherFuncs.h"

using namespace std;

void filldeck(stack<Card*>& cards) {
	vector<Card*> tmp;
	Card* c;
	bool found;
	while (tmp.size() < 52) {
		c = new Card(rand() % 4 + 1, rand() % 13 + 1);
		found = false;
		for (int i = 0; !found && i < tmp.size(); i++) {
			found = (*tmp[i] == *c);
		}
		if (!found)
			tmp.push_back(c);
	}

	for (int i = tmp.size() - 1; i >= 0; i--)
		cards.push(tmp[i]);
}

void deal(stack<Card*>& deck, Hand players[], int numplayers) {
	for (int c = 0; c < NUMCARDS; c++) {
		for (int p = 0; p < numplayers; p++) {
			players[p] += deck.top();
			deck.pop();
		}
	}
}

void cleanup(Hand& cards) {
	for (int i = 0; i < cards.size(); i++)
		delete cards[i];
}

void cleanup(stack<Card*>& cards) {
	while (!cards.empty()) {
		delete cards.top();
		cards.pop();
	}
}