#include "Game.h"

Game::Game(Player &name, Player &name1, string logfile) {

  player1 = name;
  player2 = name1;
  this->logfile = logfile;
  warCounter = 1;
  battleCounter = 0;

  for(int i=0; i<4; i++){
      for(int j=2; j<15; j++){
          PlayingCard card = PlayingCard(i, j);
          stack.insert(card);
      }
  }

  shuffleDeck();
  dealCards();

}

Game::Game(const Game &gam) {
}

Game::~Game() {
}

void Game::shuffleDeck() {
  stack.shuffle();
}

void Game::dealCards() {
  for (int i = 0; i < 26; i++) {
    PlayingCard card = stack.getFirstCard();
    PlayingCard card2 = stack.getFirstCard();
    player1.insert(card);
    player2.insert(card2);
  }
}

Player Game::play() {
  out.open(logfile, fstream::app);
  out << "===" << endl;
  out << player1.name << " VS. " << player2.name << endl;
  while(player1.len() != 0 && player2.len() != 0){
    if(battleCounter == 1000){ //cannot be more than 1000 rounds
      if(player1.len() > player2.len()){
        out << player1.name << " (" << player1.numWins + 1 << ")" << " DEFEATED " << player2.name << " in ";
        out << battleCounter <<" Battles and "<< warCounter << " Wars" << endl;
        return player2;
      }
      else {
        out << player2.name << " (" << player2.numWins + 1 << ")" << " DEFEATED " << player1.name << " in ";
        out << battleCounter <<" Battles and "<< warCounter << " Wars" << endl;
        return player1;
      }
    }
    battle();
  }

  if(player1.len() != 0 && player2.len() == 0) {
      out << player1.name << " (" << player1.numWins + 1 << ")" << " DEFEATED " << player2.name << " in ";
      out << battleCounter <<" Battles and "<< warCounter << " Wars" << endl;
  return player2;
  }

  else if(player2.len() != 0 && player1.len() == 0) {
      out << player2.name << " (" << player2.numWins + 1 << ")" << " DEFEATED " << player1.name << " in ";
      out << battleCounter <<" Battles and "<< warCounter << " Wars" << endl;
  return player1;
  }
  return player1;
}

void Game::battle() {
  battleCounter++;

  if(battleCounter == 1000) { //cannot exceed 1000
    return;
  }

  PlayingCard card1 = player1.getFirstCard();
  PlayingCard card2 = player2.getFirstCard();

  stack.insert(card1);
  stack.insert(card2);

    if(card1 == card2) {
      out << "\t" << "War " << warCounter << ": " << player1.name << " (" << card1 << ") tied " << player2.name << " (" << card2 << "): " << player1.name << " " << player1.len() << ", " << player2.name << " " << player2.len() << endl;
      war();
    }

    else if(card1 > card2) {
      player1.join(stack);
      out << "\t" << "Battle " << battleCounter << ":" << " " << player1.name << " (" << card1 << ") defeated " << player2.name << " (" << card2 << "): " << player1.name << " " << player1.len() << ", " << player2.name << " " << player2.len() << endl;
      stack.clear();
    }

    else if(card2 > card1) {
      player2.join(stack);
      out << "\t" << "Battle " << battleCounter << ":" << " " << player2.name << " (" << card2 << ") defeated " << player1.name << " (" << card1 << "): " << player1.name << " " << player1.len() << ", " << player2.name << " " << player2.len() << endl;
      stack.clear();
    }
}
void Game::war() {

    warCounter++;

    for(int i=0; i<3; i++) {

      stack.insert(player1.getFirstCard());
      stack.insert(player2.getFirstCard());

  }

  battle();

}

int Game::get_battleCounter() {

  return battleCounter;

}

int Game::get_warCounter() {

  return warCounter;

}
