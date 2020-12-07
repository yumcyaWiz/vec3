#ifndef _VEC3_SIMD
#define _VEC3_SIMD
#include <immintrin.h>

#include <iostream>

class Vec3S {
 public:
  __m128 v;

  Vec3S() { v = _mm_setzero_ps(); }
  Vec3S(__m128 _v) : v(_v) {}
  Vec3S(float _x) { v = _mm_set_ps1(_x); }
  Vec3S(float _x, float _y, float _z) { v = _mm_set_ps(0.0f, _z, _y, _x); }

  float x() const {
    float value[4];
    _mm_store_ps(&value[0], v);
    return value[0];
  }
  float y() const {
    float value[4];
    _mm_store_ps(&value[0], v);
    return value[1];
  }
  float z() const {
    float value[4];
    _mm_store_ps(&value[0], v);
    return value[2];
  }
};

inline Vec3S operator+(const Vec3S& v1, const Vec3S& v2) {
  return Vec3S(_mm_add_ps(v1.v, v2.v));
}

inline Vec3S operator-(const Vec3S& v1, const Vec3S& v2) {
  return Vec3S(_mm_sub_ps(v1.v, v2.v));
}

inline float dot(const Vec3S& v1, const Vec3S& v2) {
  __m128 v = _mm_mul_ps(v1.v, v2.v);
  float value[4];
  _mm_store_ps(&value[0], v);
  return value[0] + value[1] + value[2];
}

inline std::ostream& operator<<(std::ostream& stream, const Vec3S& v) {
  stream << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
  return stream;
}

#endif