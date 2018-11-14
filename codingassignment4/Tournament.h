#include <iostream>
#include <string>
#include "Game.h"
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

class Tournament {
  public:
    Tournament();
    ~Tournament();
    Player playTournament();
    void readFile(string fname);
    //void writeFile();
    string lfile;

  private:
    vector <Player> playerName;
    ifstream inFile;
    ofstream out;
    string pfile;
    int total;
    int numGames;
    int average;
    int maxNum;
  };
