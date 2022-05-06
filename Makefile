main.exe : functions.o main.o
	g++ functions.o main.o -o main.exe
main.o : main.cpp functions.h
	g++ -Wall -c main.cpp
functions.o : functions.cpp functions.h
	g++ -Wall	-c functions.cpp
run: main.exe
	main.exe
clean:
	rm *.o main.exe
