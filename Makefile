CC=gcc
CXX=g++
CXXFLAGS=-std=c++17
CFLAGS=-std=c17
LDFLAGS=-lncurses
ALLDEPENDON=includes.h

default_target: all
.PHONY : default_target all

all: shooter build

debug: debug_dir shooter_d 

debug_dir:
	-mkdir debug
build:
	-mkdir build

shooter: build/enemy.o build/main.o build/bar.o 
	$(CC) $(CFLAGS) build/{enemy,bar,main}.o -o shooter $(LDFLAGS)
build/enemy.o: enemy.h $(ALLDEPENDON) enemy.c
	$(CC) $(CFLAGS) -c enemy.c -o build/enemy.o
build/main.o: $(ALLDEPENDON) main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o
build/bar.o: $(ALLDEPENDON) bar.h bar.c
	$(CC) $(CFLAGS) -c bar.c -o build/bar.o

shooter_d: debug/enemy.o debug/main.o debug/bar.o 
	$(CC) $(CFLAGS) debug/{enemy,bar,main}.o -o shooter_d $(LDFLAGS)
debug/enemy.o: enemy.h $(ALLDEPENDON) enemy.c
	$(CC) $(CFLAGS) -g -c enemy.c -o debug/enemy.o
debug/main.o: $(ALLDEPENDON) main.c
	$(CC) $(CFLAGS) -g  -c main.c -o debug/main.o
debug/bar.o: $(ALLDEPENDON) bar.h bar.c
	$(CC) $(CFLAGS) -g -c bar.c -o debug/bar.o