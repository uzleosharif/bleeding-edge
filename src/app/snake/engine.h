

// geometry:
// the engine imagines the game board to be 2D whose points accessed via (x,y) system
// (0,0) is middle of board

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
  auto getSnakePos() const -> const std::vector<pos_t>&;
  auto getSnakeDirection() const -> Direction;

 private:
  Direction snake_direction_{Direction::RIGHT};
  int board_rows_{30};
  int board_cols_{30};
  pos_t fruit_{};
  // TODO: better container type to represent snake?
  std::vector<pos_t> snake_{};
};

}