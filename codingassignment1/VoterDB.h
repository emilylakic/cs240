#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void newInfo(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &amountDonated);

void update(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode); 

void view(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &amountDonated); 

int donate(float &amountDonated);

void report(string &lastName, float &amountDonated);
