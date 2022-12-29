

#include "QtWidgets/QApplication"
#include "vertical_box.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  VerticalBox window{};
  window.resize(240, 230);
  window.setWindowTitle("VerticalBox");
  window.show();

  return app.exec();
}