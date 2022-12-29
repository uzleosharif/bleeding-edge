

#pragma once

#include "QtWidgets/QApplication"
#include "QtWidgets/QMainWindow"

class Checkable : public QMainWindow {
  Q_OBJECT

 public:
  Checkable(QWidget* parent = nullptr);

 private slots:
  void toggleStatusbar();

 private:
  QAction* viewst{};
};