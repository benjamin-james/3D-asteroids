CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-lSDL2 -lm

ifeq ($(OS),Windows_NT)
	CCFLAGS += -D WIN32
	LDFLAGS += -mwindows -lmingw32 -lSDL2main -lopengl32
   	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
        	CCFLAGS += -D AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
        	CCFLAGS += -D IA32
        endif
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
        	CCFLAGS += -D LINUX
        	LDFLAGS += -lGL
        endif
        ifeq ($(UNAME_S),Darwin)
        	CCFLAGS += -D OSX
        	LDFLAGS += -framework OpenGL
        endif
        UNAME_P := $(shell uname -p)
        ifeq ($(UNAME_P),x86_64)
        	CCFLAGS += -D AMD64
        endif
        ifneq ($(filter %86,$(UNAME_P)),)
        	CCFLAGS += -D IA32
        endif
        ifneq ($(filter arm%,$(UNAME_P)),)
        	CCFLAGS += -D ARM
        endif
endif
game: src/*.c
	$(CC) $(CFLAGS) src/*.c -o game $(LDFLAGS)
