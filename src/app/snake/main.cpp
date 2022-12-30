

#include "gui.h"

auto main() -> int {
  SnakeEngine engine{};
  Gui gui{};
  gui.setEngine(&engine);
  gui.run();
}