

#include "QtWidgets/QApplication"
#include "qt_gui.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  snake::Engine engine{};
  snake::QtGui gui{};
  gui.setEngine(&engine);
  gui.resize(600, 600);
  gui.setWindowTitle("Snake");
  gui.show();

  gui.run();

  return app.exec();
}