#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "VoterDB.h"

using namespace std;

	void newInfo(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &amountDonated) { 
		amountDonated = 0;
		cout << "Last Name: " << endl;
		cin >> lastName;
		cout << "First Name: " << endl;
		cin >> firstName; 
                cout << "Age: " << endl;
		cin >> age;
		cout << "Street Number: " << endl;
		cin >> streetNumber;
		cout << "Street Name: " << endl;
		cin >> streetName;
		cout << "Town: " << endl;
		cin >> town;
		cout << "Zip Code: " << endl;
		cin >> zipCode;
	}

	void update(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode) { 
		cout << "What would you like to change the last name to? " << endl;
		cin >> lastName;
		cout << "What would you like to change the first name to? " << endl;
		cin >> firstName; 
                cout << "What would you like to change the age to? " << endl;
		cin >> age;
		cout << "What would you like to change the street number to? " << endl;
		cin >> streetNumber;
		cout << "What would you like to change the street number to? " << endl;
		cin >> streetName;
		cout << "What would you like to change the town to? " << endl;
		cin >> town;
		cout << "What would you like to change the zip code to? " << endl;
		cin >> zipCode;
	}


	void view(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &amountDonated) { 
		cout << "Donor Info:" << endl;
		cout << firstName << " " << lastName << ":"  <<" age " << age << endl;
		cout << streetNumber << " " << streetName << endl;
		cout << town << " " << zipCode << endl;
		cout << "Current Amount Donated: " << "$" << amountDonated << endl;
}

	int donate(float &amountDonated) { 
		float amount;
		cin >> amount;
		cout << "Enter Amount to Donate: ";
		amountDonated = amount + amountDonated;
		cout << fixed << setprecision(2);
		cout<< " $" << amount << "  donated." << endl;
	}

	void report(string &lastName, float &amountDonated) { 
		cout << fixed;
		cout << setprecision(2);
		cout << lastName << " $" << amountDonated << endl; 
}

		
