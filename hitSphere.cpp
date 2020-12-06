#include <chrono>
#include <cmath>
#include <iostream>

#include "rng.hpp"
#include "vec3-expression.hpp"
#include "vec3.hpp"

int main() {
  const unsigned int samples = 10000000;

  auto hitSphere = [](const auto& center, float radius, const auto& origin,
                      const auto& direction) {
    const float a = dot(direction, direction);
    const float b = dot(direction, origin - center);
    const float c = dot(origin - center, origin - center) - radius * radius;
    const float D = b * b - 4 * a * c;

    const float t1 = (-b - std::sqrt(D)) / (2 * a);
    const float t2 = (-b + std::sqrt(D)) / (2 * a);
    float t = t1;
    if (t < 0) {
      t = t2;
      if (t < 0) {
        return false;
      }
    }
    return true;
  };

  RNG rng(1);

  unsigned int hit_count = 0;
  auto start_time = std::chrono::system_clock::now();
  for (unsigned int i = 0; i < samples; ++i) {
    hit_count += hitSphere(Vec3(0, 0, 0), 1.0, Vec3(0, 0, -3),
                           Vec3(rng.getNext(), rng.getNext(), rng.getNext()));
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
    hit_count += hitSphere(Vec3E(0, 0, 0), 1.0, Vec3E(0, 0, -3),
                           Vec3E(rng.getNext(), rng.getNext(), rng.getNext()));
  }
  end_time = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                     start_time)
                   .count()
            << std::endl;
  std::cout << hit_count << std::endl;

  return 0;
}