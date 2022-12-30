

#pragma once

#include <vector>

namespace snake {

class Engine {
  enum class Direction { UP, DOWN, RIGHT, LEFT };

 public:
  Engine() = default;
  virtual ~Engine() = default;
  Engine(const Engine&) = default;
  Engine(Engine&&) = default;
  Engine& operator=(const Engine&) = default;
  Engine& operator=(Engine&&) = default;

  auto init(int board_rows = 10, int board_cols = 10) -> void;

 private:
  Direction snake_direction_{Direction::RIGHT};
  int board_rows_{30};
  int board_cols_{30};
  std::vector<std::pair<int, int>> snake_{};
  std::pair<int, int> fruit_{};
};

}