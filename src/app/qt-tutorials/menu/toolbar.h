

#pragma once

#include "QtWidgets/QApplication"
#include "QtWidgets/QMainWindow"

class Toolbar : public QMainWindow {
  Q_OBJECT

 public:
  Toolbar(QWidget* parent = nullptr);
};
