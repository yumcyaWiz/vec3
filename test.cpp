#include <iostream>
#include <typeinfo>

#include "vec3-expression.hpp"
#include "vec3-simd.hpp"
#include "vec3.hpp"

int main() {
  const Vec3 v = Vec3(0, 1, 2) + Vec3(3, 4, 5) + Vec3(6, 7, 8);

  const auto v1 = Vec3E(0, 1, 2);
  const auto v2 = Vec3E(3, 4, 5);
  const auto v3 = Vec3E(6, 7, 8);
  const Vec3E ve1 = v1 + v2 + v3;

  std::cout << v << std::endl;
  std::cout << ve1 << std::endl;
  const Vec3E v4 = Vec3E(0, 1, 2) + Vec3E(3, 4, 5) + Vec3E(6, 7, 8);
  std::cout << v4 << std::endl;

  std::cout << Vec3S(0, 1, 2) + Vec3S(3, 4, 5) << std::endl;
  return 0;
}