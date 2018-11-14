#include "VoterDB.h"

int main(int argc, char *argv[]) { //argc = # of arguments passed to command line - always at least one
//argv = array of strings of the arguments (each element is an argument) - at 0 is the name of the program

  VoterDB db;

  if (argc == 2) {
    db = VoterDB(atoi(argv[1])); // OR VoterDB *db = new VoterDB etc.
  } else if (argc == 3) {
    db = VoterDB(atoi(argv[1]));
    string fn(argv[2]);
    db.load(fn);
  } else {
    cout << "Improper usage." << endl;
    exit(1);
  }

  string input;
  bool keepGoing = true;
  while(keepGoing){
  cout << "Enter a command. " << endl;
  cout << "Choose from [\"Login\" \"New\" \"Report\" \"Save\" \"Load\" \"Quit\"]" << endl;
  cin >> input;


  if (input == "Login") {
      db.login();
    }

  if (input == "New") {
      db.newInfo();
    }

  if (input == "Report") {
      db.report();
    }

  if (input == "Save") {
      db.save();
    }

  if (input == "Load") {
      string fn;
      cout << "Enter name of file to load from: " << endl;
      cin >> fn;
      db.load(fn);
    }
}
}
