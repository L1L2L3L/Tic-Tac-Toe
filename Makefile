CC = g++
CXXFLAGS = -std=c++14
LDFLAGS = -lstdc++

all: TicTacToe

TicTacToe: main.o TicTacToe.o
	$(CC) main.o TicTacToe.o -o TicTacToe $(LDF)

main.o: main.cpp TicTacToe.h
	$(CC) -c main.cpp $(CXXF)

TicTacToe.o: TicTacToe.cpp TicTacToe.h
	$(CC) -c TicTacToe.cpp $(CXXF)

clean:
	rm -rf *.o TicTacToe
