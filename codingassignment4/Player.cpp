#include "Player.h"

Player::Player(){
  name="";
  numWins=0;
}

Player::Player(string st) {
  name = st;
  numWins = 0;
}

Player::Player(const Player &p) {
  hand = LLC<PlayingCard>();
  numWins = p.numWins;
  name = p.name;
}

Player::~Player(){

}

void Player::insert(const PlayingCard &card) {
  hand.insert(card);
}

PlayingCard Player::getFirstCard() {

  return hand.getFirstCard();
}

int Player::len(){
  return hand.len();
}

void Player::join(LLC<PlayingCard> & other){
  hand.join(other);
}
