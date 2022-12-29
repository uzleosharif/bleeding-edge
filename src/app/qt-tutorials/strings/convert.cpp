

#include "QtCore/QTextStream"

auto main() -> int {
  QTextStream out{stdout};
  QString s1{"12"};
  QString s2{"15"};
  QString s3{}, s4{};

  out << s1.toInt() + s2.toInt() << "\n";

  int n1{30};
  int n2{40};
  out << s3.setNum(n1) + s4.setNum(n2) << "\n";

  int digits{0};
  int letters{0};
  int spaces{0};
  int puncts{0};

  QString str{"7 white, 3 red roses."};

  for (auto s : str) {
    if (s.isDigit()) {
      digits++;
    } else if (s.isLetter()) {
      letters++;
    } else if (s.isSpace()) {
      spaces++;
    } else if (s.isPunct()) {
      puncts++;
    }
  }

  out << QString{"There are %1 characters"}.arg(str.count()) << "\n";
  out << QString{"There are %1 letters"}.arg(letters) << "\n";
  out << QString{"There are %1 digits"}.arg(digits) << "\n";
  out << QString{"There are %1 spaces"}.arg(spaces) << "\n";
  out << QString{"There are %1 punctuation characters"}.arg(puncts) << "\n";

  QString str2{"Lovely"};
  str2.append(" season");
  out << str2 << "\n";

  str2.remove(10, 3);
  out << str2 << "\n";

  str2.replace(7, 3, "girl");
  out << str2 << "\n";

  str2.clear();
  if (str2.isEmpty()) {
    out << "the string is empty"
        << "\n";
  }
}