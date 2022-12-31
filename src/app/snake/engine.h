

#pragma once

#include <utility>

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
  auto advance() -> void;
  auto getFruitPos() const -> pos_t;
  auto getSnakePos() const -> std::pair<pos_t, pos_t>;
  auto isGameOver() const -> bool;

 private:
  auto hitSnake(pos_t pos) const -> bool;

  Direction head_direction_{Direction::RIGHT};
  Direction tail_direction_{Direction::RIGHT};
  int board_rows_{30};
  int board_cols_{30};
  pos_t fruit_{};
  // (head, tail)
  std::pair<pos_t, pos_t> snake_{};
  bool game_over_{false};
};

}