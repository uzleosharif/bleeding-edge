

#include "QtWidgets/QApplication"
#include "calculator.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  Calculator window{};
  window.setWindowTitle("Calculator");
  window.show();

  return app.exec();
}