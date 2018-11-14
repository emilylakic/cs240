#include "PlayingCard.h"

PlayingCard::PlayingCard(int typeSuit, int value) {
  typ = Suit(typeSuit);
  val1 = value;
}

PlayingCard::PlayingCard() {
  typ = hearts;
  val1 = 2;
}

PlayingCard::~PlayingCard() {
}

string PlayingCard::getVal() const { //possible cases

    switch(val1) {

    case 2: return "2";

    case 3: return "3";

    case 4: return "4";

    case 5: return "5";

    case 6: return "6";

    case 7: return "7";

    case 8: return "8";

    case 9: return "9";

    case 10: return "10";

    case 11: return "J";

    case 12: return "Q";

    case 13: return "K";

    case 14: return "A";

    default: return "";

  }
}

string PlayingCard::getTypeSuit() const {

  switch(typ) {
    case clubs: return "C";
    case spades: return "S";
    case hearts: return "H";
    case diamonds: return "D";
    default: return "";
  }

}

ostream &operator<<(ostream &output, const PlayingCard &other) {

  output << other.getVal();
  output << other.getTypeSuit();
  return output;

}

bool PlayingCard::operator<(const PlayingCard &other) {
  return val1 < other.val1;
}

bool PlayingCard::operator>(const PlayingCard &other) {
  return val1 > other.val1;
}

bool PlayingCard::operator==(const PlayingCard &other) {

  if(val1 == other.val1)
      return true;
  return false;

}

void PlayingCard::operator=(const PlayingCard &other) {
  val1 = other.val1;
  typ = other.typ;
}
