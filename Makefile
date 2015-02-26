CC=gcc
CFLAGS=-march=native -g -Wall
LDFLAGS=-lm

ifeq ($(OS),Windows_NT)
	CCFLAGS += -D WIN32
	LDFLAGS += -mwindows -lmingw32 -lSDL2main -lSDL2 -lopengl32
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
        	LDFLAGS += -lSDL2 -lGL -lm
        endif
        ifeq ($(UNAME_S),Darwin)
        	CCFLAGS += -D OSX
        	LDFLAGS += -framework SDL -framework OpenGL -lm
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
