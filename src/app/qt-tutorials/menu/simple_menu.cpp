

#include "simple_menu.h"

#include "QtWidgets/QMenu"
#include "QtWidgets/QMenuBar"

SimpleMenu::SimpleMenu(QWidget* parent) : QMainWindow{parent} {
  auto* quit{new QAction{"&Quit", this}};
  QMenu* file = menuBar()->addMenu("&File");
  file->addAction(quit);
  connect(quit, &QAction::triggered, qApp, QApplication::quit);
}