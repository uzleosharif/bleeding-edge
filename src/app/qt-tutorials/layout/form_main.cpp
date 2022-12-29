

#include "QtWidgets/QApplication"
#include "form.h"

auto main(int argc, char** argv) -> int {
  QApplication app(argc, argv);

  FormEx window{};
  window.setWindowTitle("Form example");
  window.show();

  return app.exec();
}