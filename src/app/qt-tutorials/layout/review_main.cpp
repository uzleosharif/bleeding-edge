

#include "QtWidgets/QApplication"
#include "review.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  Review window{};
  window.setWindowTitle("Review");
  window.show();

  return app.exec();
}