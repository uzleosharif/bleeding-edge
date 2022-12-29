

#include "QtWidgets/QApplication"
#include "nesting.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  Layouts window{};
  window.setWindowTitle("Layouts");
  window.show();

  return app.exec();
}