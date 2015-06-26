#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#include "Card.h"
#include "Hand.h"
#include "OtherFuncs.h"

using namespace std;

int NUMCARDS = 13;
const int NUMPLAYERS = 4;

int main() {

	cout << boolalpha;
	stack <Card*> MainDeck;
	filldeck(MainDeck);

	Hand playerHand[NUMPLAYERS];
	deal(MainDeck, playerHand, NUMPLAYERS);

	

	return 0;
}
