

#pragma once

#include <map>

#include "QtWidgets/QGraphicsRectItem"
#include "QtWidgets/QGraphicsScene"
#include "QtWidgets/QGraphicsView"
#include "QtWidgets/QMainWindow"
#include "engine.h"

namespace snake {

class QtGui {
  // parameters for board
  static constexpr int kBoardLength{500};
  static constexpr int kBoardWidth{500};
  static constexpr int kWallThickness{5};
  static constexpr auto kBoardBackgroundColor{Qt::black};
  static constexpr auto kWallColor{Qt::red};

  class Board final : public QMainWindow {
   public:
    Board(QWidget* parent = nullptr);

   private:
    std::unique_ptr<QGraphicsView> view_{nullptr};
    std::unique_ptr<QGraphicsScene> scene_{nullptr};
    std::map<std::string, std::unique_ptr<QGraphicsRectItem>> walls_{};
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