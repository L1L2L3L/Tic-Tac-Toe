CC = g++
CXXFLAGS = -O2 -std=c++14
LDFLAGS = -lstdc++
OUT = Ticgame

all: Ticgame

Ticgame: main.o libTicTacToe.a
	$(CC) main.o libTicTacToe.a -o $(OUT) $(LDFLAGS)

main.o: main.cpp TicTacToe.h
	$(CC) -c main.cpp $(CXXFLAGS)

TicTacToe.o: TicTacToe.cpp TicTacToe.h
	$(CC) -c TicTacToe.cpp $(CXXFLAGS)

libTicTacToe.a: TicTacToe.o
	ar rcs libTicTacToe.a TicTacToe.o
clean:
	rm -f *.o *.a $(OUT)
