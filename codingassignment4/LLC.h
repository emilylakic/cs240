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
    LLC<T>& operator+(const LLC<T> &oth);
    void head(int n);
    T tail();

    template <typename U>
    friend ostream &operator<<(ostream &out, const LLC<U> &list);
    void operator+=(int oth);
    int len();
    void join(LLC<T> &oth);

  private:

    struct Node {
        T data;
        Node *next;
    };

    Node *first;
    Node *last;

};
