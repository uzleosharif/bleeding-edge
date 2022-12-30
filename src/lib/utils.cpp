

#include "utils.h"

auto utils::getRandomInt(int low, int high) -> int {
  // seed the generator
  std::random_device dev{};
  // use Mersenne Twister as the generator
  std::mt19937 rng{dev()};
  // define the range
  std::uniform_int_distribution<> dist{low, high};

  return dist(rng);
}