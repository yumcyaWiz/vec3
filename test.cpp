#include <iostream>
#include <typeinfo>

#include "vec3-expression.hpp"
#include "vec3.hpp"

int main() {
  const Vec3 v = Vec3(0, 1, 2) + Vec3(3, 4, 5) + Vec3(6, 7, 8);

  const auto ve1 = Vec3E(0, 1, 2) + Vec3E(3, 4, 5);
  const Vec3E ve2(0, 0, 0);
  float ve3 = (ve1 + ve2)[0];

  std::cout << v << std::endl;
  std::cout << ve3 << std::endl;
  return 0;
}