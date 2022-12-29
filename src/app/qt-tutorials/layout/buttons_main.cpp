

#include "QtWidgets/QApplication"
#include "buttons.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  Buttons window{};
  window.resize(290, 170);
  window.setWindowTitle("Buttons");
  window.show();

  return app.exec();
}