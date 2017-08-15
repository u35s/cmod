CFLAG= -g -Wall
gcc=g++ -std=c++11 $(CFLAG) 
default:main

utils.o: utils/time.cpp
	$(gcc) -o $@ -c $^ 

mods.o: mods/test.cpp
	$(gcc) -o $@ -c $^ 

main:utils.o mods.o loop.cpp main.cpp
	$(gcc) -o cmod $^ 

clean :
	rm *.o
	rm -rf *dSYM
	rm cmod
