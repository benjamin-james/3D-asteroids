#ifndef MATRIX_H
#define MATRIX_H

#include "GL/gl.h" //for GLfloat

typedef GLfloat mat4[16];
typedef struct
{
  GLfloat x,y,z;
} vec3;

/*mat4 _mat4();
vec4 _vec4(GLfloat a, GLfloat b, GLfloat c, GLfloat d);*/
vec3 _vec3(GLfloat a, GLfloat b, GLfloat c);
/*mat4 mat4_clone(mat4 m);
mat4 mat4_translate(mat4 m, vec3 pos);
mat4 _mat4_translate(vec3 pos);
mat4 mat4_rotate(mat4 m, vec3 rot);
mat4 _mat4_rotate(vec3 rot);*/
vec3 vec3_rot(vec3 pos, vec3 rot);
#endif
