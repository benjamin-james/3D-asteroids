#include "game.h"
#include "matrix.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

vec3 stick = {0,0,0}; //joystick x y

vec3 pos = {0,0,-6};
vec3 rot = {0,0,0};

GLfloat speed = 2.0;

void renderShip()
{
	glRotatef(rot.x,1,0,0);
	glRotatef(rot.y,0,1,0);
	glRotatef(rot.z,0,0,1);
	glTranslatef(-pos.x,-pos.y,-pos.z);
	glBegin(GL_TRIANGLES);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.5f, 0.0f, -0.5f);
		glVertex3f(0.0f, 0.0f, 2.0f);
		
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.5f, 0.0f, -0.5f);
		glVertex3f(0.0f, 0.0f, 2.0f);

		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, -0.5f);
		glVertex3f(0.0f, 0.0f, 2.0f);
	}
	glEnd();
}
void render()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glPushMatrix();
	glBegin(GL_QUADS);
		glColor4f(0.15f,0.9f,0.3f,1.0f);
		glVertex3f(-10.0f,-1.0f,10.0f);
		glVertex3f(-10.0f,-1.0f,-10.0f);
		glVertex3f(10.0f,-1.0f,-10.0f);
		glVertex3f(10.0f,-1.0f,10.0f);
	glEnd();
	renderShip();
	glPopMatrix();
	
	glLoadIdentity();
}
void update(double delta)
{
	rot.y += 10*delta*stick.y;
	rot.x += 10*delta*stick.x;
	speed += delta*stick.z;
	if(speed)//used for movement
	{
		//vec3 dVec = vec3_rot(_vec3(0.f,0.f,speed*delta),rot);
		vec3 dVec = _vec3(speed*delta*sinf(rot.x)*cosf(rot.y),speed*delta*sinf(rot.x)*sinf(rot.y),speed*delta*cosf(rot.x));		
		pos.x += dVec.x;
		pos.y += dVec.y;
		pos.z += dVec.z;
	}
}
void handleKey(SDL_Keycode key, Uint32 status)
{
	if(status == SDL_PRESSED)
	{
	  if(key == SDLK_UP) stick.z = 0.5f;
	  else if(key == SDLK_DOWN) stick.z = -0.5f;
	}
	else if(status == SDL_RELEASED)
	{
	  stick.z = 0;
	}
}
void joystick(double x, double y) //range of [-1,1] for x and y
{
	stick.x = x;
	stick.y = y;
	//stick.x = atan2(y,x); //polar
	//stick.y = hypot(x,y);
}
