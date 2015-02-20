#include "game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

double joystick[2]; //joystick angle and magnitude

double x,y,z,rx,ry,rz;
double speed = 2.0;
void render()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glRotatef(rx,1,0,0);
	glRotatef(ry,0,1,0);
	glRotatef(rz,0,0,1);
	glTranslatef(x,y,z);
	
	glBegin(GL_TRIANGLES);
	{
		glColor4f(1,0,0,1);
		glVertex3f(0,0,1);
		glVertex3f(0.5,0,-0.5);
		glVertex3f(0,0,-0.2);
		
		glVertex3f(0,0,-0.2);
		glVertex3f(-0.5,0,-0.5);
		glVertex3f(0,0,1);
		
		glColor4f(0,0,1,1);
		glVertex3f(0,0,1);
		glVertex3f(0,0,-0.2);
		glVertex3f(0,0.5,-0.5);
	}
	glEnd();
}
void update(double delta)
{
	ry += delta*joystick[1];
	rz += delta*joystick[0];
	z += delta*speed;
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
	joystick[0] = x;
	joystick[1] = y;
	//joystick[0] = atan2(y,x);
	//joystick[1] = hypot(x,y);
}
