

// my first attempt at gui programming so there is lot of room for improvement (graphics, performance)

// Usage:
// CTRL+W to quit
// IJKL for snake control

// TODO: walls not aligned properly (esp. bottom and right ones)

#pragma once

#include <map>

#include "QtCore/QTimer"
#include "QtWidgets/QGraphicsRectItem"
#include "QtWidgets/QGraphicsScene"
#include "QtWidgets/QGraphicsView"
#include "QtWidgets/QMainWindow"
#include "engine.h"

namespace snake {

class QtGui : public QMainWindow {
  // parameters for board
  // TODO: expose these to users?
  static constexpr int kBoardLength{80};
  static constexpr int kBoardWidth{80};
  static constexpr auto kBoardBackgroundColor{Qt::white};
  static constexpr auto kFruitColor{Qt::black};
  static constexpr auto kSnakeColor{Qt::black};
  static constexpr auto kWallsColor{Qt::black};
  // game updates each `kSpeed` milli-seconds
  static constexpr int kSpeed{60};
  static constexpr double kWelcomeScreenWait{3.0};
  static constexpr int kCellSize{1};
  static constexpr int kSpacingSize{2};
  static constexpr int kScale{kCellSize + kSpacingSize};
  static constexpr int kGuiBoardLength{kBoardLength * kScale};
  static constexpr int kGuiBoardWidth{kBoardWidth * kScale};
  static constexpr int kZoom{2};

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
  auto render() -> void;
  auto keyPressEvent(QKeyEvent* event) -> void override;

  Engine* engine_{nullptr};
  std::unique_ptr<QGraphicsView> view_{std::make_unique<QGraphicsView>()};
  std::unique_ptr<QGraphicsScene> scene_{std::make_unique<QGraphicsScene>()};
  std::unique_ptr<QGraphicsRectItem> walls_{std::make_unique<QGraphicsRectItem>(0, 0, kGuiBoardLength, kGuiBoardWidth)};
  std::unique_ptr<QGraphicsEllipseItem> fruit_{std::make_unique<QGraphicsEllipseItem>(0, 0, kCellSize, kCellSize)};
  // std::unique_ptr<Q
  std::vector<std::unique_ptr<QGraphicsEllipseItem>> snake_{};
  QTimer timer_{};
  std::unique_ptr<QGraphicsTextItem> text_{std::make_unique<QGraphicsTextItem>("Welcome to Snake")};
  // current time (in seconds) spent in game
  double game_time_{0.0};
  bool snake_started_{false};
  bool paused_{false};
};

}  // namespace snake