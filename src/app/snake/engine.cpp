

#include "engine.h"

auto SnakeEngine::init() -> void {
  // snake consist of 3 blocks. It is placed in center and moving to right on board
  // fruit is randomly placed somewhere on board
}

auto SnakeEngine::setBoardLength(int length) -> void { board_x_ = length; }

auto SnakeEngine::setBoardWidth(int width) -> void { board_y_ = width; }