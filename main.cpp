#include <chrono>
#include <iostream>

#include "vec3-expression.hpp"
#include "vec3.hpp"

int main() {
  Vec3 ret;
  Vec3 v1(0, 1, 2);
  Vec3 v2(3, 4, 5);
  Vec3 v3(3, 4, 5);
  Vec3 v4(3, 4, 5);
  auto start_time = std::chrono::system_clock::now();
  for (unsigned int i = 0; i < 1e7; ++i) {
    ret = v1 + v2 + v3 + v4;
  }
  auto end_time = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                     start_time)
                   .count()
            << std::endl;
  std::cout << ret << std::endl;

  Vec3E ret2;
  Vec3E v1e(0, 1, 2);
  Vec3E v2e(3, 4, 5);
  Vec3E v3e(3, 4, 5);
  Vec3E v4e(3, 4, 5);
  start_time = std::chrono::system_clock::now();
  for (unsigned int i = 0; i < 1e7; ++i) {
    ret2 = v1e + v2e + v3e + v4e;
  }
  end_time = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                     start_time)
                   .count()
            << std::endl;
  std::cout << ret2 << std::endl;

  return 0;
}