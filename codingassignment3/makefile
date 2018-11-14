#
# Specifiy the target
all:	PlayingCard

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
PlayingCard:   main.o LLC.o
	g++  main.o LLC.o -o LLC.exe

# Specify how the object files should be created from source files
LLC.o:	LLC.cpp
	g++ -c -g LLC.cpp

main.o: main.cpp
	g++ -c -g main.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o LLC.exe
