

#include "engine.h"

#include <algorithm>

auto SnakeEngine::init(int board_rows, int board_cols) -> void {
  board_.resize(board_rows * board_cols);
  std::ranges::for_each(board_, [](BlockType& b) { b = BlockType::EMPTY; });

  // snake (3 blocks) pointing to right in the middle of board
  snake_direction_ = Direction::RIGHT;
  for (int i = board_.size() - 1; i < board_.size() + 2; ++i) {
    board_[i] = BlockType::SNAKE;
  }

  // fruit random
}
