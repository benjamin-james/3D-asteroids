CC=gcc
CFLAGS=-g -Wall -Og
LDFLAGS=-lSDL2 -lGL -lm
game: src/main.c src/game.c src/matrix.c
	$(CC) $(CFLAGS) src/main.c src/game.c src/matrix.c -o game $(LDFLAGS)
