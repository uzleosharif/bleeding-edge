

#include "qt_gui.h"

#include <stdexcept>

#include "QtGui/QResizeEvent"
#include "QtWidgets/QGraphicsEllipseItem"

snake::QtGui::QtGui(QWidget* parent) : QMainWindow{parent} {
  fruit_->setBrush(kFruitColor);

  scene_->setSceneRect(0, 0, kBoardLength, kBoardWidth);
  scene_->addItem(walls_.get());
  scene_->addItem(fruit_.get());

  view_->setBackgroundBrush(kBoardBackgroundColor);
  view_->setScene(scene_.get());
  setCentralWidget(view_.get());
}

auto snake::QtGui::setEngine(Engine* engine) -> void {
  if (engine_ != nullptr) {
    throw std::runtime_error{"Attempted to replace already set snake engine"};
  }

  engine_ = engine;
}

auto snake::QtGui::run() -> void {
  if (engine_ == nullptr) {
    throw std::runtime_error{"Request to run the game with invalid engine"};
  }

  // initialize the game state
  engine_->init(kBoardWidth, kBoardLength);

  resize(kBoardLength * 1.1, kBoardWidth * 1.1);
  setWindowTitle("Snake");
  show();

  // TODO: WELCOME screen

  // show game start on window
  auto [fruit_pos_x, fruit_pos_y] = engine_->getFruitPos();
  fruit_->setX(fruit_pos_x);
  fruit_->setY(fruit_pos_y);

  auto [snake_tail, snake_head] = engine_->getSnakePos();

  auto xyz{new QGraphicsLineItem{snake_tail.first, snake_tail.second, snake_head.first, snake_head.second}};
  xyz->setPen(QPen{kSnakeColor, kScale});
  scene_->addItem(xyz);

  // // keep on running until game over or quit
  // // if no input then advance snake after delay
  // while (1) {
  // }
}
