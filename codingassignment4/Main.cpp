#include "Tournament.h"
#include <cstdlib>
#include <fstream>

int main(int argc,char *argv[]) {
	if(argc < 3) {

		cerr << "More inputs needed." << endl;
		exit(1);

  }

  string pfile = argv[1];
  string lfile = argv[2];
  Tournament tournament;
  tournament.readFile(pfile);
  tournament.lfile = lfile;
  tournament.playTournament();

}
