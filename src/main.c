#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

int main(int argc, char **argv)
{
  int width = 800;
  int height = 600;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *window = SDL_CreateWindow(*argv, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);	
  SDL_GL_CreateContext(window);
	Display_InitGL();
	Display_SetViewport(WINDOW_WIDTH, WINDOW_HEIGHT);
  int running = 1;
	while(running)
	{
	  SDL_Event e;
	  while(SDL_PollEvent(&e))
	  {
	    if(e.type == SDL_QUIT) running = 0;
	    handleEvent(&e);
	  }
	  Display_Render(window);
	}
	SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
