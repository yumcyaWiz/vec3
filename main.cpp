#include <chrono>
#include <cmath>
#include <iostream>
#include <random>

#include "vec3-expression.hpp"
#include "vec3.hpp"

int main() {
  const unsigned int samples = 10000000;

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

  std::random_device seed_gen;
  std::mt19937 rng(seed_gen());

  unsigned int hit_count = 0;
  auto start_time = std::chrono::system_clock::now();
  for (unsigned int i = 0; i < samples; ++i) {
    hit_count += test_func(Vec3(0, 0, 0), 1.0, Vec3(0, 0, -3),
                           Vec3(rng(), rng(), rng()));
  }
  auto end_time = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                     start_time)
                   .count()
            << std::endl;
  std::cout << hit_count << std::endl;

  hit_count = 0;
  start_time = std::chrono::system_clock::now();
  for (unsigned int i = 0; i < samples; ++i) {
    hit_count += test_func(Vec3E(0, 0, 0), 1.0, Vec3E(0, 0, -3),
                           Vec3E(rng(), rng(), rng()));
  }
  end_time = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                     start_time)
                   .count()
            << std::endl;
  std::cout << hit_count << std::endl;

  return 0;
}