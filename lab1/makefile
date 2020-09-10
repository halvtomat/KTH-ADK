CXX=g++
RM=rm -f

make: main tokenizer

seek: gen_hash.o seek.o
	g++ seek.o gen_hash.o -o seek

main: gen_hash.o gen_files.o main.o 
	g++ main.o gen_files.o gen_hash.o -o main

tokenizer: tokenizer.c
	gcc tokenizer.c -o tokenizer

main.o: main.cpp
	g++ -c main.cpp

gen_files.o: gen_files.cpp
	g++ -c gen_files.cpp

gen_hash.o: gen_hash.cpp
	g++ -c gen_hash.cpp

seek.o: seek.cpp
	g++ -c seek.cpp

clean:
	$(RM) *.o main result tokenizer