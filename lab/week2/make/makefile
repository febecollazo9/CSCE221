all: hello

hello: main.o file1.o
	g++ file1.o main.o -o main
file1.o: file1.cpp
	g++ -c file1.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o main
run:
	./main
