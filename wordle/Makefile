#------------------------------------------------------------------------------
# Makefile for CSE 101 Programming Assignment 1
#
# make                   makes Lex
# make ListClient        makes ListClient
# make clean             removes all binaries
# make checkClient       checks ListClient for memory errors
# make checkLex          checks Lex for memory errors
#------------------------------------------------------------------------------

solver: solver.o
	g++ -std=c++17 -g -Wall -o solver solver.o

solver.o : solver.cpp
	g++ -std=c++17 -g -Wall -c solver.cpp

clean :
	rm -f solver.o solver

format:
	clang-format -i -style=file *.cpp
