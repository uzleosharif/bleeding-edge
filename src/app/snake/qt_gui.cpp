

#include "qt_gui.h"

#include <stdexcept>
// TODO: later remove
#include <iostream>

#include "QtGui/QResizeEvent"
#include "QtWidgets/QApplication"
#include "QtWidgets/QGraphicsEllipseItem"

snake::QtGui::QtGui(QWidget* parent) : QMainWindow{parent} {
  resize(kBoardLength * 1.1, kBoardWidth * 1.1);
  setWindowTitle("Snake");
  show();

  walls_->setPen(QPen{kWallColor, kWallThickness});

  fruit_->setBrush(kFruitColor);
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
  for (const auto& p : engine_->getSnakePos()) {
    snake_.emplace_back(std::make_unique<QGraphicsEllipseItem>(0, 0, kScale, kScale));
    snake_.back()->setPos(p->first, p->second);
  }

  // main gui loop triggered after delay interval
  connect(&timer_, &QTimer::timeout, [this]() {
    game_time_ += (kSpeed / 1000.0);

    if (game_time_ >= kWelcomeScreenWait) {
      if (!snake_started_) {
        scene_->removeItem(text_.get());
        scene_->addItem(walls_.get());
        scene_->addItem(fruit_.get());
        for (const auto& item : snake_) {
          scene_->addItem(item.get());
        }

        snake_started_ = true;
      } else {
        engine_->advance();

        if (engine_->isGameOver()) {
          scene_->removeItem(walls_.get());
          scene_->removeItem(fruit_.get());
          for (auto& item : snake_) {
            scene_->removeItem(item.get());
          }

          text_->setPlainText("Game Over");
          text_->setX(text_->x() + 10);
          scene_->addItem(text_.get());

          timer_.stop();
        } else {
          render();
        }
      }
    }
  });

  timer_.start();
}

auto snake::QtGui::render() -> void {
  // show game start on window
  auto [fruit_pos_x, fruit_pos_y] = engine_->getFruitPos();
  fruit_->setPos(fruit_pos_x, fruit_pos_y);

  const auto& snake{engine_->getSnakePos()};
  for (int i = 0; i < snake.size(); ++i) {
    snake_[i]->setPos(snake[i]->first, snake[i]->second);
  }
}

auto snake::QtGui::keyPressEvent(QKeyEvent* event) -> void {
  if (event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_W) {
    QApplication::quit();
  }

  switch (event->key()) {
    // TODO: somehow up,down,left,right not recognized
    case Qt::Key_I: {
      engine_->moveUp();
      break;
    }
    case Qt::Key_J: {
      engine_->moveLeft();
      break;
    }
    case Qt::Key_K: {
      engine_->moveDown();
      break;
    }
    case Qt::Key_L: {
      engine_->moveRight();
      break;
    }
  }
}