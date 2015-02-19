CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-lSDL2 -lSDL2_opengl -lopengl32
all:
  $(CC) $(CFLAGS) src/main.c src/game.c -o game $(LDFLAGS)
