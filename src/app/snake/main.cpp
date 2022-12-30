

#include "gui.h"

auto main() -> int {
  snake::Engine engine{};
  snake::Gui gui{};
  gui.setEngine(&engine);
  gui.run();
}