all: monomio.exe polinomio.exe

CPPFLAGS = -g -Wall -ansi
OBJECTS = pruebaMonomio.o monomio.o
POL = pruebaPolinomio.o polinomio.o

monomio.exe: pruebaMonomio.o monomio.o
	g++ -o monomio.exe $(OBJECTS)

polinomio.exe: pruebaPolinomio.o polinomio.o
	g++ -o polinomio.exe $(POL)

pruebaPolinomio.o: pruebaPolinomio.cpp polinomio.cpp
	g++ -c $(CPPFLAGS) pruebaPolinomio.cpp

pruebaMonomio.o: pruebaMonomio.cpp monomio.hpp
	g++ -c $(CPPFLAGS) pruebaMonomio.cpp

polinomio.o: polinomio.cpp polinomio.hpp polinomioInterfaz.hpp
	g++ -c $(CPPFLAGS) polinomio.cpp

monomio.o: monomio.cpp monomio.hpp monomiointerfaz.hpp
	g++ -c $(CPPFLAGS) monomio.cpp

clean:
	rm -f $(OBJECTS) $(POL)
