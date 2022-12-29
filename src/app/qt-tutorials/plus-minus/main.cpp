

#include "plus_minus.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  PlusMinus window{};
  window.resize(300, 190);
  window.setWindowTitle("Plus Minus");
  window.show();

  return app.exec();
}