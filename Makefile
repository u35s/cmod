CFLAG= -g -Wall
gcc=g++ -std=c++11 $(CFLAG) 
default:main

utils.o:
	$(gcc) -o utils.o -c utils/time.cpp

mods.o:
	$(gcc) -o mods.o -c mods/test.cpp 

main:utils.o mods.o
	$(gcc) -o cmod utils.o mods.o loop.cpp main.cpp 

clean :
	rm *.o
	rm -rf *dSYM
	rm cmod
