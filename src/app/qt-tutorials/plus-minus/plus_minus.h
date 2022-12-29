

#pragma once

#include "QtWidgets/QApplication"
#include "QtWidgets/QLabel"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QWidget"

// the `Q_OBJECT` macro must be included in classes that declare their own signals and slots.

class PlusMinus : public QWidget {
  Q_OBJECT;

 public:
  PlusMinus(QWidget* parent = nullptr);

 private slots:
  void OnPlus();
  void OnMinus();

 private:
  QLabel* lbl{};
};