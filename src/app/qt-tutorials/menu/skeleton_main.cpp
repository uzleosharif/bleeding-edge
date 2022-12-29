

#include "skeleton.h"

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  Skeleton window{};
  window.resize(450, 350);
  window.setWindowTitle("Application Skeleton");
  window.show();

  return app.exec();
}