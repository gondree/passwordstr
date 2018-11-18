.PHONY: all clean
CC=g++

all: passwdstr broken mpa_example

broken.o: src/broken.cpp
mpa_example.o: example/mpa_example.cpp
StringRules.o: src/StringRules.cpp
util.o : src/util.cpp
passwdstr.o: passwdstr.cpp

%.o:
	$(CC) $< -c -g -Iinclude -o $@

passwdstr: passwdstr.o StringRules.o util.o
	$(CC) $^ -lgmpxx -lgmp  -o $@

mpa_example: mpa_example.o util.o
	$(CC) $^ -lgmpxx -lgmp  -o $@

broken: broken.o
	$(CC) $^  -o $@

clean:
	rm -f *.o passwdstr broken
	rm -f mpa_example custom_example
