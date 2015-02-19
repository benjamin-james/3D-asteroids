#ifndef MATRIX_H
#define MATRIX_H

#include "GL/gl.h" //for gldouble

typedef GLdouble mat4[16];
typedef GLdouble vec3[3];
typedef GLdouble vec4[4];

mat4 _mat4(vec4 a, vec4 b, vec4 c, vec4 d);
vec4 _vec4(GLdouble a, GLdouble b, GLdouble c, GLdouble d);
vec3 _vec3(GLdouble a, GLdouble b, GLdouble c);
mat4 mat4_identity();
mat4 mat4_clone(mat4 m);
mat4 mat4_translate(mat4 m, vec3 axis);
mat4 mat4_rotate(mat4 m, vec3 axis);

#endif
