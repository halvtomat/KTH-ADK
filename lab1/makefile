CXX=g++
RM=rm -f

make: main tokenizer

main: main.o gen_index.o gen_hash.o
	g++ main.o gen_index.o gen_hash.o -o main

tokenizer: tokenizer.c
	gcc tokenizer.c -o tokenizer

main.o: main.cpp
	g++ -c main.cpp

gen_index.o: gen_index.cpp
	g++ -c gen_index.cpp

gen_hash.o: gen_hash.cpp
	g++ -c gen_hash.cpp

clean:
	$(RM) *.o main result tokenizer