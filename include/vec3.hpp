#ifndef _VEC3_H
#define _VEC3_H
#include <array>
#include <iostream>

class Vec3 {
 public:
  float v[3];

  constexpr Vec3() : v{0, 0, 0} {}
  constexpr Vec3(float _x) : v{_x, _x, _x} {}
  constexpr Vec3(float _x, float _y, float _z) : v{_x, _y, _z} {}

  constexpr float x() const { return v[0]; }
  constexpr float y() const { return v[1]; }
  constexpr float z() const { return v[2]; }
};

inline constexpr Vec3 operator+(const Vec3& v1, const Vec3& v2) {
  return Vec3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}
inline constexpr Vec3 operator+(const Vec3& v1, float k) {
  return Vec3(v1.x() + k, v1.y() + k, v1.z() + k);
}
inline constexpr Vec3 operator+(float k, const Vec3& v2) {
  return Vec3(k + v2.x(), k + v2.y(), k + v2.z());
}

inline constexpr Vec3 operator-(const Vec3& v1, const Vec3& v2) {
  return Vec3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}
inline constexpr Vec3 operator-(const Vec3& v1, float k) {
  return Vec3(v1.x() - k, v1.y() - k, v1.z() - k);
}
inline constexpr Vec3 operator-(float k, const Vec3& v2) {
  return Vec3(k - v2.x(), k - v2.y(), k - v2.z());
}

inline constexpr float dot(const Vec3& v1, const Vec3& v2) {
  return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}
inline constexpr Vec3 cross(const Vec3& v1, const Vec3& v2) {
  return Vec3(v1.y() * v2.z() - v1.z() * v2.y(),
              v1.z() * v2.x() - v1.x() * v2.z(),
              v1.x() * v2.y() - v1.y() * v2.x());
}

inline std::ostream& operator<<(std::ostream& stream, const Vec3& v) {
  stream << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
  return stream;
}

#endif