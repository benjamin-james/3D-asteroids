#ifndef MATRIX_H
#define MATRIX_H

#include "GL/gl.h" //for gldouble

typedef GLdouble mat4[16];
typedef GLdouble vec3[3];
typedef GLdouble vec4[4];

mat4 _mat4();
vec4 _vec4(GLdouble a, GLdouble b, GLdouble c, GLdouble d);
vec3 _vec3(GLdouble a, GLdouble b, GLdouble c);
mat4 mat4_clone(mat4 m);
mat4 mat4_translate(mat4 m, vec3 axis);
mat4 _mat4_translate(vec3 axis);
mat4 mat4_rotate(mat4 m, vec3 axis);
mat4 _mat4_rotate(vec3 axis);
vec3 vec3_rot(vec3 v, vec3 axis, GLdouble a);
#endif