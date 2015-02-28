#ifndef EVENTS_H
#define EVENTS_H

#include "SDL2/SDL.h"
#include "matrix.h"	//vec3
int input(SDL_Window *);
void setAcceleration(double);
vec3 getInput();
#endif
