

#include "QtWidgets/QWidget"

class Move : public QWidget {
  Q_OBJECT

 public:
  Move(QWidget* parent = nullptr);

 protected:
  auto moveEvent(QMoveEvent* e) -> void;
};