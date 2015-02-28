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
mat3 mat3_rotx(float);
mat3 mat3_roty(float);
mat3 mat3_rotz(float);
vec3 mat3_mcolumn(mat3, vec3);
mat3 mat3_multiply(mat3, mat3);
mat3 mat3_rotate(vec3);
mat3 mat3_translate(mat3, vec3);
mat4 mat4_multiply(mat4, mat4);
vec3 _vec3(float, float, float);
mat4 mat4_translate(mat4, vec3);
mat4 mat4_rotate(mat4, vec3);
vec3 vec3_rot(vec3, vec3);
vec3 rotz(vec3, float);
vec3 roty(vec3, float);
vec3 rotx(vec3, float);
#endif
