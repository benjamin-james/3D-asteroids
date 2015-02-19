CC=gcc
CFLAGS=-g -Wall -Og
LDFLAGS=-lSDL2 -lGL
game: src/main.c src/game.c
	$(CC) $(CFLAGS) src/main.c src/game.c -o game $(LDFLAGS)
