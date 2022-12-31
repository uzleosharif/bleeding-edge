

#include "engine.h"

#include <algorithm>
#include <iostream>

#include "utils.h"

auto snake::Engine::init(int board_rows, int board_cols) -> void {
  board_rows_ = board_rows;
  board_cols_ = board_cols;

  // snake (3 blocks) pointing to right in the middle of board
  snake_ = {{board_cols_ / 2 - 10, board_rows_ / 2}, {board_cols_ / 2 + 10, board_rows_ / 2}};

  snake_direction_ = Direction::RIGHT;

  // fruit random
  while (1) {
    fruit_ = {utils::getRandomInt(0, board_cols_), utils::getRandomInt(0, board_rows_)};
    // TODO: fruit shouldn't overlap with snake
    break;
  }
}

auto snake::Engine::getFruitPos() const -> pos_t { return fruit_; }

auto snake::Engine::getSnakePos() const -> std::pair<pos_t, pos_t> { return snake_; }

auto snake::Engine::getSnakeDirection() const -> Direction { return snake_direction_; }

auto snake::Engine::advance() -> void {
  auto& tail{snake_.first};
  auto& head{snake_.second};

  head.first++;
  tail.first++;
}