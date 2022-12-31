

#include "qt_gui.h"

#include <stdexcept>

#include "QtGui/QResizeEvent"
#include "QtWidgets/QGraphicsEllipseItem"

snake::QtGui::QtGui(QWidget* parent) : QMainWindow{parent} {
  // we initialize all members here in constructor as the map with unique_ptr can't be done so with
  // initialier_list because it requires copyable types (a unique_ptr is only moveable)
  view_ = std::make_unique<QGraphicsView>();

  scene_ = std::make_unique<QGraphicsScene>();

  walls_.insert({"left", std::make_unique<QGraphicsRectItem>(0, 0, kWallThickness, kBoardWidth)});
  walls_.insert({"right", std::make_unique<QGraphicsRectItem>(kBoardLength, 0, kWallThickness, kBoardWidth)});
  walls_.insert({"up", std::make_unique<QGraphicsRectItem>(0, 0, kBoardLength, kWallThickness)});
  walls_.insert({"down", std::make_unique<QGraphicsRectItem>(0, kBoardWidth, kBoardLength, kWallThickness)});

  fruit_ = std::make_unique<QGraphicsEllipseItem>(kBoardLength / 2, kBoardWidth / 2, kScale, kScale);
  fruit_->setBrush(kFruitColor);

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
  auto fruit_pos{engine_->getFruitPos()};
  fruit_->setX(fruit_pos.first);
  fruit_->setY(fruit_pos.second);
  scene_->addItem(fruit_.get());

  // // keep on running until game over or quit
  // // if no input then advance snake after delay
  // while (1) {
  // }
}