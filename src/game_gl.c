#include "SDL2/SDL_opengl.h"
#include "math.h"
#define VIEWPORT_ANGLE (M_PI/4)

//setting up the constants
void GL_init()
{
	glShadeModel( GL_SMOOTH );
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClearDepth( 1.0f );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

/*
 *	setting a screen size (upon creation or resize of window)
 *	using fov of 45 degrees (pi/4), near clipping pane of 0.1f,
 *	far clipping pane as 100.0f, and uses glFrustum to compute
 *	the viewport
 */
void GL_setViewport(int width, int height)
{
	GLfloat ratio;
	if ( height == 0 ) height = 1;
	ratio = ( GLfloat )width / ( GLfloat )height;
	glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	/*gluPerspective alternative*/
	GLdouble fW, fH;
	fH = tan( VIEWPORT_ANGLE / 2 ) * 0.1f;
	fW = fH * ratio;
	glFrustum(-fW,fW,-fH,fH,0.1f,100.0f);
	/*gluPerspective alternative end*/
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}
