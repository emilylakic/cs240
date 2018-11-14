#include "Tournament.h"
#include <math.h>
#include <algorithm>


Tournament::Tournament() {
  total=0;
  numGames=0;
  average=0;
  maxNum=0;
}

Tournament::~Tournament() {
}

void Tournament::readFile(string fname) { //read file name
  inFile.open(fname); //open

  if (!inFile.is_open()) {
    	cerr << "Not able to open file. " << pfile << endl;
    	exit(1);
	}

  string str;

  while(inFile >> str){

    Player p = Player(str);
    playerName.push_back(p);

  }

inFile.close();
}

Player Tournament::playTournament() {
  out.open(lfile);
  Player loser;
  Player winner = playerName.at(0).name;
  int max=playerName.size();
    for(int i=0; i<max/2; i++) {
      Game game = Game(playerName.at(0), playerName.at(1), lfile);
      loser = game.play();
      total += game.get_battleCounter();
      if(game.get_battleCounter() > maxNum) {
        maxNum = game.get_battleCounter();
      }
      numGames++;
      if(playerName.size() == 1) {
        return loser;
      }
        if(loser.name == playerName.at(0).name) {
          playerName.at(1).numWins++;
          playerName.push_back(playerName.at(1));
          //playerName.at(1).numWins++;
          playerName.erase(playerName.begin());
          playerName.erase(playerName.begin());
        }

        else if(loser.name == playerName.at(1).name) {
          playerName.at(0).numWins++;
          playerName.push_back(playerName.at(0));
          //playerName.at(0).numWins++;
          playerName.erase(playerName.begin());
          playerName.erase(playerName.begin());
        }
      }
      if(playerName.size()!= 1) {
        playTournament();
      }
      else {
      average = total/numGames;
      cout << "Winner of tournmanet: " << winner.name << endl;
      cout << "Average number of battles per matchup: " << average << endl;
      cout << "The largest number of battles in any one matchup: " << maxNum << endl;
    }
  out.close();
  return loser;
}
