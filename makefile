final: go_fish.o player.o deck.o card.o
	g++ -std=c++11 -o test go_fish.cpp player.cpp card.cpp deck.cpp
