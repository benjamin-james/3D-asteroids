#include "SDL2/SDL.h"
#include "events.h"
#include "matrix.h"	//setAcceleration,joystick
#include "game_gl.h"	//setViewport


static vec3 rot = {0,0,0};//joystick x y is look, z is acceleration
			//i.e. the camera
void setAcceleration(double d)
{
	rot.z = d;
}
vec3 getInput()
{
	return rot;
}
int input(SDL_Window *window)
{
	SDL_Event e;
	int x,y;
  	while(SDL_PollEvent(&e))
  	{
  		switch(e.type)
  		{
  			case SDL_QUIT: 		return 0;
  			case SDL_WINDOWEVENT:	if(e.window.type == SDL_WINDOWEVENT_CLOSE) return 0;
  						if(e.window.type == SDL_WINDOWEVENT_RESIZED)	//reset the view if the window size has changed
  						{
  							GL_setViewport(e.window.data1,e.window.data2);
  						}
  						break;
  			case SDL_KEYDOWN:	if(e.key.keysym.sym == SDLK_ESCAPE) return 0;	//handling keys here for movement
  						else if(e.key.keysym.sym == SDLK_UP)
  						{
  							setAcceleration(0.5);
  						}
  						else if(e.key.keysym.sym == SDLK_DOWN)
  						{
  							setAcceleration(-0.5);
  						}
  						break;
  			case SDL_KEYUP:		if(e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_DOWN)
  						{
  							setAcceleration(0.0);
  						}
  						break;
  			case SDL_MOUSEMOTION: 	rot.x = e.motion.xrel;
						rot.y = -e.motion.yrel;//inverted y because mouse down means y goes up
  						SDL_GetWindowSize(window,&x,&y);
						SDL_WarpMouseInWindow(window,x/2,y/2);//put mouse at center so that it doesn't move away
  						break;
  		}
  	}
  	return 1;
}
