#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "game.h"

void initGL();
void setViewport(int w, int h);
int input(SDL_Window *window);
int main(int argc, char **argv)
{
  int width = 800;
  int height = 600;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *window = SDL_CreateWindow(*argv, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);	
  SDL_GL_CreateContext(window);
  initGL();
  setViewport(width, height);
  Uint32 now,last = SDL_GetTicks();
  SDL_ShowCursor(SDL_DISABLE);
  SDL_WarpMouseInWindow(window,width/2,height/2);
  init();
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
  						if(e.window.type == SDL_WINDOWEVENT_RESIZE)	//reset the view if the window size has changed
  						{
  							setViewport(event->window.data1,event->window.data2);
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
  			case SDL_MOUSEMOTION: 	joystick(e.motion.xrel,-e.motion.yrel);//inverted y because mouse down means y goes up
  						SDL_GetWindowSize(window,&x,&y);
						SDL_WarpMouseInWindow(window,x/2,y/2);//put mouse at center so that it doesn't move away
  						break;
  		}
  	}
  	return 1;
}
void initGL()
{
	glShadeModel( GL_SMOOTH );
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClearDepth( 1.0f );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}
//setting a screen size (upon creation or resize of window)
void setViewport(int width, int height)
{
	const GLdouble pi = 3.1415926535897932384626433832795;
	GLfloat ratio;
	if ( height == 0 ) height = 1;
	ratio = ( GLfloat )width / ( GLfloat )height;
	glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	/*gluPerspective alternative*/
	GLdouble fW, fH;
	fH = tan( (45.0 / 2) / 180 * pi ) * 0.1f;
	fW = fH * ratio;
	glFrustum(-fW,fW,-fH,fH,0.1f,100.0f);
	/*gluPerspective alternative end*/
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}
