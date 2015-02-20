#include "game.h"
#include "matrix.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

vec3 stick = {0,0,0}; //joystick x y

vec3 pos = {0,0,-6};
vec3 rot = {0,0,0};

GLfloat speed = 2.0;
void render()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glPushMatrix();
	glRotatef(rot.x,1,0,0);
	glRotatef(rot.y,0,1,0);
	glRotatef(rot.z,0,0,1);
	glTranslatef(pos.x,pos.y,pos.z);
	
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
	rot.x += delta*stick.y;
	rot.z += delta*stick.x;
	vec3 dVec = vec3_rot(_vec3(0.f,0.f,speed*delta),rot);
	pos.x += dVec.x;
	pos.y += dVec.y;
	pos.z += dVec.z;
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
	stick.x = x;
	stick.y = y;
	//stick.x = atan2(y,x); //polar
	//stick.y = hypot(x,y);
}
