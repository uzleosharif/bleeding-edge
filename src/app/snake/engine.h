

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
  auto getSnakePos() const -> const std::vector<const pos_t*>&;
  auto isGameOver() const -> bool;
  auto moveUp() -> void;
  auto moveDown() -> void;
  auto moveLeft() -> void;
  auto moveRight() -> void;

 private:
  auto hitSnake(pos_t pos) const -> bool;

  int board_rows_{100};
  int board_cols_{100};
  pos_t fruit_{};
  bool game_over_{false};
  std::vector<std::pair<pos_t, Direction>> snake_{};
  // a convenience container, to hold const pointers to internal data structure objects, for better api
  // we force const pointers so internal data structure so it can't be messed up by using this
  std::vector<const pos_t*> snake_out_{};
};

}  // namespace snake