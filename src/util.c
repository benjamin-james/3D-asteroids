#include "stdlib.h"
#include "stdio.h"
#include "signal.h"
#include "math.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "entity.h"
#include "util.h"
#include "array.h"

void showFatalError(char *msg)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Fatal Error!",msg,NULL);
	SDL_Quit();
	exit(-1);
}
void sighandler(int signum)
{
	char str[30];
	switch(signum)
	{
		case SIGINT:	sprintf(str,"Interrupted"); break;
		case SIGSEGV:	sprintf(str,"Segmentation fault"); break;
		case SIGFPE:	sprintf(str,"One does not simply divide by 0"); break;
		default:	sprintf(str,"Unknown signal %d",signum);
	}
	showFatalError(str);
}
void showWarning(char *msg)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING,"Warning!",msg,NULL);
}/*
inline float toDeg(float r)
{
	return (float)(r*180.f/M_PI);
}
inline float toRad(float r)
{
	return (float)(r*M_PI/180.f);
}*/
GLuint loadBMP(char *filename)
{
	GLuint texture;
	SDL_Surface *img = SDL_LoadBMP(filename);
	if(!img) return 0;
	if((img->w & (img->w - 1)) || (img->h & (img->h - 1)))
	{
		showWarning("Not a valid bmp file");
	}
	GLenum format = GL_RGBA;//when in doubt
	GLint bpp = img->format->BytesPerPixel;
	if(bpp == 4)
	{
		if(img->format->Rmask == 0xFF) format = GL_RGBA;
		else format = GL_BGRA;
	}
	else if(bpp == 3)
	{
		if(img->format->Rmask == 0xFF) format = GL_RGB;
		else format = GL_BGR; 
	}
	glGenTextures(1,&texture);
	glBindTexture(GL_TEXTURE_2D,texture);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D,0,bpp,img->w,img->h,0,format,GL_UNSIGNED_BYTE,img->pixels);
	if(img) SDL_FreeSurface(img);
	return texture;
}
char *loadFile(char *filename)
{
	if(!filename) return NULL;
	FILE *f = fopen(filename,"r");
	fseek(f,0,SEEK_END);
	long size = ftell(f);
	rewind(f);
	char *str = malloc(size);
	fread(str,sizeof(char),size,f);
	fclose(f);
	str[size-1] = 0;//make sure it is null-terminated
	return str;
}
entity loadObj(char *filename)
{
	FILE *f = fopen(filename,"r");
	if(!f) showFatalError("Could not open file");
	size_t len = 0;
	char *line = NULL;
	entity e = entity_create();
	array *faces = array_create(4);
	array *vertices = array_create(4);
	//array *normals = array_create(1);
	while(getline(&line,&len,f) != -1)	//read file line by line
	{
		if(line[0] == '#') continue; //a comment
		char *tok = strtok(line," ");
		if(!strcmp(tok,"v"))	//a plain vertex
		{
			vec3 *v = malloc(sizeof(vec3));
			sscanf(line,"v %f %f %f",&v->x,&v->y,&v->z);
			array_append(vertices,v);
		}
		else if(!strcmp(tok,"vn")) //a vertex normal
		{
			/*vec3 *v = malloc(sizeof(vec3));
			sscanf(line,"vn %f %f %f",v->x,v->y,v->z);
			array_append(normals,v);*/
		}
		else if(!strcmp(tok,"f"))	//a face
		{
			array *face = array_create(3);
			while((tok = strtok(NULL," ")) != NULL)
			{
				int index = atoi(tok) - 1; 			//obj is 1-indexed
				array_append(face,array_get(vertices,index)); 	//add the vertex described by the index
			}
			array_append(faces,face);
		}
	}
	fclose(f);
	if(line) free(line);
	e->index = glGenLists(1);	//generates unique id for this list, is used to render the mesh
	glNewList(e->index,GL_COMPILE);	//compiles a new list
	while(faces->size > 0)
	{
		array *face = array_remove(faces,faces->size-1);
		if(face->size == 4)
		{
			glBegin(GL_QUADS);
			{
				glColor4f(0.8f,0.8f,0.8f,1.f);
				vec3 *v;
				v = array_get(face,0);
				glVertex3f(v->x,v->y,v->z);
				v = array_get(face,1);
				glVertex3f(v->x,v->y,v->z);
				v = array_get(face,2);
				glVertex3f(v->x,v->y,v->z);
				v = array_get(face,3);
				glVertex3f(v->x,v->y,v->z);
			}
			glEnd();
		}
		else if(face->size == 3)
		{
			glBegin(GL_TRIANGLES);
			{
				glColor4f(0.8f,0.8f,0.8f,1.f);
				vec3 *v;
				v = array_get(face,0);
				glVertex3f(v->x,v->y,v->z);
				v = array_get(face,1);
				glVertex3f(v->x,v->y,v->z);
				v = array_get(face,2);
				glVertex3f(v->x,v->y,v->z);
			}
			glEnd();
		}
		array_destroy(face);
	}
	while(vertices->size > 0) free(array_remove(vertices,vertices->size-1));
	array_destroy(vertices);
	array_destroy(faces);
	glEndList();
	return e;
}
