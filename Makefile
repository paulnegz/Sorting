sort: main.o Executive.o
	g++ -std=c++11 -g -Wall -o sort main.o Executive.o

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Sorts.h Sorts.hpp SortTimer.h SortTimer.hpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o sort
