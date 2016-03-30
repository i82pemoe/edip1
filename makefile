all: monomio.exe polinomio.exe

CPPFLAGS =  -c -g -Wall -ansi
OBJECTS = pruebaMonomio.o monomio.o
POL = pruebaPolinomio.o polinomio.o

monomio.exe: pruebaMonomio.o monomio.o
	g++ -o monomio.exe $(OBJECTS)

polinomio.exe: pruebaPolinomio.o polinomio.o
	g++ -o polinomio.exe $(POL)

pruebaPolinomio.o: pruebaPolinomio.cpp polinomio.cpp
	g++  $(CPPFLAGS) pruebaPolinomio.cpp

pruebaMonomio.o: pruebaMonomio.cpp monomio.hpp monomiointerfaz.hpp
	g++  $(CPPFLAGS) pruebaMonomio.cpp

polinomio.o: polinomio.cpp polinomio.hpp polinomioInterfaz.hpp
	g++  $(CPPFLAGS) polinomio.cpp

monomio.o: monomio.cpp monomio.hpp monomiointerfaz.hpp
	g++  $(CPPFLAGS) monomio.cpp

clean:
	rm -f $(OBJECTS) $(POL)
