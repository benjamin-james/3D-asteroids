#ifndef ENTITY_H
#define ENTITY_H

#include "matrix.h"
#include "SDL/SDL_opengl.h"

typedef struct
{
  vec3 pos,rot,vel;
  GLuint index;
} *entity, entity_t;

entity entity_create();
void entity_destroy(entity e);

void useView(entity e);
void render(entity e);

#endif
