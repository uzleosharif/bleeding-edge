

#include "another_menu.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  AnotherMenu window{};
  window.resize(350, 250);
  window.setWindowTitle("Another Menu");
  window.show();

  return app.exec();
}