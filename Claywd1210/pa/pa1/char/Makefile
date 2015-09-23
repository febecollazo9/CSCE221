all: My_vec.o main.o
	g++ My_vec.o main.o -o main
My_vec.o: My_vec.cpp My_vec.h
	g++ -c -g My_vec.cpp
main.o: main.cpp My_vec.h
	g++ -c -g main.cpp
clean:
	rm *.o main.out
