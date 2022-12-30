

#include "QtWidgets/QApplication"
#include "disconnect.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  Disconnect window{};
  window.resize(250, 150);
  window.setWindowTitle("Disconnect");
  window.show();

  return app.exec();
}