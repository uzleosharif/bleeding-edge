

#include "QtCore/QTextStream"

auto main() -> int {
  QTextStream out{stdout};

  QString str{"The night train"};
  out << str.right(5) << "\n";
  out << str.left(9) << "\n";
  out << str.mid(4, 5) << "\n";

  QString str2{"the big apple"};
  QStringRef sub(&str2, 0, 7);

  out << sub.toString() << "\n";
}