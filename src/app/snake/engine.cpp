

#include "engine.h"

#include <algorithm>
#include <iostream>

#include "utils.h"

auto snake::Engine::init(int board_rows, int board_cols) -> void {
  snake_.reserve(100);

  board_rows_ = board_rows;
  board_cols_ = board_cols;

  // snake (3 blocks) pointing to right in the middle of board
  snake_[0] = {-1, 0};
  snake_[1] = {0, 0};
  snake_[2] = {1, 0};

  snake_direction_ = Direction::RIGHT;

  // fruit random
  while (1) {
    fruit_ = {utils::getRandomInt(0, board_cols), utils::getRandomInt(0, board_rows)};
    if (std::ranges::find(snake_, fruit_) == snake_.end()) {
      break;
    }
  }
}

auto snake::Engine::getFruitPos() const -> pos_t { return fruit_; }

auto snake::Engine::getSnakePos() const -> const std::vector<pos_t>& { return snake_; }

auto snake::Engine::getSnakeDirection() const -> Direction { return snake_direction_; }