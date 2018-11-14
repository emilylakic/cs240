//list should contain C++ strings (one per node)

#include "LLC.h"

LLC::LLC() {
  first = nullptr; //setting first and last equal to null will create an empty list
  last = nullptr;
}

LLC::LLC (const LLC &obj) {
  Node *temp;
  temp = obj.first; //first is first
  Node *previous = NULL;
  while(temp!=NULL) {
    Node *newNode = new Node();
    newNode -> data = temp -> data;
    newNode -> next = NULL;
    if(first==nullptr) {
      first = newNode;
    }
    if(previous!=NULL) {
      previous -> next = newNode;
    }
    previous = newNode;
    temp = temp -> next;
  }
  last = previous;
} //loop through obj linked list, for each node is obj you'll create a new node

  //void friend foo() //check notes for friend function

LLC::~LLC() {
Node *currentNode;
Node *nextNode;
currentNode = this->first;
while(currentNode) {
	nextNode = currentNode->next;
	delete currentNode; //if new was used to create the new node then delete can be used
	currentNode = nextNode; //now that currentNode was deleted, it can be replaced with nextNode
  }
}

bool LLC::contains(const string &str) { //how do I access Node from private in h
  Node *current = first;
  while(current != NULL) { //there is also a way to do this recursively if this doesn't work
    if(current->data == str) {
      return true;
    }
    current = current->next; //struct Node* should be defined as part of struct Node {}
  }
  return false;
}

bool LLC::insert(const string &str) {
    Node *tmp = new Node();
    tmp->data = str;
    tmp->next = NULL;

    if(first == NULL) {
        first = tmp;
        last = tmp;
        return true;
    }
    else {
        last->next = tmp;
        last = last->next;
	      return true;
    }
    return false;
}

void LLC::remove(const string &st) {
  Node *prev = NULL;
  Node *current = first;
  while(current!=NULL){
    if(current->data == st) {
      cout << "Deleting: " << current << "\n";
      if(prev == NULL){
        first = current->next;
      }else{
        prev->next = current->next;
        if(prev->next == NULL){
          last = prev;
        }
      }
      delete current;
    }
    //else {
      //cout << "Value " << current->data << " does not match " << st << ".\n";
    prev = current;
    current = current->next;
    //}
  }
}

void LLC::head(int n) {
  int counter = 0;
  Node *current = first;
  cout << "[";
  while(current!=NULL) {
    if(counter==n) { //if(counter!=n-1 don't print comma and space)
      break;
    }
    else if(counter!=n-1 && current!=last) {
      cout << current -> data << ", ";
    }
    else {
    cout << current -> data;
    }
    current = current -> next;
    counter++;
  }
  cout << "]" << endl;
}

string LLC::tail() {
  cout << "Tail: " << last->data << endl;
  return last->data;
}

ostream &operator<< (ostream &out, const LLC &list) { //isn't member function of LLC class
LLC::Node *current = list.first;
LLC::Node *las = list.last;
out << "[";
while(current!=NULL) { //use this fact here ecounter!=n-1 && current!=last)
  if(current -> next != NULL) {
  out << current -> data << ", ";
  }
  else {
  out << current -> data << "";
  }
  current = current -> next;
}
out << "]" << endl;
return out;
}

void LLC::operator+= (int n) { //think of parameters like this, left and right. what is on left will += what is on the right
for(int i = 0; i < n; i++) {
  Node *tmp;
  last -> next = first; //use arrows when things are pointers
  tmp = first -> next;
  first -> next = NULL;
  last = first;
  first = tmp;
  }
}

/*void LLC::operator+(const LLC &list1) {
Node *newList = new Node();
const LLC &list2 = new LLC();
LLC copy1 = LLC(list1);
LLC copy2 = LLC(list2);
newList = this->insert(copy1->data);
newList = this->insert(copy2->data);
return newList;
cout << newList << endl;
//make a new list and copy values from both lists in the new list
//should return const&
}*/

LLC LLC::operator+(const LLC &addThis){
  LLC *answer = new LLC();
  Node *head = this->first;
  Node *head2 = addThis.first;

  while(head != nullptr){
    answer->insert(head->data);
    head = head->next;
  }

  while(head2 != nullptr){
    answer->insert(head2->data);
    head2 = head2->next;
  }
  return *answer;
}

void LLC::operator=(const LLC &oth){
  LLC *list = new LLC(oth);
  Node *currentNode;
  Node *nextNode;
  currentNode = this->first;
  //Node *temp = this->first;
  while(currentNode!=NULL) {
    nextNode = currentNode->next;
  	delete currentNode; //if new was used to create the new node then delete can be used
  	currentNode = nextNode;
  }
  this->first = list->first;
  this->last = list->last;
}

void LLC::join(LLC& other) {
  //cout << other;
  Node *current = other.first;
    while(current != NULL) {
      this->insert(current->data);
      current = current->next;
    }
}

int LLC::len() {
  int count = 0;
  Node *current = first;
  while(current !=NULL) {
    count++;
    current = current -> next;
  }
  return count;
}

void LLC::shuffle() {
LLC *ls = new LLC();
if(ls -> len()==1) {
  cout << ls << endl;
}
Node *ptr1, *ptr2;
for (int i=0; i<rand()%10; i++) {
  ptr1 = first;
  ptr2 = first;
  int n1 = rand()%len();
  for(int i=0; i<n1; i++) {
    ptr1 = ptr1 -> next;
  }
  int n2 = rand()%len();
  for(int i=0; i<n2; i++) {
    ptr2 = ptr2 -> next;
  }
  string temp = ptr1 -> data;
  ptr1 -> data = ptr2 -> data;
  ptr2 -> data = temp;
  }
}
