
#include "move.h"

#include "QtGui/QMoveEvent"

Move::Move(QWidget* parent) : QWidget{parent} {}

auto Move::moveEvent(QMoveEvent* e) -> void {
  int x{e->pos().x()};
  int y{e->pos().y()};

  QString text{QString::number(x) + "," + QString::number(y)};

  setWindowTitle(text);
}