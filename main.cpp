#include <chrono>
#include <iostream>

#include "vec3.hpp"

int main() {
  Vec3 ret;
  const auto start_time = std::chrono::system_clock::now();
  for (unsigned int i = 0; i < 1e9; ++i) {
    ret = ret + Vec3(0, 1, 2) + Vec3(3, 4, 5);
  }
  const auto end_time = std::chrono::system_clock::now();
  std::cout << ret << std::endl;
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                     start_time)
                   .count()
            << std::endl;

  return 0;
}