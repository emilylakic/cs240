#
# Specifiy the target
all:	Voter

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Voter:	main.o Voter.o VoterDB.o
	g++  Voter.o main.o	VoterDB.o -o Voter.exe

# Specify how the object files should be created from source files
Voter.o:	Voter.cpp
	g++ -c Voter.cpp

VoterDB.o:	VoterDB.cpp
	g++ -c VoterDB.cpp

main.o: main.cpp
	g++ -c main.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Voter.exe
