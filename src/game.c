#include "game.h"
#include "matrix.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

vec3 stick = {0,0,0}; //joystick x y

vec3 pos = {0,0,-6};
vec3 rot = {0,0,0};

double speed = 2.0;
void render()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glPushMatrix();
	glRotatef(rot[0],1,0,0);
	glRotatef(rot[1],0,1,0);
	glRotatef(rot[2],0,0,1);
	glTranslatef(pos[0],pos[1],pos[2]);
	
	glBegin(GL_QUADS);

		/* Cube Top */
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);


		/* Cube Bottom */
		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		/* Cube Front */
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		/* Cube Back */
		glColor4f(0.0f, 1.0f, 0.5f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		/* Cube Left Side */
		glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		/* Cube Right Side */
		glColor4f(0.15f, 0.25f, 0.75f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
	
	glEnd();
	glPopMatrix();
	
	glLoadIdentity();
}
void update(double delta)
{
	rot[1] += delta*joy_stick[1];
	rot[2] += delta*joy_stick[0];
	pos[2] += delta*speed;
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
	stick[0] = x;
	stick[1] = y;
	//stick[0] = atan2(y,x); //polar
	//stick[1] = hypot(x,y);
}
