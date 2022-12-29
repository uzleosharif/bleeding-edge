

#include "QtWidgets/QApplication"
#include "QtWidgets/QWidget"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  QWidget window{};
  window.resize(350, 250);
  window.setWindowTitle("Tooltip");
  window.setToolTip("QWidget");
  window.show();

  return app.exec();
}