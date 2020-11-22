#ifndef _VEC3_H
#define _VEC3_H
#include <array>

class Vec3 {
 public:
  std::array<float, 3> v;

  constexpr Vec3() : v({0, 0, 0}) {}
  constexpr Vec3(float _x) : v({_x, _x, _x}) {}
  constexpr Vec3(float _x, float _y, float _z) : v({_x, _y, _z}) {}
};

#endif