#include "matrix.h"
#include "GL/gl.h"

vec4 _vec4(GLdouble a, GLdouble b, GLdouble c, GLdouble d);
vec3 _vec3(GLdouble a, GLdouble b, GLdouble c);
mat4 _mat4();
mat4 mat4_clone(mat4 m);
mat4 mat4_translate(mat4 m, vec3 axis);
mat4 mat4_rotate(mat4 m, vec3 axis);
