

#include "toolbar.h"

#include "QtGui/QIcon"
#include "QtWidgets/QAction"
#include "QtWidgets/QToolBar"

Toolbar::Toolbar(QWidget* parent) : QMainWindow{parent} {
  QPixmap newpix{"/tmp/new.png"};
  QPixmap openpix{"/tmp/open.png"};
  QPixmap quitpix{"/tmp/quit.png"};

  auto* toolbar{addToolBar("main toolbar")};
  toolbar->addAction(QIcon{newpix}, "New File");
  toolbar->addAction(QIcon(openpix), "Open File");
  toolbar->addSeparator();

  auto* quit{toolbar->addAction(QIcon{quitpix}, "Quit Application")};
  connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}