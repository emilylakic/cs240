#
# Specifiy the target
all:	War

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
War:	PlayingCard.o Player.o Game.o Tournament.o Main.o
	g++ -lstdc++ Main.o PlayingCard.o Game.o Tournament.o Player.o  -o War.exe

# Specify how the object files should be created from source files
Main.o: Main.cpp
	g++ -c -g Main.cpp

LLC.o: LLC.cpp LLC.h
	g++ -c -g LLC.cpp

PlayingCard.o: PlayingCard.cpp PlayingCard.h
	g++ -c -g PlayingCard.cpp

Player.o: Player.cpp Player.h
	g++ -c -g Player.cpp

Game.o: Game.cpp Game.h
	g++ -c -g Game.cpp

Tournament.o: Tournament.cpp Tournament.h
	g++ -c -g Tournament.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o LLC.exe
