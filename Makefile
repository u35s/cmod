CFLAG= -g -Wall
gcc=g++ -std=c++11 $(CFLAG) 
default:main

time.o:utils/time.cpp
	$(gcc) -c utils/time.cpp

loop.o:time.o 
	$(gcc) -c loop.cpp 

main:loop.o
	$(gcc) -o cmod loop.o time.o main.cpp 

clean :
	rm cmod
	rm *.o
	rm -rf *dSYM
