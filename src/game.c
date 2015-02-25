#include "time.h"
#include "stdlib.h"
#include "math.h"
#include "game.h"
#include "matrix.h"
#include "SDL2/SDL_opengl.h"

vec3 stick = {0,0,0}; //joystick x y is look, z is acceleration
			//i.e. the camera

vec3 pos = {0,0,-5};	//ship position
vec3 rot = {0,0,0};	//ship rotation

vec3 ground[64];	//mesh for ground: not implemented yet

GLfloat speed = 0.2;	//speed multiplier

//Function which converts radians to degrees
float toDeg(float r)
{
	return r*180.f/M_PI;
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
//Main rendering function
//Should call other rendering functions, one for each "object"
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
void update(double delta)
{
	rot.z += delta*stick.x/10;	//sets roll with horizontal mouse movement
	rot.x += delta*stick.y/10;	//sets pitch with vertical mouse movement
	stick.x = stick.y = 0;		//resets stick: very strong friction apparently
	#ifdef DEBUG 
		printf("%f %f\n",toDeg(rot.z),toDeg(rot.x));	//debug
	#endif
	speed += delta*stick.z;		//sets speed
	if(speed)//used for movement
	{
		vec3 dVec = vec3_rot(_vec3(0.f,0.f,speed*delta),rot);	//gets velocity vector, rotates direction {0,0,speed} in rotation rot
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
void init()	
{
	srand(time(0));
	int i,j;
	//initializes ground randomly
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			ground[8*i+j] = _vec3((4-i),(rand() % 4),(4-j));
		}
	}
}
void setAcceleration(double d) //sets "acceleration" by changing what the speed will change by each update()
{
	stick.z = d;
}
void joystick(double x, double y) //range of [-1,1] for x and y, this changes the ship's direction
{
	
	stick.x = x;
	stick.y = y;
	//stick.x = atan2(y,x); //polar
	//stick.y = hypot(x,y);
}
