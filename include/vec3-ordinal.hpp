#ifndef _VEC3_ORDINAL_H
#define _VEC3_ORDINAL_H
#include <array>
#include <iostream>

class Vec3O {
 public:
  std::array<float, 3> v;

  constexpr Vec3O() : v({0, 0, 0}) {}
  constexpr Vec3O(float _x) : v({_x, _x, _x}) {}
  constexpr Vec3O(float _x, float _y, float _z) : v({_x, _y, _z}) {}

  constexpr float x() const { return v[0]; }
  constexpr float y() const { return v[1]; }
  constexpr float z() const { return v[2]; }
};

inline constexpr Vec3O operator+(const Vec3O& v1, const Vec3O& v2) {
  return Vec3O(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}
inline constexpr Vec3O operator+(const Vec3O& v1, float k) {
  return Vec3O(v1.x() + k, v1.y() + k, v1.z() + k);
}
inline constexpr Vec3O operator+(float k, const Vec3O& v2) {
  return Vec3O(k + v2.x(), k + v2.y(), k + v2.z());
}

inline constexpr Vec3O operator-(const Vec3O& v1, const Vec3O& v2) {
  return Vec3O(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}
inline constexpr Vec3O operator-(const Vec3O& v1, float k) {
  return Vec3O(v1.x() - k, v1.y() - k, v1.z() - k);
}
inline constexpr Vec3O operator-(float k, const Vec3O& v2) {
  return Vec3O(k - v2.x(), k - v2.y(), k - v2.z());
}

inline constexpr float dot(const Vec3O& v1, const Vec3O& v2) {
  return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}
inline constexpr Vec3O cross(const Vec3O& v1, const Vec3O& v2) {
  return Vec3O(v1.y() * v2.z() - v1.z() * v2.y(),
               v1.z() * v2.x() - v1.x() * v2.z(),
               v1.x() * v2.y() - v1.y() * v2.x());
}

inline std::ostream& operator<<(std::ostream& stream, const Vec3O& v) {
  stream << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
  return stream;
}

#endif