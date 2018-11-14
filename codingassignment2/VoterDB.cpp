#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>
#include <string>
#include <fstream>
#include <assert.h>
#include <sstream>
#include "VoterDB.h"

using namespace std;

VoterDB::VoterDB() {

}

	bool VoterDB::checkid(const string &userid) {
		for(int i = 0;i < count; i++) {
			if(arr[i].getid()==userid) {
				cout << "User ID already taken." << endl;
				return false;
			}
		}
		for(int i = 0; i < userid.length(); i++) {
			if(!(isalnum(userid[i]))) { //function to check if chars are alphanumerical
				return false;
			}
		}
		if(userid.length() < 5) {
			return false;
		}
		if(userid.length() > 10) {
			return false;
		}
		return true;
	}

	bool VoterDB::checkpassword(const string &password){
		bool containsDigit = false;
		bool containsChar = false;
		for (int i = 0; i <password.size(); i++) {
			if (isdigit(password[i])) {
				containsDigit = true;
			}
			if (!(isalnum(password[i]) || isspace(password[i]))) {
				containsChar = true;
			}
		}
		if(password.length() < 6) {
			return false;
		}
		if(containsDigit && containsChar) {
			return true;

		} else {
			return false;
		}
	}

VoterDB::VoterDB(int numVoters) { //:: class and then method from that class - this method is the method from voterDB class
	arr = new Voter[numVoters]; //Voter *arr is a member variable of the class (VoterDB.h)
	arrSize = numVoters;
	count = 0;
	assert(arr != nullptr);
}

void VoterDB::login() {
	string userid;
	string password;
	cout << "Enter your user ID: " << endl;
	cin >> userid;
	cout << "Enter your password: " << endl;
	cin >> password;
	for (int i = 0; i < count; i++) {
		if (arr[i].getid() == userid && arr[i].getpass() == password) {
			arr[i].secondLevel();
			return;
		}
	}
	cout << "Invalid user ID or password." << endl;
}

void VoterDB::newInfo() {
if(count==arrSize) {
	cout << "Error: maximum number of new voters." << endl;
	return;}
string lastName;
string firstName;
string userid;
string password;
int age;
int streetNumber;
string streetName;
string town;
string zipCode; //make sure to note which are floats!!
float amountDonated = 0;
cout << "Last Name: " << endl;
cin >> lastName;
cout << "First Name: " << endl;
cin >> firstName;
cout << "User ID: " << endl;
cin >> userid;
while(!checkid(userid)) { //while checkid does not return true, go through this loop again
	cout << "Invalid user ID. ID must be at least 5 characters and at most 10, and can only contains characters and digits" << endl;
	cin >> userid;
}
cout << "Password: " << endl;
cin >> password;
while(!checkpassword(password)) {
	cout << "Invalid password. Password should be at least 6 characters, including at least one digit and one character that is neither a letter nor a digit" << endl;
	cin.ignore();
	cin >> password;
}
cout << "Age: " << endl;
cin >> age;
cout << "Street Number: " << endl;
cin >> streetNumber;
cout << "Street Name: " << endl;
cin.ignore();
getline(cin, streetName);
cout << "Town: " << endl;
//don't cin.ignore() if the previous was getline()
getline(cin, town);
cout << "Zip Code: " << endl;
cin >> zipCode;
while(zipCode.length() !=5) {
	cout << "Invalid zipcode. Enter a zipcode of 5 digits: " << endl;
	cin >> zipCode;
}
arr[count] = Voter(firstName, lastName, userid, password, age, streetName, streetNumber, town, zipCode, amountDonated);
count++;
}

void VoterDB::report() {
	cout << "Voters in database: ";
	cout << count;
	int tracker = 0;
	for (int i = 0; i < count; i++) {
		tracker += arr[i].getdonated();
	}
	cout << " Total amount of money donated: " << "$" << tracker << endl;
}

void VoterDB::save() {
   char ans = 'n';
   string fn;
   while(ans != 'y') {
      cout << "Enter name of file to save to: " << endl;
      cin >> fn;
      if (ifstream(fn.c_str())){
         cout << "File already exists. Type Y to overwrite." << endl;
         cin >> ans;
	 tolower(ans);
      } else { ans = 'y'; }
   }
   ofstream myfile;
   myfile.open(fn.c_str());
   myfile << count << endl;
   for (int i = 0; i < count; i++) {
      myfile << arr[i].save() << endl;
   }
   myfile.close();
}

void VoterDB::load(string fn) {
if (ifstream(fn.c_str())) { //must use .c_str here - stackoverflow
	ifstream myfile;
	myfile.open(fn.c_str());
	string line;
	int line1;
	float line2;
	myfile >> line;
	istringstream (line) >> count;
	for (int i = 0; i < count; i++){
		myfile >> line;
		arr[i].setLast(line);
		myfile >> line;
		arr[i].setFirst(line);
		myfile >> line;
		istringstream(line) >> line1;
		arr[i].setAge(line1);
		getline(myfile, line);
		getline(myfile, line);
		arr[i].setstreetName(line);
		myfile >> line;
		istringstream (line) >> line1;
		arr[i].setstreetNum(line1);
		getline(myfile, line);
		getline(myfile, line);
		arr[i].setTown(line);
		myfile >> line;
		arr[i].setZip(line);
		myfile >> line;
		arr[i].setUser(line);
		myfile >> line;
		arr[i].setPass(line);
		myfile >> line;
		istringstream (line) >> line2;
		arr[i].setDonated(line2);
		}
myfile.close();
} else { cout << "File does't exist. " << endl;
}
}
