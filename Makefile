CC=gcc
CFLAGS=-g -Wall -Og
LDFLAGS=-lSDL2 -lSDL2_opengl -lGL
game: src/main.c src/game.c
	$(CC) $(CFLAGS) src/main.c src/game.c -o game $(LDFLAGS)
