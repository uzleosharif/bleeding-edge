

#include "QtWidgets/QApplication"
#include "QtWidgets/QWidget"

auto main(int argc, char** argv) -> int {
  QApplication app(argc, argv);

  QWidget window{};
  window.resize(250, 150);
  window.setWindowTitle("simple example");
  window.show();

  return app.exec();
}