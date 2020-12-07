#include <chrono>

#include "rng.hpp"
#include "vec3-expression.hpp"
#include "vec3-simd.hpp"
#include "vec3.hpp"

template <typename VecX>
bool vecAdd(const VecX& v1, const VecX& v2) {
  const VecX v3 = v1 + v2;
  const VecX v4 = v1 + v2 + v3;
  const VecX v5 = v1 + v2 + v3 + v4;
  const VecX v6 = v1 + v2 + v3 + v4 + v5;
  const VecX v7 = v1 + v2 + v3 + v4 + v5 + v6;
  return dot(v7, v7) > 10.0f;
}

int main() {
  const unsigned int samples = 100000000;

  RNG rng(1);

  unsigned int count = 0;
  auto start_time = std::chrono::system_clock::now();
  for (unsigned int i = 0; i < samples; ++i) {
    count += vecAdd(Vec3(rng.getNext(), rng.getNext(), rng.getNext()),
                    Vec3(rng.getNext(), rng.getNext(), rng.getNext()));
  }
  auto end_time = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                     start_time)
                   .count()
            << std::endl;
  std::cout << count << std::endl;

  count = 0;
  start_time = std::chrono::system_clock::now();
  for (unsigned int i = 0; i < samples; ++i) {
    count += vecAdd(Vec3E(rng.getNext(), rng.getNext(), rng.getNext()),
                    Vec3E(rng.getNext(), rng.getNext(), rng.getNext()));
  }
  end_time = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                     start_time)
                   .count()
            << std::endl;
  std::cout << count << std::endl;

  count = 0;
  start_time = std::chrono::system_clock::now();
  for (unsigned int i = 0; i < samples; ++i) {
    count += vecAdd(Vec3S(rng.getNext(), rng.getNext(), rng.getNext()),
                    Vec3S(rng.getNext(), rng.getNext(), rng.getNext()));
  }
  end_time = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                     start_time)
                   .count()
            << std::endl;
  std::cout << count << std::endl;

  return 0;
}