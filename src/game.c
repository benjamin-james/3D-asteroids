#include "stdlib.h"
#include "game.h"
#include "matrix.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

vec3 stick = {0,0,0}; //joystick x y

vec3 pos = {0,0,-5};
vec3 rot = {0,0,0};

vec3 ground[64];

GLfloat speed = 0.2;

float toDeg(float r)
{
	return r*180.f/M_PI;
}
void renderShip()
{
	glRotatef(toDeg(rot.x),1,0,0);
	glRotatef(toDeg(rot.y),0,1,0);
	glRotatef(toDeg(rot.z),0,0,1);
	glTranslatef(pos.x,pos.y,pos.z);
	glBegin(GL_TRIANGLES);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.5f, 0.0f, -1.5f);
		glVertex3f(0.0f, 0.0f, 3.0f);
		
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-1.5f, 0.0f, -1.5f);
		glVertex3f(0.0f, 0.0f, 3.0f);

		glColor4f(1.0f, 2.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 2.0f, -1.0f);
		glVertex3f(0.0f, 0.0f, 3.0f);

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f(0.0f, 1.0f, -0.5f);
		glVertex3f(0.0f, 0.0f, 2.0f);
		glVertex3f(0.5f, 0.0f, -0.5f);

		glVertex3f(0.0f, 1.0f, -0.5f);
		glVertex3f(0.0f, 0.0f, 2.0f);
		glVertex3f(-0.5f, 0.0f, -0.5f);
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
	rot.z += delta*stick.x/10;
	rot.x += delta*stick.y/10;
	stick.x = stick.y = 0;
	printf("%f %f\n",toDeg(rot.z),toDeg(rot.x));
	speed += delta*stick.z;
	if(speed)//used for movement
	{
		vec3 dVec = vec3_rot(_vec3(0.f,0.f,speed*delta),rot);
		pos.x += dVec.x;
		pos.y += dVec.y;
		pos.z += dVec.z;
	}
	while(rot.x < 0) rot.x += 2.f*M_PI;
	while(rot.x >= 2.f*M_PI) rot.x -= 2.f*M_PI;
	while(rot.y < 0) rot.y += 2.f*M_PI;
	while(rot.y >= 2.f*M_PI) rot.y -= 2.f*M_PI;
	while(rot.z < 0) rot.z += 2.f*M_PI;
	while(rot.z >= 2.f*M_PI) rot.z -= 2.f*M_PI;
}
void init()
{
	srand(time(0));
	int i,j,c=0;
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			ground[8*i+j] = _vec3((4-i),(rand() % 4),(4-j));
		}
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
