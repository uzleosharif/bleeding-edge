

#include "QtCore/QTextStream"

auto main() -> int {
  QTextStream out{stdout};

  QString str1 = "The night train";
  out << str1 << "\n";

  QString str2{"An old falcon"};
  out << str2 << "\n";

  using std::string_literals::operator""s;
  auto s{"A blue sky"s};
  QString str3{s.c_str()};
  out << str3 << "\n";

  auto ss{"A deep forest"};
  QString str4{ss};
  out << str4 << "\n";
}