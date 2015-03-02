#include "SDL2/SDL.h"
#include "game.h"
#include "game_gl.h"
#include "events.h"
#include "util.h"
#include "signal.h"

int main(int argc, char **argv)
{
  int width = 800;
  int height = 600;
  signal(SIGSEGV,sighandler);
  signal(SIGINT,sighandler);
  signal(SIGFPE,sighandler);
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *window = SDL_CreateWindow(*argv, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);	
	if(!window) showFatalError("Could not create window");
  SDL_GL_CreateContext(window);
  GL_init();
  GL_setViewport(width, height);
  Uint32 now,last = SDL_GetTicks();
  SDL_ShowCursor(SDL_DISABLE);
  SDL_WarpMouseInWindow(window,width/2,height/2);
  game_init();
  while(input(window))
  {
  	render();
  	SDL_GL_SwapWindow(window);
  	now = SDL_GetTicks();
  	float delta = (now-last)/1000.0;
  	update(delta);
 	last = now;
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

