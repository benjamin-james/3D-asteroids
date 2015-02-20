#include "matrix.h"
#include "GL/gl.h"

vec3 rotx(vec3 v, GLdouble a)
{
  return _vec(v[0],v[1]*cos(a) - v[2]*sin(a),v[1]*sin(a) + v[2]*cos(a));
}
vec3 vec3_rot(vec3 v, vec3 axis, GLdouble a)
{
  
}
inline void m_set(mat4 m, int x, int y, GLdouble value)
{
  m[x*4+y] = value;
}
inline GLdouble m_get(mat4 m, int x, int y)
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
vec4 _vec4(GLdouble a, GLdouble b, GLdouble c, GLdouble d)
{
  vec4 v = {a,b,c,d};
  return v;
}
vec3 _vec3(GLdouble a, GLdouble b, GLdouble c)
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
}