#include "checkable.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  Checkable window{};
  window.resize(350, 250);
  window.setWindowTitle("Checkable Menu");
  window.show();

  return app.exec();
}