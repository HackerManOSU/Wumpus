CXX = g++
CXXFLAGS = -Wall -g
OBJ = main.o Player.o Room.o Wumpus.o Bats.o Stalactites.o Gold.o GameGrid.o Game.o
DEPS = Player.h Room.h Event.h Wumpus.h Bats.h Stalactites.h Gold.h GameGrid.h Game.h

all: wumpus

wumpus: $(OBJ)
	$(CXX) $(CXXFLAGS) -o wumpus $(OBJ)

main.o: main.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c main.cpp

Player.o: Player.cpp Player.h
	$(CXX) $(CXXFLAGS) -c Player.cpp

Room.o: Room.cpp Room.h
	$(CXX) $(CXXFLAGS) -c Room.cpp

Wumpus.o: Wumpus.cpp Wumpus.h
	$(CXX) $(CXXFLAGS) -c Wumpus.cpp

Bats.o: Bats.cpp Bats.h
	$(CXX) $(CXXFLAGS) -c Bats.cpp

Stalactites.o: Stalactites.cpp Stalactites.h
	$(CXX) $(CXXFLAGS) -c Stalactites.cpp

Gold.o: Gold.cpp Gold.h
	$(CXX) $(CXXFLAGS) -c Gold.cpp

GameGrid.o: GameGrid.cpp GameGrid.h
	$(CXX) $(CXXFLAGS) -c GameGrid.cpp

Game.o: Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

clean:
	rm -f *.o wumpus
