#include "game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

double joystick[2]; //joystick angle and magnitude

void render()
{

}
void update(double delta)
{

}
void handleKey(SDL_Keycode key, Uint32 status)
{
	if(status == SDL_PRESSED)
	{
	  //do stuff
	}
	else if(status == SDL_RELEASED)
	{
	  //do stuff
	}
}
void joystick(double x, double y) //range of [-1,1] for x and y
{
	joystick[0] = atan2(y,x);
	joystick[1] = hypot(x,y);
}
