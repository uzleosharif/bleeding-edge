

#include "skeleton.h"

#include "QtGui/QIcon"
#include "QtWidgets/QAction"
#include "QtWidgets/QMenuBar"
#include "QtWidgets/QStatusBar"
#include "QtWidgets/QTextEdit"
#include "QtWidgets/QToolBar"

Skeleton::Skeleton(QWidget* parent) : QMainWindow{parent} {
  QPixmap newpix{"/tmp/new.png"};
  QPixmap openpix{"/tmp/open.png"};
  QPixmap quitpix{"/tmp/quit.png"};

  auto* quit{new QAction{"&Quit", this}};

  auto* file{menuBar()->addMenu("&File")};
  file->addAction(quit);
  connect(quit, &QAction::triggered, qApp, &QApplication::quit);

  auto* toolbar{addToolBar("main toolbar")};
  toolbar->addAction(QIcon{newpix}, "New File");
  toolbar->addAction(QIcon{openpix}, "Open File");
  toolbar->addSeparator();

  auto* quit2{toolbar->addAction(QIcon{quitpix}, "Quit Application")};
  connect(quit2, &QAction::triggered, qApp, &QApplication::quit);

  auto* edit{new QTextEdit{this}};
  setCentralWidget(edit);

  statusBar()->showMessage("Ready");
}