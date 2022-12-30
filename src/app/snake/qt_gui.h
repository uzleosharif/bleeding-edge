

#pragma once

#include "QtWidgets/QMainWindow"
#include "engine.h"

namespace snake {

class QtGui {
  class Board : public QMainWindow {
   public:
    Board(QWidget* parent = nullptr);
  };

 public:
  // constructor
  QtGui();
  virtual ~QtGui() = default;
  QtGui(const QtGui&) = default;
  QtGui(QtGui&&) = default;
  QtGui& operator=(const QtGui&) = default;
  QtGui& operator=(QtGui&&) = default;

  // set the underlying engine for snake logic
  // this isn't meant to be called frequently hence no issue not inlining it
  auto setEngine(Engine* engine) -> void;

  // run the game loop
  auto run() -> void;

 private:
  Engine* engine_{nullptr};
  Board window_{};
};

}  // namespace snake