

#pragma once

#include "QtWidgets/QPushButton"
#include "QtWidgets/QWidget"

class Buttons : public QWidget {
 public:
  Buttons(QWidget* parent = nullptr);

 private:
  QPushButton* okBtn{};
  QPushButton* applyBtn{};
};