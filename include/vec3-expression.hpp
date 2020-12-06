#ifndef _VEC3_EXPRESSION_H
#define _VEC3_EXPRESSION_H
#include <array>
#include <iostream>

// forward declaration
template <typename L, typename Op, typename R>
class Expression;

class Vec3E {
 public:
  std::array<float, 3> v;

  constexpr Vec3E() : v({0, 0, 0}) {}
  constexpr Vec3E(float _x) : v({_x, _x, _x}) {}
  constexpr Vec3E(float _x, float _y, float _z) : v({_x, _y, _z}) {}

  constexpr float x() const { return v[0]; }
  constexpr float y() const { return v[1]; }
  constexpr float z() const { return v[2]; }
  constexpr float operator[](std::size_t i) const { return v[i]; }

  template <typename... Args>
  constexpr Vec3E& operator=(const Expression<Args...>& e) {
    for (unsigned int i = 0; i < 3; ++i) {
      v[i] = e[i];
    }
    return *this;
  }
};

template <typename L, typename Op, typename R>
class Expression {
 private:
  const L& l;
  const R& r;

 public:
  constexpr Expression(const L& _l, const R& _r) : l(_l), r(_r) {}

  constexpr float operator[](std::size_t i) const {
    return Op::apply(l[i], r[i]);
  }

  // for dot(Expression, Expression)
  constexpr operator Vec3E() const {
    return Vec3E((*this)[0], (*this)[1], (*this)[2]);
  }
};

struct Plus {
  static constexpr float apply(float lhs, float rhs) { return lhs + rhs; }
};
struct Minus {
  static constexpr float apply(float lhs, float rhs) { return lhs - rhs; }
};

inline std::ostream& operator<<(std::ostream& stream, const Vec3E& v) {
  stream << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
  return stream;
}

template <typename L, typename R>
inline constexpr Expression<L, Plus, R> operator+(const L& lhs, const R& rhs) {
  return Expression<L, Plus, R>(lhs, rhs);
}
template <typename L, typename R>
inline constexpr Expression<L, Minus, R> operator-(const L& lhs, const R& rhs) {
  return Expression<L, Minus, R>(lhs, rhs);
}

inline constexpr float dot(const Vec3E& v1, const Vec3E& v2) {
  return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}
inline constexpr Vec3E cross(const Vec3E& v1, const Vec3E& v2) {
  return Vec3E(v1.y() * v2.z() - v1.z() * v2.y(),
               v1.z() * v2.x() - v1.x() * v2.z(),
               v1.x() * v2.y() - v1.y() * v2.x());
}

#endif