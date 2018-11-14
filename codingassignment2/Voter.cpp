#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Voter.h"
#include <sstream>

using namespace std;

Voter::Voter()
{
  lastName = "";
  firstName = "";
  userid = "";
  password = "";
  passage = "";
  passstreetnumber = "";
  age = -1;
  streetNumber = -1;
  streetName = "";
  town = "";
  zipCode = "";
  updateamount = "";
  amountDonated = 0.0;
  donatedAmount = 0.0;
  oldPass = "";
  newPass = "";
  confirmed = "";
  ///0.0 for floats and -1 for integers
  //do the rest of the strings '="";'
  //cout << "Fill in code for a default constructor." << endl;
}

Voter::Voter(string first, string last, string ID, string pass, int ag, string sname, int snumber, string tow, string zip, float dona){
  firstName = first;
  lastName = last;
  userid = ID;
  password = pass;
  age = ag;
  streetName = sname;
  streetNumber = snumber;
  town = tow;
  zipCode = zip;
  amountDonated = 0;
} //if it has the same name you need this.

void Voter::secondLevel(){
  string input;
  bool keepGoing = true;
  while(keepGoing){
	cout << "Enter a command. " << endl;
	cout << "Choose from [\"Update\" \"Password\" \"View\" \"Donate\" \"Report\" \"Logout\"]" << endl;

cin >> input;

  if (input == "Update"){
      update();
    }

  else if (input == "Password") {
      passwd();
    }

	else if (input == "View") {
	    view();
	}

	else if (input == "Donate") {
	    donate();
	}

	else if (input == "Report") {
	    report();
	}

	else if(input == "Logout") {
	    return;
	}

	else {
	    cout << "Invalid command. Enter a correct command: " << endl;
	}
  }
}

string Voter::getid() {
  return userid;
}

string Voter::getpass() {
  return password;
}

float Voter::getdonated() {
  return amountDonated;
}

string Voter::save() {
  return lastName + ',' + ' ' + firstName + ',' + ' ' + userid + ',' + ' ' + password + ',' + ' ' + to_string(age) + ',' + ' ' + to_string(streetNumber) + ',' + ' ' + streetName + ',' + ' ' +  town + ',' + ' ' + zipCode + ',' + ' ' + to_string(amountDonated);
}

void Voter::setUser(string us) {
  userid = us;
}

void Voter::setPass(string pas) {
  password = pas;
}
void Voter::setLast(string ln) {
	lastName = ln; }

void Voter::setFirst(string fr) {
  firstName = fr; }

void Voter::setstreetName(string stn) {
  streetName = stn; }

void Voter::setstreetNum(int num) {
  streetNumber = num; }

void Voter::setDonated(float stDon) {
  amountDonated = stDon; }

void Voter::setTown(string tn) {
	town = tn; }

void Voter::setAge(int ag) {
  age = ag; }

void Voter::setZip(string zipp) {
  zipCode = zipp;
}

void Voter::update() {

	bool boolean = true;
  int integer;
	char character;
	string temp;

	cout << "Enter your last name: " << endl;
	while (boolean) {
		boolean = false;
		cin.ignore();
		getline(cin, temp);
		if(temp != "") {
      for (int i = 0; i < lastName.length(); i++){
      character = lastName[i];
          if (!((character >= 'a' && character <= 'z') || (character >='A' && character <='Z'))){
  	           cout << "Name must only contain letters." << endl;
               boolean = true;
	        }
           else {
             lastName = temp;
             boolean = false;
           }
         }
       }
     }

		boolean = true;
		cout << "Enter your first name: " << endl;
		while (boolean){
			boolean = false;
			getline(cin, temp);
			   if(temp != "") {
           for (int i = 0; i < firstName.length(); i++){
	           character = firstName[i];
               if (!(isalpha(character))){
                  cout << "Name must only contain letters." << endl;
                  boolean = true;
                } else {
                firstName = temp;
                boolean = false; }
	            }
          }
			}

    boolean = true;
    cout << "Enter your age: " << endl;
    while(boolean) {
      boolean = false;
			getline(cin, passage);
			if(temp != "") {
				for (int i = 0; i < passage.length(); i++){
					character = passage[i];
					if(!isdigit(character)) {
						boolean = true;
						cout << "Please enter an integer." << endl;
					}
				}
      }
				if (!boolean){
					istringstream (passage) >> age;
					if(age < 18) {
						boolean = true;
						cout << "Please enter an integer greater than 18." << endl;
					}
				}
			}

  boolean = true;
  cout << "Enter your street number: " << endl;
	while (boolean) {
			boolean = false;
			getline(cin, passstreetnumber);
			if(temp != "") {
			     for (int i = 0; i < passstreetnumber.length(); i++){
			         character = passstreetnumber[i];
		           if(!isdigit(character)) {
			            boolean = true;
                  cout << "Enter an integer: " << endl;
				} /*else {
        passstreetnumber = temp;
        boolean = false; }*/
      }
		}
			if (!boolean){
				istringstream (passstreetnumber) >> streetNumber;
				if(streetNumber <= 0) {
					boolean = true;
					cout << "Enter an integer greater than 0: " << endl;
				}
			}
	}

	cout << "Enter your street name: " << endl;
	getline(cin,streetName);
	cout << "Enter your town: " << endl;

	getline(cin, town);

	cout << "Enter your zip code: " << endl;
	boolean = true;
	while (boolean){

		boolean = false;
		cin >> zipCode;

		if(zipCode.length() != 5) {
			boolean = true;
			cout << "Zip code requires 5 digits." << endl;
		}
		else {
			for (int i = 0; i < zipCode.length(); i++){
			character = zipCode[i];
			if(!isdigit(character)) {
				boolean = true;
				cout << "Only integers accepted." << endl;
			     }
		      }
         }
       }
     }

void Voter::view() {
		cout << "Donor Info: " << endl;
		cout << firstName << " " << lastName << ":"  <<" age " << age << endl;
		cout << streetNumber << " " << streetName << endl;
		cout << town << " " << zipCode << endl;
		cout << "Current Amount Donated: " << "$" << amountDonated << endl;
}

void Voter::passwd(){
  bool numb = false;
  bool letter = false;
  bool other = false;
  char char1;
  cout << "Enter current password: " << endl;
  cin >> oldPass;
  if (oldPass == password) {
    cout << "Enter a new password: " << endl;
    cin >> newPass;
    cout << "Confirm new password: " << endl;
    cin >> confirmed;
    if(newPass != confirmed) {
      cout << "New password does not match confirmation." << endl;
    } else {
    password = newPass;}

      for (int i = 0; i < newPass.length(); i++) {
        char1 = newPass[i];
        if(isdigit(char1)) {
          numb = true;
        }
        else if(isalpha(char1)) {
          letter = true;
        }
        else {
          other = true;
        }
      }
  } else {
    cout << "Password change denied." << endl;
  }
}

  void Voter::donate() {
  	bool boolean = true;
  	char char1;
  	cout.precision(2);
  	cout << "Current Amount Donated: $" << fixed << amountDonated << endl;
  	cout << "Enter Amount to Donate: $ ";

  	boolean = true;
  	while (boolean) {
  		int counter = 0;
  		boolean = false;
  		cin >> updateamount;
  		for (int i = 0; i < updateamount.length(); i++){
  			char1 = updateamount[i];
  			if (char1 == '.') {
  				counter++;
  			}
  			else if(!(isdigit(char1))) {
  				boolean = true;
  				cout << "Enter valid float: " << endl;
  			}
  		}
  		if (counter>=2) {
  			boolean = true;
  			cout << "Enter valid float: " << endl;
  		}
  }
  	donatedAmount=(double)atof(updateamount.c_str());
  	if (amountDonated + donatedAmount <= 2700) {
  		amountDonated += donatedAmount;
  	}
  	else {
  		cout << "Warning: You may not donate more than $2700." << endl;
  	}
  }

  void Voter::report() {
  	cout << fixed;
  	cout << setprecision(2);
  	cout << lastName << " $" << amountDonated << endl;
  }
