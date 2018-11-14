//#include <iostream>
//#include <string>
#include "LLC.cpp"

using namespace std;

class PlayingCard {
  public:
    PlayingCard();
    PlayingCard(int value, int typeSuit);
    ~PlayingCard();
    friend ostream &operator<< (ostream &out, const PlayingCard&);
    bool operator==(const PlayingCard &other);
    void operator=(const PlayingCard &other);
    bool operator>(const PlayingCard &other);
    bool operator<(const PlayingCard &other);
    string getVal() const;
    string getTypeSuit() const;
   private:
    int val1;
    enum Suit { hearts, diamonds, spades, clubs };
    Suit typ;

};
