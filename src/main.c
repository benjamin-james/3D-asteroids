#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

//extern void render();
//extern void update(double delta);
void initGL();
void setViewport(int w, int h);
int input();

int main(int argc, char **argv)
{
  int width = 800;
  int height = 600;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *window = SDL_CreateWindow(*argv, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);	
  SDL_GL_CreateContext(window);
  initGL();
  setViewport(WINDOW_WIDTH, WINDOW_HEIGHT);
  Uint32 last, now;
  last = SDL_GetTicks();
  while(input())
  {
  	render();
  	SDL_GL_SwapWindow(window);
  	now = SDL_GetTicks();
  	update(now-last);
 	last = now;
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

int input()
{
	SDL_Event e;
  	while(SDL_PollEvent(&e))
  	{
  		if(e.type == SDL_QUIT) return 0;
  		handleEvent(&e);
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
void setViewport(int width, int height)
{
	const GLdouble pi = 3.1415926535897932384626433832795;
	GLfloat ratio;
	if ( height == 0 ) height = 1;
	ratio = ( GLfloat )width / ( GLfloat )height;
	glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	GLdouble fW, fH;
	fH = tan( (45.0 / 2) / 180 * pi ) * 0.1f;
	fW = fH * ratio;
	glFrustum(-fW,fW,-fH,fH,0.1f,100.0f);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	return glGetError() == GL_NO_ERROR;
}
