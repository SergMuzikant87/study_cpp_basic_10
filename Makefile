CC := g++
FLAGS := -Wall -O2 -std=c++11 -g

all:
	$(CC) $(FLAGS) programm_1.cpp -o programm_1
	$(CC) $(FLAGS) programm_2.cpp -o programm_2
	$(CC) $(FLAGS) programm_3.cpp -o programm_3

