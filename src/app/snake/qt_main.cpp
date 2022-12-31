

#include "QtWidgets/QApplication"
#include "qt_gui.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  // engine to use
  snake::Engine engine{};

  // Qt gui to use
  snake::QtGui gui{};
  gui.setEngine(&engine);

  // start game
  gui.run();

  return app.exec();
}