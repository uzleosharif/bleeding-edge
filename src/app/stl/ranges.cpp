

#include <iostream>
#include <ranges>
#include <vector>

// ranges : iterable sequences
// views : lightweight objects which are manipulated by ranges
// range adaptors : take a range and produce a view (produce lazily evaluated views)

auto main() -> int {
  const auto ints = {0, 1, 2, 3, 4, 5};
  auto even = [](int i) { return 0 == i % 2; };
  auto square = [](int i) { return i * i; };

  // "pipe" syntax of composing the views:
  for (int i : ints | std::views::filter(even) | std::views::transform(square)) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}