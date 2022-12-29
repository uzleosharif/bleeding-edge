

#include "QtCore/QTextStream"

#define STR_EQUAL 0

auto main() -> int {
  QTextStream out{stdout};

  QString a{"Rain"};
  QString b{"rain"};
  QString c{"rain\n"};

  if (QString::compare(a, b) == STR_EQUAL) {
    out << "a,b are equal"
        << "\n";
  } else {
    out << "a,b are not equal"
        << "\n";
  }

  out << "in case insensitive comparison:"
      << "\n";
  if (QString::compare(a, b, Qt::CaseInsensitive) == STR_EQUAL) {
    out << "a,b are equal"
        << "\n";
  } else {
    out << "a,b are not equal"
        << "\n";
  }

  if (QString::compare(b, c) == STR_EQUAL) {
    out << "b,c are equal"
        << "\n";
  } else {
    out << "b,c are not equal"
        << "\n";
  }

  c.chop(1);
  if (QString::compare(b, c) == STR_EQUAL) {
    out << "b,c are equal"
        << "\n";
  } else {
    out << "b,c are not equal"
        << "\n";
  }

  auto d{c};
  d.chop(2);
  out << d << "\n";
}