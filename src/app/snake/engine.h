

#pragma once

#include <vector>

class SnakeEngine {
  enum class BlockType { SNAKE, FRUIT, EMPTY };
  enum class Direction { UP, DOWN, RIGHT, LEFT };

 public:
  SnakeEngine() = default;
  virtual ~SnakeEngine() = default;
  SnakeEngine(const SnakeEngine&) = default;
  SnakeEngine(SnakeEngine&&) = default;
  SnakeEngine& operator=(const SnakeEngine&) = default;
  SnakeEngine& operator=(SnakeEngine&&) = default;

  auto init(int board_rows = 30, int board_cols = 30) -> void;

 private:
  std::vector<BlockType> board_{};
  Direction snake_direction_{Direction::RIGHT};
};