

#include "QtCore/QTextStream"

auto main() -> int {
  QTextStream out{stdout};
  QString a{"love"};
  a.append(" chess");
  a.prepend("I ");

  out << a << "\n";

  out << "The a string has " << a.count() << " characters"
      << "\n";

  out << a.toUpper() << "\n";
  out << a.toLower() << "\n";
}
