#include "matrix.h"
#include "math.h"
//#include "GL/gl.h"

vec3 rotx(vec3 v, float a)
{
  return _vec3(v.x,v.y*cos(a) - v.z*sin(a),v.y*sin(a) + v.z*cos(a));
}
vec3 roty(vec3 v, float a)
{
  return _vec3(v.x*cos(a)+v.z*sin(a),v.y,-v.x*sin(a)+v.z*cos(a));
}
vec3 rotz(vec3 v, float a)
{
  return _vec3(v.x*cos(a) - v.y*sin(a),v.x*sin(a)+v.y*cos(a),v.z);
}
vec3 vec3_rot(vec3 pos, vec3 rot)
{
  vec3 x = rotz(roty(rotx(_vec3(1.f,0.f,0.f),rot.x),rot.y),rot.y);
  vec3 y = rotz(roty(rotx(_vec3(0.f,1.f,0.f),rot.x),rot.y),rot.y);
  vec3 z = rotz(roty(rotx(_vec3(0.f,0.f,1.f),rot.x),rot.y),rot.y);
  return _vec3( 
                pos.x*x.x + pos.y*y.x + pos.z*z.x,
                pos.x*x.y + pos.y*y.y + pos.z*z.y,
                pos.x*x.z + pos.y*y.z + pos.z*z.z
              );
}/*
inline void m_set(mat4 m, int x, int y, GLfloat value)
{
  m[x*4+y] = value;
}
inline GLfloat m_get(mat4 m, int x, int y)
{
  return m[x*4+y];
}
*/
mat4 _mat4()
{
  mat4 r = {{1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1}};
  return r;
}/*
vec4 _vec4(GLfloat a, GLfloat b, GLfloat c, GLfloat d)
{
  vec4 v = {a,b,c,d};
  return v;
}*/
vec3 _vec3(float a, float b, float c)
{
  vec3 v = {a,b,c};
  return v;
}
mat4 mat4_clone(mat4 m)
{
  int i;
  mat4 r;
  for(i = 0; i < 16; i++)
  {
    r[i] = m[i];
  }
  return r;
}
mat4 mat4_translate(mat4 m, vec3 axis)
{
  return _mat4();//TODO: do this
}
mat4 mat4_rotate(mat4 m, vec3 axis)
{
  return _mat4();//TODO: do this
}
mat4 mat4_multiply(mat4 m1, mat4 m2)
{
  mat4 m = _mat4();
  m[M4(0,0)] = m1[M4(0,0)] * m2[M4(0,0)] + m1[M4(0,1)] * m2[M4(1,0)] + m1[M4(0,2)] * m2[M4(2,0)] + m1[M4(0,3)] * m2[M4(3,0)];
  *(dest+O(0,1)) = (*(src1+O(0,0)) * *(src2+O(0,1))) + (*(src1+O(0,1)) * *(src2+O(1,1))) + (*(src1+O(0,2)) * *(src2+O(2,1))) + (*(src1+O(0,3)) * *(src2+O(3,1)));	
  *(dest+O(0,2)) = (*(src1+O(0,0)) * *(src2+O(0,2))) + (*(src1+O(0,1)) * *(src2+O(1,2))) + (*(src1+O(0,2)) * *(src2+O(2,2))) + (*(src1+O(0,3)) * *(src2+O(3,2)));	
  *(dest+O(0,3)) = (*(src1+O(0,0)) * *(src2+O(0,3))) + (*(src1+O(0,1)) * *(src2+O(1,3))) + (*(src1+O(0,2)) * *(src2+O(2,3))) + (*(src1+O(0,3)) * *(src2+O(3,3)));	
  *(dest+O(1,0)) = (*(src1+O(1,0)) * *(src2+O(0,0))) + (*(src1+O(1,1)) * *(src2+O(1,0))) + (*(src1+O(1,2)) * *(src2+O(2,0))) + (*(src1+O(1,3)) * *(src2+O(3,0)));	
  *(dest+O(1,1)) = (*(src1+O(1,0)) * *(src2+O(0,1))) + (*(src1+O(1,1)) * *(src2+O(1,1))) + (*(src1+O(1,2)) * *(src2+O(2,1))) + (*(src1+O(1,3)) * *(src2+O(3,1)));	
  *(dest+O(1,2)) = (*(src1+O(1,0)) * *(src2+O(0,2))) + (*(src1+O(1,1)) * *(src2+O(1,2))) + (*(src1+O(1,2)) * *(src2+O(2,2))) + (*(src1+O(1,3)) * *(src2+O(3,2)));	
  *(dest+O(1,3)) = (*(src1+O(1,0)) * *(src2+O(0,3))) + (*(src1+O(1,1)) * *(src2+O(1,3))) + (*(src1+O(1,2)) * *(src2+O(2,3))) + (*(src1+O(1,3)) * *(src2+O(3,3)));	
  *(dest+O(2,0)) = (*(src1+O(2,0)) * *(src2+O(0,0))) + (*(src1+O(2,1)) * *(src2+O(1,0))) + (*(src1+O(2,2)) * *(src2+O(2,0))) + (*(src1+O(2,3)) * *(src2+O(3,0)));	
  *(dest+O(2,1)) = (*(src1+O(2,0)) * *(src2+O(0,1))) + (*(src1+O(2,1)) * *(src2+O(1,1))) + (*(src1+O(2,2)) * *(src2+O(2,1))) + (*(src1+O(2,3)) * *(src2+O(3,1)));	
  *(dest+O(2,2)) = (*(src1+O(2,0)) * *(src2+O(0,2))) + (*(src1+O(2,1)) * *(src2+O(1,2))) + (*(src1+O(2,2)) * *(src2+O(2,2))) + (*(src1+O(2,3)) * *(src2+O(3,2)));	
  *(dest+O(2,3)) = (*(src1+O(2,0)) * *(src2+O(0,3))) + (*(src1+O(2,1)) * *(src2+O(1,3))) + (*(src1+O(2,2)) * *(src2+O(2,3))) + (*(src1+O(2,3)) * *(src2+O(3,3)));	
  *(dest+O(3,0)) = (*(src1+O(3,0)) * *(src2+O(0,0))) + (*(src1+O(3,1)) * *(src2+O(1,0))) + (*(src1+O(3,2)) * *(src2+O(2,0))) + (*(src1+O(3,3)) * *(src2+O(3,0)));	
  *(dest+O(3,1)) = (*(src1+O(3,0)) * *(src2+O(0,1))) + (*(src1+O(3,1)) * *(src2+O(1,1))) + (*(src1+O(3,2)) * *(src2+O(2,1))) + (*(src1+O(3,3)) * *(src2+O(3,1)));	
  *(dest+O(3,2)) = (*(src1+O(3,0)) * *(src2+O(0,2))) + (*(src1+O(3,1)) * *(src2+O(1,2))) + (*(src1+O(3,2)) * *(src2+O(2,2))) + (*(src1+O(3,3)) * *(src2+O(3,2)));	
  *(dest+O(3,3)) = (*(src1+O(3,0)) * *(src2+O(0,3))) + (*(src1+O(3,1)) * *(src2+O(1,3))) + (*(src1+O(3,2)) * *(src2+O(2,3))) + (*(src1+O(3,3)) * *(src2+O(3,3)));
}
