# Makefile for World project
binary: lib_database.a Interface.o main.o
	g++ -o binary main.o Interface.o -L. -l_database
main.o: main.cpp
	g++ -c main.cpp
lib_database.a: Database.o InsurancePolicy.o
	ar cr lib_database.a Database.o InsurancePolicy.o
Database.o: Database.cpp
	g++ -c Database.cpp
InsurancePolicy.o: InsurancePolicy.cpp
	g++ -c InsurancePolicy.cpp
Interface.o: Interface.cpp
	g++ -c Interface.cpp
clean:
	rm -f *.o *.a binary