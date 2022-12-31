

// my first attempt at gui programming so there is lot of room for improvement (graphics, performance)

#pragma once

#include <map>

#include "QtWidgets/QGraphicsRectItem"
#include "QtWidgets/QGraphicsScene"
#include "QtWidgets/QGraphicsView"
#include "QtWidgets/QMainWindow"
#include "engine.h"

namespace snake {

class QtGui : public QMainWindow {
  // parameters for board
  // TODO: expose these to users?
  static constexpr int kBoardLength{500};
  static constexpr int kBoardWidth{500};
  static constexpr int kWallThickness{5};
  static constexpr auto kBoardBackgroundColor{Qt::black};
  static constexpr auto kWallColor{Qt::red};
  static constexpr auto kFruitColor{Qt::green};
  static constexpr auto kSnakeColor{Qt::blue};
  static constexpr int kScale{10};

 public:
  // constructor
  QtGui(QWidget* parent = nullptr);
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
  std::unique_ptr<QGraphicsView> view_{nullptr};
  std::unique_ptr<QGraphicsScene> scene_{nullptr};
  std::map<std::string, std::unique_ptr<QGraphicsRectItem>> walls_{};
  std::unique_ptr<QGraphicsEllipseItem> fruit_{};
};

}  // namespace snake