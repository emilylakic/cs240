#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>

using namespace std;

template <typename T>
class LLC {
  public:
    LLC();
    LLC(const LLC<T> &oth);
    void operator=(const LLC<T> &oth);
    ~LLC();
    bool contains(const T &con);
    bool insert(const T &newest);
    void remove(const T &val);
    void shuffle();
    LLC<T> &operator+(const LLC<T> &oth);
    void head(int n);
    T tail();

    template <typename U>
    friend ostream &operator<<(ostream &out, const LLC<U> &list);
    void operator+=(int oth);
    int len();
    void join(LLC<T> &oth);
    T getFirstCard();
    void clear();

  private:

    struct Node {
        T data;
        Node *next;
    };

    Node *first;
    Node *last;

};

template <typename T>
LLC<T>::LLC() {
  first = nullptr;
  last = nullptr;
}

template <typename T>
LLC<T>::LLC(const LLC<T> &oth) {

first = nullptr;
last = nullptr;

 Node *previ, *temp;
    previ = nullptr;
    temp = oth.first;

    while(temp != nullptr) {
      Node *nNode;
      nNode = new Node();
      nNode->data = temp->data;
      nNode->next = nullptr;

      if(previ!=nullptr) {
          previ->next=nNode;
      }

      if(first == nullptr)
        first = nNode;
        previ = nNode;
        temp = temp->next;

    }

    last=previ;
}

template <typename T>
void LLC<T>::operator=(const LLC<T> &oth) {

  LLC<T> *list = new LLC(oth);

  Node *pos;
  Node *nNode;
  pos = this->first;

  while(pos != nullptr) {
    nNode = pos->next;
    delete pos;
    pos = nNode;
  }

  this->first = list->first;
  this->last = list->last;
	free(list);
}

template <typename T>
LLC<T>::~LLC() {

  if(first != nullptr) {
    Node * temp;
    temp = first;

    while(temp != nullptr) {
      Node * nNode;
      nNode = temp->next;
      delete temp;
      temp = nNode;
    }
  }
}

template <typename T>
bool LLC<T>::contains(const T &elem) {
  Node *pos = first;
  while(pos != nullptr) {
    if(pos->data == elem)
      return true;
    pos = pos->next;
  }
  return false;
}

template <typename T>
bool LLC<T>::insert(const T &newest) {
  Node *nNode = new Node();

  nNode->next = nullptr;
  nNode->data = newest;

  if(first==nullptr) {
    first = nNode;
    last = nNode;
    return true;
  }
  else {
    last->next = nNode;
    last=last->next;
    return true;
  }

  return false;
}

template <typename T>
void LLC<T>::remove(const T &val) {
  Node *previ, *pos;
  previ = nullptr;
  pos = first;
  while(pos != nullptr) {
    if(pos->data == val) {
      if(previ != nullptr) {
        previ->next = pos->next;
      }
      else {
        first = pos->next;
      }
      delete pos;
    }
    previ = pos;
    pos = pos->next;
  }
}

template <typename T>
void LLC<T>::shuffle() {

  Node *firstNode, *secondNode;

  for(int i = 0; i < rand() % len() + 1500; i++) {

    firstNode = first;
    secondNode = first;
    int node1 = rand() % len();

    for (int i = 0; i < node1; i++){
      firstNode = firstNode->next;
    }

    int node2 = rand() % len();

    for (int i=0; i<node2; i++){
      secondNode = secondNode->next;
    }

    T temp = firstNode->data;
    firstNode->data = secondNode->data;
    secondNode->data = temp;
  }
}

template <typename T>
LLC<T>& LLC<T>::operator+(const LLC<T> &oth) {
  LLC<T> *list = new LLC();
	Node *node1ptr, *node2ptr;
	node1ptr = this->first;
	node2ptr = oth.first;

	while(node1ptr != nullptr) {
		list->insert(node1ptr->data);
		node1ptr = node1ptr->next;
	}
	while(node2ptr != nullptr) {
		list->insert(node2ptr->data);
		node2ptr = node2ptr->next;
	}
	return *list;
}

template <typename T>
void LLC<T>::head(int n) {
  Node *pos = first;
  cout << "[";
  if(pos != nullptr) {
    for (int i=0; i<n; i++) {
  	   cout << pos->data;
       if(i!=n-1) {
          cout << ", ";
       }
  	   pos = pos->next;
    }
  }
  cout << "]" << endl;
}

template <typename T>
T LLC<T>::tail() {
  if(last != nullptr) {
    cout << last->data << endl;
    return last->data;
  }
  return "Last = void.";
}

template <typename T>
ostream &operator<< (ostream &output, const LLC<T> &oth) {

  typename LLC<T>::Node *pos, *lst;
  pos = oth.first;
  lst = oth.last;
  output << "[";

  while(pos != nullptr) {

    if(pos->next != nullptr) {
      output << pos->data << ", ";
    }
    else {
      output << pos->data << "";
    pos = pos->next;
    }
  }

  output << "]" << endl;
  return output;

}

template <typename T>
void LLC<T>::operator+=(int num) {

  int cnt;

  while (cnt < num) {
    Node *nNode;
    last->next = first;
    nNode = first->next;
    first->next = nullptr;
    last = first;
    first=nNode;
    cnt++;
  }

}

template <typename T>
int LLC<T>::len() {
  int cnt = 0;
  Node *pointer = first;
  while (pointer != nullptr) {
    ++cnt;
    pointer = pointer->next;
  }
  return cnt;
}

template <typename T>
void LLC<T>::join(LLC<T> &oth) {
  Node *pos;
  pos = oth.first;
  while(pos != nullptr) {
    insert(pos->data);
    pos = pos->next;
  }
}

template <typename T>
T LLC<T>::getFirstCard() {
T temp;

  if(first != nullptr) {
    Node *ptr;
    temp = first->data;

    ptr = first;
    first = first->next;
    delete ptr;
  }
  return temp;
}

template <typename T>
void LLC<T>::clear(){

  if(first != nullptr) {
    Node * temp;
    temp = first;

    while(temp != nullptr) {
      Node * nNode;
      nNode = temp;
      temp = temp->next;
      delete nNode;
    }

    first = nullptr;
    last = nullptr;

  }
}
