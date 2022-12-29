

#include "QtCore/QTextStream"

auto main() -> int {
  QTextStream out{stdout};
  QString a{"Eagle"};

  out << a[0] << "\n";
  out << a[4] << "\n";
  out << a.at(2) << "\n";

  // if (a.at(5).isNull()) {
  //   out << "outside the range of the string\n";
  // }

  out << a.length() << "\n";
  out << a.count() << "\n";

  QString str{"there are many stars."};
  for (auto qc : str) {
    out << qc << " ";
  }
  out << "\n";
  for (auto it{str.begin()}; it != str.end(); ++it) {
    out << *it << " ";
  }
  out << "\n";
  for (int i = 0; i < str.size(); ++i) {
    out << str.at(i) << " ";
  }
  out << Qt::endl;
}