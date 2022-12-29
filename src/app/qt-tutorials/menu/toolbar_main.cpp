

#include "toolbar.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  Toolbar window{};
  window.resize(350, 250);
  window.setWindowTitle("QToolBar");
  window.show();

  return app.exec();
}