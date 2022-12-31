

#include "qt_gui.h"

#include <stdexcept>

#include "QtGui/QResizeEvent"
#include "QtWidgets/QGraphicsEllipseItem"

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
  engine_->init(kBoardWidth, kBoardLength);

  // show game start on window

  // // keep on running until game over or quit
  // // if no input then advance snake after delay
  // while (1) {
  // }
}

snake::QtGui::Board::Board(QWidget* parent) : QMainWindow{parent} {
  // we initialize all members here in constructor as the map with unique_ptr can't be done so with
  // initialier_list because it requires copyable types (a unique_ptr is only moveable)
  view_ = std::make_unique<QGraphicsView>();
  scene_ = std::make_unique<QGraphicsScene>();
  walls_.insert({"left", std::make_unique<QGraphicsRectItem>(0, 0, kWallThickness, kBoardWidth)});
  walls_.insert({"right", std::make_unique<QGraphicsRectItem>(kBoardLength, 0, kWallThickness, kBoardWidth)});
  walls_.insert({"up", std::make_unique<QGraphicsRectItem>(0, 0, kBoardLength, kWallThickness)});
  walls_.insert({"down", std::make_unique<QGraphicsRectItem>(0, kBoardWidth, kBoardLength, kWallThickness)});

  // setting up view
  view_->setBackgroundBrush(kBoardBackgroundColor);
  view_->setScene(scene_.get());

  // setting up scene
  scene_->setSceneRect(0, 0, kBoardLength, kBoardWidth);

  std::ranges::for_each(walls_, [this](const auto& p) {
    p.second->setBrush(kWallColor);

    scene_->addItem(p.second.get());
  });

  // view is set as the central widget of main-window
  setCentralWidget(view_.get());
}