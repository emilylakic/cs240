#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>
#include "Voter.h"

using namespace std;

class VoterDB {
  public:
    VoterDB();
    VoterDB(int numVoters);
    bool checkid(const string &userid);
    bool checkpassword(const string &password);
    void login();
    void newInfo();
    void report();
    void save();
    void load(string fn);

  private: //most member vars should be private
    Voter *arr;
    int arrSize;
    int count; //keep track of current number of voters in database
};
