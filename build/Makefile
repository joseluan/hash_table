CC=g++
VC=c++11
.DEFAULT_GOAL=hash

Account.o: ../src/Account.cpp
	$(CC) ../src/Account.cpp -c -std=$(VC)

hash: ../src/main.cpp Account.o
	$(CC) ../src/main.cpp Account.o -o hash -std=$(VC)

clear:
	rm *.o
	rm hash