

#include <iostream>

#include "QtCore/QtCore"

auto main() -> int {
  std::cout << "Qt version: " << qVersion() << std::endl;
  return 0;
}