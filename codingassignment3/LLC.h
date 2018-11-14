#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <list>

using namespace std;

class LLC {

public:

  LLC();
  LLC (const LLC &obj);
  //LLC& LLC::operator = (const LLC &list);
  ~LLC();
  bool contains(const string &str);
  bool insert(const string &str);
  void remove(const string &st);
  void head(int n);
  string tail();
  friend ostream &operator<< (ostream &out, const LLC &list); //you need the list here bc this is a friend function that's why you got rid of LLC param from below
  void operator+= (int n);
  //LLC &operator=(LLC other);
  int len();
  void join(LLC& other);
  void shuffle();
  //void operator+(const LLC &list1);
  LLC operator+(const LLC &addThis);
  void operator=(const LLC &list);

private:

struct Node {
  string data;
  Node *next;
};

Node *first, *last;

};
