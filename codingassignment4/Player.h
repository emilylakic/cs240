
#include <iostream>
#include <string>
#include "PlayingCard.h"

using namespace std;

class Player {
  public:
    Player();
    Player(string st);
    Player(const Player &p);
    ~Player();
    PlayingCard getFirstCard();
    void insert(const PlayingCard &card);
    int len();
    void join(LLC<PlayingCard> &other);

    string name;

    LLC<PlayingCard> hand;
    int numWins;
};
