

#include "qt_gui.h"

#include <stdexcept>

#include "QtGui/QResizeEvent"
#include "QtWidgets/QApplication"
#include "QtWidgets/QGraphicsEllipseItem"

snake::QtGui::QtGui(QWidget* parent) : QMainWindow{parent} {
  resize(kGuiBoardLength * kZoom * 1.1, kGuiBoardWidth * kZoom * 1.1);
  setWindowTitle("Snake");
  show();

  walls_->setPen(QPen{kWallsColor, kSpacingSize});

  fruit_->setBrush(kFruitColor);
  text_->setPos(kGuiBoardLength / 2 - 50, kGuiBoardWidth / 2);

  scene_->setSceneRect(0, 0, kGuiBoardLength, kGuiBoardWidth);
  scene_->addItem(text_.get());

  view_->setBackgroundBrush(kBoardBackgroundColor);
  view_->setScene(scene_.get());
  view_->setTransform(QTransform::fromScale(kZoom, kZoom));
  // view_->setFixedSize(...);
  setCentralWidget(view_.get());

  timer_.setInterval(kSpeed);
}

auto snake::QtGui::setEngine(Engine* engine) -> void {
  if (engine_ != nullptr) {
    throw std::runtime_error{"Attempted to replace already set snake engine"};
  }

  engine_ = engine;
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
    case Qt::Key_P: {
      paused_ = !paused_;
      break;
    }
  }

  render();
}

auto snake::QtGui::run() -> void {
  if (engine_ == nullptr) {
    throw std::runtime_error{"Request to run the game with invalid engine"};
  }

  // initialize the game state
  engine_->init(kBoardWidth, kBoardLength);
  for (const auto& p : engine_->getSnakePos()) {
    snake_.emplace_back(std::make_unique<QGraphicsEllipseItem>(0, 0, kCellSize, kCellSize));
    snake_.back()->setPos(p->first * kScale, p->second * kScale);
  }

  // main gui loop triggered after delay interval
  connect(&timer_, &QTimer::timeout, [this]() {
    if (paused_) {
      return;
    }

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
          game_over_wait_cnt_++;
          if (game_over_wait_cnt_ == kGameOverWait) {
            scene_->removeItem(walls_.get());
            scene_->removeItem(fruit_.get());
            for (auto& item : snake_) {
              scene_->removeItem(item.get());
            }

            text_->setPlainText("Game Over");
            text_->setX(text_->x() + 10);
            scene_->addItem(text_.get());

            timer_.stop();
          }
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
  fruit_->setPos(fruit_pos_x * kScale, fruit_pos_y * kScale);

  const auto& snake{engine_->getSnakePos()};
  if (snake.size() > snake_.size()) {
    if (snake.size() != snake_.size() + 1) {
      throw std::runtime_error{"it seems GUI lost track of engine's snake as snake grew more than expected"};
    }

    snake_.emplace_back(std::make_unique<QGraphicsEllipseItem>(0, 0, kCellSize, kCellSize));
    scene_->addItem(snake_.back().get());
  } else if (snake.size() < snake_.size()) {
    throw std::runtime_error{"it seems GUI lost track of engine's snake"};
  }

  for (int i = 0; i < snake_.size(); ++i) {
    snake_[i]->setPos(snake[i]->first * kScale, snake[i]->second * kScale);
  }
}
