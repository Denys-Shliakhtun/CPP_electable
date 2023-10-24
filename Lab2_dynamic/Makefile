# Makefile for World project
binary: lib_database.so Interface.o main.o
	g++ -o binary main.o Interface.o -L. -l_database -Wl,--rpath,.
main.o: main.cpp
	g++ -c main.cpp
lib_database.so: Database.o InsurancePolicy.o
	g++ -shared -o lib_database.so Database.o InsurancePolicy.o
Database.o: Database.cpp
	g++ -c -fPIC Database.cpp
InsurancePolicy.o: InsurancePolicy.cpp
	g++ -c -fPIC InsurancePolicy.cpp
Interface.o: Interface.cpp
	g++ -c Interface.cpp
clean:
	rm -f *.o *.so binary