#include "stdlib.h"
#include "SDL2/SDL_opengl.h"

#include "entity.h"
#include "matrix.h"

entity entity_create()
{
  entity e = malloc(sizeof(entity_t));
  e->pos = _vec3(0,0,0);
  e->rot = _vec3(0,0,0);
  e->lin = _vec3(0,0,0);
  e->ang = _vec3(0,0,0);
  e->index = 0;
  return e;
}
void entity_destroy(entity e)
{
  if(!e) return;
  if(e->index) glDeleteLists(e->index,1);
  free(e);
}
void entity_render(entity e)
{
	if(!e) return;
	glCallList(e->index);
}
void entity_update(entity e, float delta)
{
	if(!e) return;
	e->rot.x += e->ang.x*delta;
	e->rot.y += e->ang.y*delta;
	e->rot.z += e->ang.z*delta;
	vec3 dVec = vec3_rot(e->lin,e->rot);
	e->pos.x += dVec.x*delta;
	e->pos.y += dVec.y*delta;
	e->pos.z += dVec.z*delta;
}
