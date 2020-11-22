#ifndef _VEC3_H
#define _VEC3_H
#include <array>

class Vec3 {
 public:
  std::array<float, 3> v;

  Vec3();
  Vec3(float _x);
  Vec3(float _x, float _y, float _z);
};

#endif