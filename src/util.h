#ifndef UTIL_H
#define UTIL_H

#define DEBUG 1 //for now
#include "entity.h"
#include "SDL2/SDL_opengl.h"
#include "math.h"

#define toDeg(r) (r*180/M_PI)
#define toRad(r) (r*M_PI/180)
void showFatalError(char *);
void showWarning(char *); 
//inline float toDeg(float);
//inline float toRad(float);
entity loadObj(char *);
char *loadFile(char *);
GLuint loadBMP(char *);
#endif
