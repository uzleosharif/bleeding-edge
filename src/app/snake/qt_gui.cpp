

#include "qt_gui.h"

#include <iostream>
#include <stdexcept>

#include "QtGui/QResizeEvent"
#include "QtWidgets/QApplication"
#include "QtWidgets/QGraphicsEllipseItem"

snake::QtGui::QtGui(QWidget* parent) : QMainWindow{parent} {
  resize(kBoardLength * 1.1, kBoardWidth * 1.1);
  setWindowTitle("Snake");
  show();

  fruit_->setBrush(kFruitColor);
  snake_->setPen(QPen{kSnakeColor, kScale});
  text_->setPos(kBoardLength / 2 - 50, kBoardWidth / 2);

  scene_->setSceneRect(0, 0, kBoardLength, kBoardWidth);
  scene_->addItem(text_.get());

  view_->setBackgroundBrush(kBoardBackgroundColor);
  view_->setScene(scene_.get());
  setCentralWidget(view_.get());

  timer_.setInterval(kSpeed);
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

  QObject::connect(&timer_, &QTimer::timeout, [this]() {
    game_time_ += (kSpeed / 1000.0);

    if (game_time_ >= kWelcomeScreenWait) {
      if (!snake_started_) {
        scene_->clear();
        scene_->setSceneRect(0, 0, kBoardLength, kBoardWidth);
        scene_->addItem(walls_.get());
        scene_->addItem(fruit_.get());
        scene_->addItem(snake_.get());

        snake_started_ = true;
      } else {
        engine_->advance();
        render();

        if (engine_->isGameOver()) {
          QApplication::quit();
        }
      }
    }
  });

  timer_.start();
}

auto snake::QtGui::render() -> void {
  // show game start on window
  auto [fruit_pos_x, fruit_pos_y] = engine_->getFruitPos();
  fruit_->setX(fruit_pos_x);
  fruit_->setY(fruit_pos_y);

  auto [snake_tail, snake_head] = engine_->getSnakePos();
  snake_->setLine(snake_tail.first, snake_tail.second, snake_head.first, snake_head.second);
}

auto snake::QtGui::keyPressEvent(QKeyEvent* event) -> void {
  if (event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_W) {
    QApplication::quit();
  }
}