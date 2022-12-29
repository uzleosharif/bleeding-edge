

#include "simple_menu.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  SimpleMenu window{};
  window.resize(350, 250);
  window.setWindowTitle("Simple menu");
  window.show();

  return app.exec();
}