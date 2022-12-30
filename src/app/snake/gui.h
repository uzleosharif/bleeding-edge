

#pragma once

#include "engine.h"

class Gui {
 public:
  // constructor
  Gui() = default;
  virtual ~Gui() = default;
  Gui(const Gui&) = default;
  Gui(Gui&&) = default;
  Gui& operator=(const Gui&) = default;
  Gui& operator=(Gui&&) = default;

  // set the underlying engine for snake logic
  // this isn't meant to be called frequently hence no issue not inlining it
  auto setEngine(SnakeEngine* engine) -> void;

  // run the game loop
  auto run() -> void;

 private:
  SnakeEngine* engine_{nullptr};
};