#ifndef MATRIX_H
#define MATRIX_H

#define M4(a,b) (a + (b<<2))
typedef struct
{
  float m[16];
} mat4;
typedef struct
{
  float x,y,z;
} vec3;

mat4 _mat4();
mat4 mat4_multiply(mat4 m1, mat4 m2);
vec3 _vec3(float a, float b, float c);
mat4 mat4_clone(mat4 m);
mat4 mat4_translate(mat4 m, vec3 pos);
mat4 mat4_rotate(mat4 m, vec3 rot);
vec3 vec3_rot(vec3 pos, vec3 rot);
vec3 rotz(vec3 v, float a);
vec3 roty(vec3 v, float a);
vec3 rotx(vec3 v, float a);
#endif
