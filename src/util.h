#ifndef UTIL_H
#define UTIL_H

#define DEBUG 1 //for now
#include "entity.h"

void showFatalError(char *);
void showWarning(char *); 
inline float toDeg(float);
inline float toRad(float);
entity loadObj(char *);

#endif
