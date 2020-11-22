#ifndef _VEC3_H
#define _VEC3_H
#include <array>
#include <iostream>

class Vec3 {
 public:
  std::array<float, 3> v;

  constexpr Vec3() : v({0, 0, 0}) {}
  constexpr Vec3(float _x) : v({_x, _x, _x}) {}
  constexpr Vec3(float _x, float _y, float _z) : v({_x, _y, _z}) {}

  constexpr float x() const { return v[0]; }
  constexpr float y() const { return v[1]; }
  constexpr float z() const { return v[2]; }
};

std::ostream& operator<<(std::ostream& stream, const Vec3& v) {
  stream << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
  return stream;
}

#endif