

#pragma once

#include <utility>
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

  auto init(int board_rows = 100, int board_cols = 100) -> void;
  auto advance() -> void;
  auto getFruitPos() const -> pos_t;
  auto getSnakePos() const -> const std::vector<pos_t*>&;
  auto isGameOver() const -> bool;

 private:
  auto hitSnake(pos_t pos) const -> bool;

  int board_rows_{100};
  int board_cols_{100};
  pos_t fruit_{};
  std::vector<std::pair<pos_t, Direction>> snake_{};
  std::vector<pos_t*> snake_out_{};
  bool game_over_{false};
};

}  // namespace snake