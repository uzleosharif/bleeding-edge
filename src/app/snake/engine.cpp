

#include "engine.h"

#include <algorithm>

#include "utils.h"

auto snake::Engine::init(int board_rows, int board_cols, int snake_blocks) -> void {
  board_rows_ = board_rows;
  board_cols_ = board_cols;

  snake_.clear();
  snake_.reserve(board_rows_ * board_cols_);
  snake_out_.clear();
  snake_out_.reserve(board_rows_ * board_cols_);

  growSnake(snake_blocks);
  for (int i = 0; i < snake_blocks; ++i) {
    auto& blk{snake_[i].first};
    blk.first = (board_cols_ / 2) - 10 + i;
    blk.second = board_rows_ / 2;
  }

  placeFruit();
}

auto snake::Engine::placeFruit() -> void {
  while (1) {
    fruit_ = {utils::getRandomInt(2, board_cols_ - 2), utils::getRandomInt(2, board_rows_ - 2)};
    if (!hitSnake(fruit_)) {
      break;
    }
  }
}

auto snake::Engine::growSnake(int blocks) -> void {
  for (int i = 0; i < blocks; ++i) {
    snake_.emplace_back(std::make_pair(std::make_pair(0, 0), Direction::RIGHT));
    snake_out_.emplace_back(&(snake_.back().first));
  }
}

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

auto snake::Engine::hitSnake(pos_t pos) const -> bool {
  return std::find_if(snake_out_.begin(), snake_out_.end() - 1, [&pos](const auto* p) { return (pos == *p); }) !=
         (snake_out_.end() - 1);
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
  if (hitSnake(head) || head.first >= board_cols_ || head.first < 0 || head.second >= board_rows_ || head.second < 0) {
    game_over_ = true;
  }

  // expand on eating fruit
  if (head == fruit_) {
    auto curr_dir{snake_.back().second};
    growSnake();
    snake_.back().first = fruit_;
    snake_.back().second = curr_dir;
    moveBlock(snake_.back().first, snake_.back().second);

    placeFruit();
    fruits_eaten_++;
  }
}

auto snake::Engine::isGameOver() const -> bool { return game_over_; }

auto snake::Engine::getCurrentScore() const -> int { return fruits_eaten_; }
