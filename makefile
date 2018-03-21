game: main.o player.o menu.o
	g++ main.o player.o menu.o -o game -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp
	
player.o: player.cpp player.h
	g++ -c player.cpp
	
menu.o: menu.cpp menu.h
	g++ -c menu.cpp

button.o : button.cpp button.h
	g++ -c button.cpp
