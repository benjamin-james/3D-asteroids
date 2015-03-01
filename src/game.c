#include "stdlib.h"
#include "math.h"
#include "SDL2/SDL_opengl.h"

#include "game.h"
#include "matrix.h"
#include "util.h"
#include "events.h"

vec3 pos = {0,0,-5};	//ship position
vec3 rot = {0,0,0};	//ship rotation

GLfloat speed = 0.2;	//speed multiplier
void game_init()
{
	//entity ship = loadObj("ship.obj");	//cant render it yet
}
//Moves to location and rotation of ship and renders it
void renderShip()
{
	//glRotate uses degrees
	glRotatef(toDeg(rot.x),1,0,0);
	glRotatef(toDeg(rot.y),0,1,0);
	glRotatef(toDeg(rot.z),0,0,1);
	glTranslatef(pos.x,pos.y,pos.z);
	//For now, using glBegin with triangle rendering (NOTE: this is ancient OpenGL)
	//TODO: have a mesh with these coordinates
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
//The one function to rule them all
void render()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );	//clears previous
	glPushMatrix();			//begins transformations
	glBegin(GL_QUADS);
		glColor4f(0.15f,0.9f,0.3f,1.0f);
		glVertex3f(-10.0f,-1.0f,10.0f);
		glVertex3f(-10.0f,-1.0f,-10.0f);
		glVertex3f(10.0f,-1.0f,-10.0f);
		glVertex3f(10.0f,-1.0f,10.0f);
	glEnd();
	renderShip();			//renders ship
	glPopMatrix();			//sets the changes
	
	glLoadIdentity();	//resets view
}
//Function called every frame after render(), sends the time in milliseconds since the last call to update()
void update(double delta)
{
	vec3 stick = getInput();
	rot.z += delta*stick.x/10;	//sets roll with horizontal mouse movement
	rot.x += delta*stick.y/10;	//sets pitch with vertical mouse movement
	#ifdef DEBUG 
		printf("%f %f\n",toDeg(rot.z),toDeg(rot.x));	//debug
	#endif
	speed += delta*stick.z;		//sets speed
	if(speed)//used for movement
	{
		vec3 dVec = vec3_rot(_vec3(0.f,0.f,delta*speed),rot);	//gets velocity vector, rotates direction {0,0,speed} in rotation rot
		pos.x += dVec.x;
		pos.y += dVec.y;
		pos.z += dVec.z;
	}
	//checks bounds
	while(rot.x < 0) rot.x += 2.f*M_PI;
	while(rot.x >= 2.f*M_PI) rot.x -= 2.f*M_PI;
	while(rot.y < 0) rot.y += 2.f*M_PI;
	while(rot.y >= 2.f*M_PI) rot.y -= 2.f*M_PI;
	while(rot.z < 0) rot.z += 2.f*M_PI;
	while(rot.z >= 2.f*M_PI) rot.z -= 2.f*M_PI;
}

