

#include "gui.h"

#include <stdexcept>

auto Gui::setEngine(SnakeEngine* engine) -> void {
  if (engine_ != nullptr) {
    throw std::runtime_error{"Attempted to replace already set snake engine"};
  }

  engine_ = engine;
}

auto Gui::run() -> void {
  if (engine_ == nullptr) {
    throw std::runtime_error{"Request to run the game with invalid engine"};
  }

  // initialize the game state
  engine_->init();

  // show game start on window

  // keep on running until game over or quit
  // if no input then advance snake after delay
  while (1) {
  }
}