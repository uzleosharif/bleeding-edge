

#include "engine.h"

#include <algorithm>
#include <iostream>

#include "utils.h"

auto snake::Engine::init(int board_rows, int board_cols) -> void {
  board_rows_ = board_rows;
  board_cols_ = board_cols;

  snake_.clear();
  snake_.reserve(board_rows_ * board_cols_ * 0.5);

  // snake_ = {{board_cols_ / 2 - 10, board_rows_ / 2}, {board_cols_ / 2 + 10, board_rows_ / 2}};
  for (int i = 0; i < 20; ++i) {
    snake_[i] = {{(board_cols_ / 2) - 10 + i, board_rows_ / 2}, Direction::RIGHT};
  }

  // fruit random
  while (1) {
    fruit_ = {utils::getRandomInt(0, board_cols_), utils::getRandomInt(0, board_rows_)};

    if (!hitSnake(fruit_)) {
      break;
    }
  }
}

auto snake::Engine::hitSnake(pos_t pos) const -> bool {
  // auto& tail{snake_.first};
  // auto& head{snake_.second};

  // pos_t x_range{std::min(tail.first, head.first), std::max(tail.first, head.first)};
  // pos_t y_range{std::min(tail.second, head.second), std::max(tail.second, head.second)};

  // if (pos.first >= x_range.first && pos.first <= x_range.second && pos.second >= y_range.first &&
  //     pos.second <= y_range.second) {
  //   return true;
  // }

  return false;
}

auto snake::Engine::getFruitPos() const -> pos_t { return fruit_; }

auto snake::Engine::getSnake() const -> const std::vector<std::pair<pos_t, Direction>>& { return snake_; }

auto snake::Engine::advance() -> void {
  // auto& tail{snake_.first};
  // auto& head{snake_.second};

  // auto move{[](pos_t& blk, Direction dir) {
  //   switch (dir) {
  //     case Direction::RIGHT: {
  //       blk.first++;
  //       break;
  //     }
  //     case Direction::LEFT: {
  //       blk.first--;
  //       break;
  //     }
  //     case Direction::UP: {
  //       blk.second++;
  //       break;
  //     }
  //     case Direction::DOWN: {
  //       blk.second--;
  //       break;
  //     }
  //   }
  // }};

  // move(head, head_direction_);
  // move(tail, tail_direction_);

  // for (auto& [pos, dir] : snake_) {
  for (auto it{snake_.begin()}; it != snake_.end(); ++it) {
    auto& [pos, dir] = *it;
    auto& [x, y] = pos;

    switch (dir) {
      case Direction::RIGHT: {
        x++;
        break;
      }
      case Direction::LEFT: {
        x--;
        break;
      }
      case Direction::UP: {
        y++;
        break;
      }
      case Direction::DOWN: {
        y--;
        break;
      }
      default: {
        // TODO: throw proper exception here (runtime exception??)
        std::terminate();
      }
    }

    if (it + 1 != snake_.end()) {
      dir = (it + 1)->second;
    }
  }

  auto& head{snake_.back().first};
  if (head.first >= board_cols_ || head.first < 0 || head.second >= board_rows_ || head.second < 0) {
    game_over_ = true;
  }
}

auto snake::Engine::isGameOver() const -> bool { return game_over_; }