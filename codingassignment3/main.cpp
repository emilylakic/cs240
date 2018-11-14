#include "LLC.h"

using namespace std;

int main() {
  LLC object = LLC();
  LLC other = LLC();
  other.insert("try");
  other.insert("to");
  other.insert("insert");
  LLC list1 = LLC();
  list1.insert("first");
  list1.insert("yay");
  LLC list2 = LLC();
  list2.insert("second");
  list2.insert("woohoo");
  //cout << other;
  //LLC copy = LLC(other);
  //cout << copy;
  //object.insert("binghamton");
  object.insert("binghamton");
  object.insert("emily");
  object.insert("lakic");
  object.insert("westchester");
  object.insert("NY");
  object.insert("binghamton");
  object.insert("hi");
  object.contains("emily"); //if you want to check if it's true use if statement and cout <<"True"<<endl;
  cout << object; //where I print first list
  object.remove("binghamton"); //test to see if it removes all of them
  object.head(object.len()); //where I print second list
  object.tail(); //print Tail:
  object.join(other); //where I print third list
  cout << object;
  object.len();
  object.shuffle();
  object += 3;
  cout << object;
  LLC test3 = LLC();
  test3 = object;
  test3.head(object.len());
  //cout << test3;
  LLC test4 = LLC();
  test4 = object + other;
  cout << object;
  cout << other;
  cout << test4;
  return 0;
}
