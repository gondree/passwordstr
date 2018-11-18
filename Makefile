.PHONY: all clean
CC=g++

all: passwordstr broken mpa_example

broken.o: src/broken.cpp
mpa_example.o: example/mpa_example.cpp
StringRules.o: src/StringRules.cpp
util.o : src/util.cpp
passwordstr.o: passwordstr.cpp

%.o:
	$(CC) $< -c -g -Iinclude -o $@

passwordstr: passwordstr.o StringRules.o util.o
	$(CC) $^ -lgmpxx -lgmp  -o $@

mpa_example: mpa_example.o util.o
	$(CC) $^ -lgmpxx -lgmp  -o $@

broken: broken.o
	$(CC) $^  -o $@

clean:
	rm -f *.o passwordstr broken
	rm -f mpa_example custom_example
