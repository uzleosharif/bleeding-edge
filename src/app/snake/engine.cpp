

#include "engine.h"

#include <algorithm>
// TODO: later remove
#include <iostream>

#include "utils.h"

auto snake::Engine::init(int board_rows, int board_cols) -> void {
  board_rows_ = board_rows;
  board_cols_ = board_cols;

  snake_.clear();
  snake_.reserve(board_rows_ * board_cols_);
  snake_out_.clear();
  snake_out_.reserve(board_rows_ * board_cols_);

  for (int i = 0; i < 20; ++i) {
    snake_.emplace_back(std::make_pair(std::make_pair((board_cols_ / 2) - 10 + i, board_rows_ / 2), Direction::RIGHT));
    snake_out_.emplace_back(&(snake_.back().first));
  }

  // fruit random
  while (1) {
    fruit_ = {utils::getRandomInt(2, board_cols_ - 2), utils::getRandomInt(2, board_rows_ - 2)};

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

auto snake::Engine::getSnakePos() const -> const std::vector<const pos_t*>& { return snake_out_; }

auto snake::Engine::advance() -> void {
  auto moveBlock{[](pos_t& pos, Direction dir) {
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
        y--;
        break;
      }
      case Direction::DOWN: {
        y++;
        break;
      }
      default: {
        throw std::runtime_error{"Unexpected direction found for a snake block"};
      }
    }
  }};

  for (auto it{snake_.begin()}; it != snake_.end(); ++it) {
    auto& [pos, dir] = *it;
    moveBlock(pos, dir);

    if ((it + 1) != snake_.end()) {
      dir = (it + 1)->second;
    }
  }

  auto& head{snake_.back().first};

  // game over check
  // checkGameOver();
  if (head.first >= board_cols_ || head.first < 0 || head.second >= board_rows_ || head.second < 0) {
    game_over_ = true;
  }

  // expand on eating fruit
  if (head == fruit_) {
    std::cout << "eating fruit\n";

    // for (auto& [pos, dir] : snake_) {
    //   moveBlock(pos, dir);
    // }

    // snake_.emplace_back(std::make_pair(fruit_, snake_.back().second));
  }
}

auto snake::Engine::isGameOver() const -> bool { return game_over_; }

auto snake::Engine::moveUp() -> void {
  auto& dir{snake_.back().second};
  if (dir == Direction::RIGHT || dir == Direction::LEFT) {
    dir = Direction::UP;
  }
}

auto snake::Engine::moveDown() -> void {
  auto& dir{snake_.back().second};
  if (dir == Direction::RIGHT || dir == Direction::LEFT) {
    dir = Direction::DOWN;
  }
}

auto snake::Engine::moveLeft() -> void {
  auto& dir{snake_.back().second};
  if (dir == Direction::UP || dir == Direction::DOWN) {
    dir = Direction::LEFT;
  }
}

auto snake::Engine::moveRight() -> void {
  auto& dir{snake_.back().second};
  if (dir == Direction::UP || dir == Direction::DOWN) {
    dir = Direction::RIGHT;
  }
}