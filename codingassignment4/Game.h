#include <iostream>
#include <string>
#include "Player.h"
#include <fstream>

using namespace std;

class Game {
  public:
    Game(Player &name, Player &name1, string logfile);
    Game(const Game &gam);
    ~Game();
    void battle();
    Player play();
    void war();
    int get_warCounter(); //getter for warCounter
    int get_battleCounter(); //getter for battleCounter
  private:
    LLC<PlayingCard> stack;
    Player player1;
    Player player2;
    int battleCounter;
    int warCounter;
    int maxNum;
    ofstream out;
    string logfile;
    void shuffleDeck();
    void dealCards();
};
