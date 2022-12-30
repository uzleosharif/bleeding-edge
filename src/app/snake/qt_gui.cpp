

#include "qt_gui.h"

#include <stdexcept>

#include "QtWidgets/QGraphicsScene"
#include "QtWidgets/QGraphicsView"

snake::QtGui::QtGui() {}

auto snake::QtGui::setEngine(Engine* engine) -> void {
  if (engine_ != nullptr) {
    throw std::runtime_error{"Attempted to replace already set snake engine"};
  }

  engine_ = engine;
}

auto snake::QtGui::run() -> void {
  window_.resize(290, 170);
  window_.setWindowTitle("Snake");
  window_.show();

  if (engine_ == nullptr) {
    throw std::runtime_error{"Request to run the game with invalid engine"};
  }

  // initialize the game state
  engine_->init();

  // show game start on window

  // // keep on running until game over or quit
  // // if no input then advance snake after delay
  // while (1) {
  // }
}

snake::QtGui::Board::Board(QWidget* parent) : QMainWindow{parent} {
  // TODO: resource management??

  // create a `QGraphicsView` widget and set it as the central widget of the main window
  QGraphicsView* view{new QGraphicsView{}};
  setCentralWidget(view);

  // create a `QGraphicsScene` scene and set it as the scene for the view
  QGraphicsScene* scene{new QGraphicsScene{}};
  view->setScene(scene);
}