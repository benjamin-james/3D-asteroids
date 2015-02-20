#include "matrix.h"
#include "math.h"
//#include "GL/gl.h"

vec3 rotx(vec3 v, float a)
{
  return _vec3(v.x,v.y*cosf(a) - v.z*sinf(a),v.y*sinf(a) + v.z*cosf(a));
}
vec3 roty(vec3 v, float a)
{
  return _vec3(v.x*cosf(a)+v.z*sinf(a),v.y,-v.x*sinf(a)+v.z*cosf(a));
}
vec3 rotz(vec3 v, float a)
{
  return _vec3(v.x*cosf(a) - v.y*sinf(a),v.x*sinf(a)+v.y*cosf(a),v.z);
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
}
mat4 _mat4()
{
  mat4 r = {{1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1}};
  return r;
}
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
    r.m[i] = m.m[i];
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
mat3 _mat3()
{
  mat3 r = {{ 
    1,0,0,
    0,1,0,
    0,0,1
  }};
  return r;
}
mat3 mat3_multiply(mat3 m1, mat3 m2)
{
  mat3 r = _mat3();
  int i,j,m;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      for(m=0;m<3;m++) 
      {
        r.m[M3(i,j)] += m1.m[M3(i,m)]*m2.m[M3(m,j)];
      }
    }
  }
  return r;
}
mat3 mat3_rotx(float a)
{
  mat3 r = {{
    1,0,0,
    0,cosf(a),-sinf(a),
    0,sinf(a),cosf(a)
  }};
  return r;
}
mat3 mat3_roty(float a)
{
  mat3 r = {{
    cosf(a),0,sinf(a),
    0,1,0,
    -sinf(a),0,cosf(a)
  }};  
  return r;
}
mat3 mat3_rotz(float a)
{
  mat3 r = {{
    cosf(a),-sinf(a),0,
    sinf(a),cosf(a),0,
    0,0,1
  }};
  return r;
}
mat3 mat3_rotate(vec3 axis)
{
  mat3 x,y,z;
  x = mat3_rotx(axis.x);
  y = mat3_roty(axis.y);
  z = mat3_rotz(axis.z);
  return mat3_multiply(mat3_multiply(z,y),x);
}
mat3 mat3_translate(mat3 m, vec3 pos);
mat4 mat4_multiply(mat4 m1, mat4 m2)
{
  mat4 m = _mat4();
  *(m.m+M4(0,0)) = (*(m1.m+M4(0,0)) * *(m2.m+M4(0,0))) + (*(m1.m+M4(0,1)) * *(m2.m+M4(1,0))) + (*(m1.m+M4(0,2)) * *(m2.m+M4(2,0))) + (*(m1.m+M4(0,3)) * *(m2.m+M4(3,0)));	
  *(m.m+M4(0,1)) = (*(m1.m+M4(0,0)) * *(m2.m+M4(0,1))) + (*(m1.m+M4(0,1)) * *(m2.m+M4(1,1))) + (*(m1.m+M4(0,2)) * *(m2.m+M4(2,1))) + (*(m1.m+M4(0,3)) * *(m2.m+M4(3,1)));	
  *(m.m+M4(0,2)) = (*(m1.m+M4(0,0)) * *(m2.m+M4(0,2))) + (*(m1.m+M4(0,1)) * *(m2.m+M4(1,2))) + (*(m1.m+M4(0,2)) * *(m2.m+M4(2,2))) + (*(m1.m+M4(0,3)) * *(m2.m+M4(3,2)));	
  *(m.m+M4(0,3)) = (*(m1.m+M4(0,0)) * *(m2.m+M4(0,3))) + (*(m1.m+M4(0,1)) * *(m2.m+M4(1,3))) + (*(m1.m+M4(0,2)) * *(m2.m+M4(2,3))) + (*(m1.m+M4(0,3)) * *(m2.m+M4(3,3)));	
  *(m.m+M4(1,0)) = (*(m1.m+M4(1,0)) * *(m2.m+M4(0,0))) + (*(m1.m+M4(1,1)) * *(m2.m+M4(1,0))) + (*(m1.m+M4(1,2)) * *(m2.m+M4(2,0))) + (*(m1.m+M4(1,3)) * *(m2.m+M4(3,0)));	
  *(m.m+M4(1,1)) = (*(m1.m+M4(1,0)) * *(m2.m+M4(0,1))) + (*(m1.m+M4(1,1)) * *(m2.m+M4(1,1))) + (*(m1.m+M4(1,2)) * *(m2.m+M4(2,1))) + (*(m1.m+M4(1,3)) * *(m2.m+M4(3,1)));	
  *(m.m+M4(1,2)) = (*(m1.m+M4(1,0)) * *(m2.m+M4(0,2))) + (*(m1.m+M4(1,1)) * *(m2.m+M4(1,2))) + (*(m1.m+M4(1,2)) * *(m2.m+M4(2,2))) + (*(m1.m+M4(1,3)) * *(m2.m+M4(3,2)));	
  *(m.m+M4(1,3)) = (*(m1.m+M4(1,0)) * *(m2.m+M4(0,3))) + (*(m1.m+M4(1,1)) * *(m2.m+M4(1,3))) + (*(m1.m+M4(1,2)) * *(m2.m+M4(2,3))) + (*(m1.m+M4(1,3)) * *(m2.m+M4(3,3)));	
  *(m.m+M4(2,0)) = (*(m1.m+M4(2,0)) * *(m2.m+M4(0,0))) + (*(m1.m+M4(2,1)) * *(m2.m+M4(1,0))) + (*(m1.m+M4(2,2)) * *(m2.m+M4(2,0))) + (*(m1.m+M4(2,3)) * *(m2.m+M4(3,0)));	
  *(m.m+M4(2,1)) = (*(m1.m+M4(2,0)) * *(m2.m+M4(0,1))) + (*(m1.m+M4(2,1)) * *(m2.m+M4(1,1))) + (*(m1.m+M4(2,2)) * *(m2.m+M4(2,1))) + (*(m1.m+M4(2,3)) * *(m2.m+M4(3,1)));	
  *(m.m+M4(2,2)) = (*(m1.m+M4(2,0)) * *(m2.m+M4(0,2))) + (*(m1.m+M4(2,1)) * *(m2.m+M4(1,2))) + (*(m1.m+M4(2,2)) * *(m2.m+M4(2,2))) + (*(m1.m+M4(2,3)) * *(m2.m+M4(3,2)));	
  *(m.m+M4(2,3)) = (*(m1.m+M4(2,0)) * *(m2.m+M4(0,3))) + (*(m1.m+M4(2,1)) * *(m2.m+M4(1,3))) + (*(m1.m+M4(2,2)) * *(m2.m+M4(2,3))) + (*(m1.m+M4(2,3)) * *(m2.m+M4(3,3)));	
  *(m.m+M4(3,0)) = (*(m1.m+M4(3,0)) * *(m2.m+M4(0,0))) + (*(m1.m+M4(3,1)) * *(m2.m+M4(1,0))) + (*(m1.m+M4(3,2)) * *(m2.m+M4(2,0))) + (*(m1.m+M4(3,3)) * *(m2.m+M4(3,0)));	
  *(m.m+M4(3,1)) = (*(m1.m+M4(3,0)) * *(m2.m+M4(0,1))) + (*(m1.m+M4(3,1)) * *(m2.m+M4(1,1))) + (*(m1.m+M4(3,2)) * *(m2.m+M4(2,1))) + (*(m1.m+M4(3,3)) * *(m2.m+M4(3,1)));	
  *(m.m+M4(3,2)) = (*(m1.m+M4(3,0)) * *(m2.m+M4(0,2))) + (*(m1.m+M4(3,1)) * *(m2.m+M4(1,2))) + (*(m1.m+M4(3,2)) * *(m2.m+M4(2,2))) + (*(m1.m+M4(3,3)) * *(m2.m+M4(3,2)));	
  *(m.m+M4(3,3)) = (*(m1.m+M4(3,0)) * *(m2.m+M4(0,3))) + (*(m1.m+M4(3,1)) * *(m2.m+M4(1,3))) + (*(m1.m+M4(3,2)) * *(m2.m+M4(2,3))) + (*(m1.m+M4(3,3)) * *(m2.m+M4(3,3)));
  return m;
}
