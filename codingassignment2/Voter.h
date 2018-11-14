#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class Voter {
  public:
    Voter();
    Voter(string firstName, string lastName, string userid, string password, int age, string streetName, int streetNumber, string town, string zipCode, float amountDonated);
    void secondLevel();
    void newInfo();
    void update();
    void passwd();
    void view();
    void donate();
    void report();
    string getid();
    string getpass();
    string save();
    float getdonated();
    void setLast(string ln);
    void setFirst(string fn);
    void setAge(int age);
    void setstreetName(string ln);
    void setstreetNum(int num);
    void setDonated(float sdon);
    void setTown(string ln);
    void setZip(string zipp);
    void setUser(string us);
    void setPass(string pas);

  private:
    string lastName;
    string firstName;
    string userid;
    string password;
    string passage;
    string passstreetnumber;
    int age;
    int streetNumber;
    string streetName;
    string town;
    string zipCode;
    string updateamount;
    float amountDonated;
    float donatedAmount;
    string oldPass;
    string newPass;
    string confirmed;
};
