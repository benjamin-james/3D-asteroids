#ifndef MATRIX_H
#define MATRIX_H

#define M4(a,b) (a + (b<<2))
#define M3(a,b) (a + (b*3))

typedef struct
{
  float m[16];
} mat4;
typedef struct
{
  float m[9];
} mat3;
typedef struct
{
  float x,y,z;
} vec3;

mat4 _mat4();
mat3 _mat3();
mat3 mat3_rotx(float a);
mat3 mat3_roty(float a);
mat3 mat3_rotz(float a);
vec3 mat3_mcolumn(mat3 m, vec3 column);
mat3 mat3_multiply(mat3 m1, mat3 m2);
mat3 mat3_rotate(vec3 axis);
mat3 mat3_translate(mat3 m, vec3 pos);
mat4 mat4_multiply(mat4 m1, mat4 m2);
vec3 _vec3(float a, float b, float c);
mat4 mat4_translate(mat4 m, vec3 pos);
mat4 mat4_rotate(mat4 m, vec3 rot);
vec3 vec3_rot(vec3 pos, vec3 rot);
vec3 rotz(vec3 v, float a);
vec3 roty(vec3 v, float a);
vec3 rotx(vec3 v, float a);
#endif
