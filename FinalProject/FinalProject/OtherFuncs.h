using namespace std;


void filldeck(stack<Card*>& cards);
void deal(stack<Card*>& deck, Hand players[], int numplayers);
void cleanup(Hand& cards);
void cleanup(stack<Card*>& cards);
Card largest(vector<Card>& discard);


extern int NUMCARDS;