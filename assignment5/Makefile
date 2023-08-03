CovidDB: main.o CovidDB.o
	g++ -o CovidDB main.o CovidDB.o

assignment3.o: main.cpp CovidDB.h
	g++ -c -Wall -Werror -pedantic -std=c++11 main.cpp

CovidDB.o: CovidDB.cpp CovidDB.h
	g++ -c -Wall -Werror -pedantic -std=c++11 CovidDB.cpp
