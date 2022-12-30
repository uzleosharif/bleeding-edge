

#include "engine.h"

#include <algorithm>
#include <iostream>

#include "utils.h"

auto snake::Engine::init(int board_rows, int board_cols) -> void {
  board_rows_ = board_rows;
  board_cols_ = board_cols;
  auto mid_row{board_rows / 2};
  auto mid_col{board_cols / 2};

  // snake (3 blocks) pointing to right in the middle of board
  snake_.resize(3);
  snake_[0] = {mid_row, mid_col - 1};
  snake_[1] = {mid_row, mid_col};
  snake_[2] = {mid_row, mid_col + 1};

  snake_direction_ = Direction::RIGHT;

  // fruit random
  while (1) {
    fruit_ = {utils::getRandomInt(0, board_rows - 1), utils::getRandomInt(0, board_cols - 1)};
    if (std::ranges::find(snake_, fruit_) == snake_.end()) {
      break;
    }
  }
}
