#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "VoterDB.h"

using namespace std;

int main(int argc, char *argv[])
{
  string input;
  string lastName;
  string firstName;
  string userid; //with conditions - contains at least 5 characters but no more than 10, only letters and digits
  string password;
  int age;
  int streetNumber;
  string streetName;
  string town;
  string zipCode;
  float amountDonated;
  float amount = 0;
  int keepGoing = 0;

  while(keepGoing == 0){ //only do == if you are in some sort of conditional/statement or loop
	cout << "Enter a command." << endl;
	cout << "Choose from [\"New\" \"Update\" \"View\" \"Donate\" \"Report\" \"Quit\"]" << endl;
        cin >> input;

        if (input == "New"){
            newInfo(lastName, firstName, age, streetNumber, streetName, town, zipCode, amountDonated);
        }

        if (input == "Login") {
          
        }

	if (input == "Update") {
	    update(lastName, firstName, age, streetNumber, streetName, town, zipCode);
	}

	if (input == "View") {
	    view(lastName, firstName, age, streetNumber, streetName, town, zipCode, amountDonated);
	}

	if (input == "Donate") {
	    donate(amountDonated);
	}

	if (input == "Report") {
	    report(lastName, amountDonated);
	}

	if(input == "Quit") {
	    keepGoing = 1;
	}

  }
}
