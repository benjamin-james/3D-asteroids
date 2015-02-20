#include "matrix.h"
#include "GL/gl.h"

vec3 rotx(vec3 v, GLfloat a)
{
  return _vec3(v.x,v.y*cos(a) - v.z*sin(a),v.y*sin(a) + v.z*cos(a));
}
vec3 roty(vec3 v, GLfloat a)
{
  return _vec3(v.x*cos(a)+v.z*sin(a),v.y,-v.x*sin(a)+v.z*cos(a));
}
vec3 rotz(vec3 v, GLfloat a)
{
  return _vec3(v.x*cos(a) - v.y*sin(a),v.x*sin(a)+v.y*cos(a),v.z);
}
vec3 vec3_rot(vec3 pos, vec3 rot)
{
  return _vec3( 
                pos.x*rotz(roty(rotx(_vec3(1.f,0.f,0.f),rot.x),rot.y),rot.y),
                pos.y*rotz(roty(rotx(_vec3(0.f,1.f,0.f),rot.x),rot.y),rot.y),
                pos.z*rotz(roty(rotx(_vec3(0.f,0.f,1.f),rot.x),rot.y),rot.y)
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
mat4 _mat4()
{
  mat4 r = {1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1};
  return r;
}
vec4 _vec4(GLfloat a, GLfloat b, GLfloat c, GLfloat d)
{
  vec4 v = {a,b,c,d};
  return v;
}*/
vec3 _vec3(GLfloat a, GLfloat b, GLfloat c)
{
  vec3 v = {a,b,c};
  return v;
}/*
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
mat4 _mat4_translate(vec3 axis)
{
  return mat4_translate(_mat4(),axis);
}
mat4 mat4_rotate(mat4 m, vec3 axis)
{
  return _mat4();//TODO: do this
}
mat4 _mat4_rotate(vec3 axis)
{
  return mat4_rotate(_mat4(),axis);
}*/
