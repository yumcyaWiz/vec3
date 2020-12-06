#include <chrono>
#include <cmath>
#include <iostream>

#include "vec3-expression.hpp"
#include "vec3.hpp"

int main() {
  const unsigned int samples = 1000000;

  auto test_func = [](const auto& center, float radius, const auto& origin,
                      const auto& direction) {
    const float b = dot(direction, origin - center);
    const float c = dot(origin - center, origin - center) - radius * radius;
    const float D = b * b - c;

    const float t1 = -b - std::sqrt(D);
    const float t2 = -b + std::sqrt(D);
    float t = t1;
    if (t < 0) {
      t = t2;
      if (t < 0) {
        return false;
      }
    }
    return true;
  };

  Vec3 ret;
  auto start_time = std::chrono::system_clock::now();
  int hit_count = 0;
  for (unsigned int i = 0; i < samples; ++i) {
    hit_count += test_func(Vec3(0, 0, 0), 1.0, Vec3(0, 0, -3), Vec3(0, 0, 1));
  }
  auto end_time = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                     start_time)
                   .count()
            << std::endl;
  std::cout << hit_count << std::endl;

  Vec3E ret2;
  Vec3E v1e(0, 1, 2);
  Vec3E v2e(3, 4, 5);
  Vec3E v3e(3, 4, 5);
  Vec3E v4e(3, 4, 5);
  start_time = std::chrono::system_clock::now();
  for (unsigned int i = 0; i < samples; ++i) {
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