

#include "another_menu.h"

#include "QtWidgets/QMenu"
#include "QtWidgets/QMenuBar"

AnotherMenu::AnotherMenu(QWidget* parent) : QMainWindow{parent} {
  QPixmap newpix{"/tmp/new.png"};
  QPixmap openpix{"/tmp/open.png"};
  QPixmap quitpix{"/tmp/quit.png"};

  auto* newa{new QAction{newpix, "&New", this}};
  auto* open{new QAction{openpix, "&Open", this}};
  auto* quit{new QAction{quitpix, "&Quit", this}};
  quit->setShortcut(tr("CTRL+Q"));

  auto* file{menuBar()->addMenu("&File")};
  file->addAction(newa);
  file->addAction(open);
  file->addSeparator();
  file->addAction(quit);

  qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

  connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}