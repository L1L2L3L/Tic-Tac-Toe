CC = g++
CXXFLAGS = -O2 -std=c++14
LDFLAGS = -lstdc++
OUT = Ticgame

all: $(OUT)

$(OUT): main.o TicTacToe.o
	$(CC) main.o TicTacToe.o -o $(OUT) $(LDFLAGS)

main.o: main.cpp TicTacToe.h
	$(CC) -c main.cpp $(CXXFLAGS)

TicTacToe.o: TicTacToe.cpp TicTacToe.h
	$(CC) -c TicTacToe.cpp $(CXXFLAGS)

clean:
	rm -f *.o $(OUT)
