

// design:
// the `processInput()` takes an input integer key representing the user input, which can be mapped to specific actions
// in the game. The `render()` takes a reference to a buffer and fills it with the game state, which can then be
// displayed by the GUI layer

// to use the game engine, you would create an instance of the `SnakeEngine` class and call the `run()` function to
// start the game loop. User -> GUI -> Engine

#pragma once

class SnakeEngine {
 public:
  SnakeEngine() = default;
  virtual ~SnakeEngine() = default;
  SnakeEngine(const SnakeEngine&) = default;
  SnakeEngine(SnakeEngine&&) = default;
  SnakeEngine& operator=(const SnakeEngine&) = default;
  SnakeEngine& operator=(SnakeEngine&&) = default;

  auto init() -> void;
  auto setBoardLength(int length) -> void;
  auto setBoardWidth(int width) -> void;

 private:
  int board_x_{30};
  int board_y_{30};
};