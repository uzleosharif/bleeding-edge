
#include "QtWidgets/QApplication"
#include "move.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  Move window{};
  window.resize(250, 150);
  window.setWindowTitle("Move");
  window.show();

  return app.exec();
}