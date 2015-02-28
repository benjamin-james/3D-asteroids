#include "stdlib.h"
#include "math.h"
#include "SDL2/SDL.h"
#include "entity.h"
#include "util.h"

void showFatalError(char *msg)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Fatal Error!",msg,NULL);
	SDL_Quit();
	exit(-1);
}
void showWarning(char *msg)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING,"Warning!",msg,NULL);
}
inline float toDeg(float r)
{
	return r*180.f/M_PI;
}
inline float toRad(float r)
{
	return r*M_PI/180.f;
}
entity loadObj(char *str)
{
	entity e = NULL;
	return e;
}
