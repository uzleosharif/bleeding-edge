

#pragma once

#include <vector>

namespace snake {

class Engine {
  using pos_t = std::pair<int, int>;
  enum class Direction { UP, DOWN, RIGHT, LEFT };

 public:
  Engine() = default;
  virtual ~Engine() = default;
  Engine(const Engine&) = default;
  Engine(Engine&&) = default;
  Engine& operator=(const Engine&) = default;
  Engine& operator=(Engine&&) = default;

  auto init(int board_rows = 10, int board_cols = 10) -> void;
  auto getFruitPos() const -> pos_t;

 private:
  Direction snake_direction_{Direction::RIGHT};
  int board_rows_{30};
  int board_cols_{30};
  std::vector<pos_t> snake_{};
  pos_t fruit_{};
};

}