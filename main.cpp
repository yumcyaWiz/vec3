#include <iostream>

#include "vec3.hpp"

int main() {
  constexpr Vec3 v3 = Vec3(0, 1, 2) + Vec3(1, 2, 3);
  return 0;
}