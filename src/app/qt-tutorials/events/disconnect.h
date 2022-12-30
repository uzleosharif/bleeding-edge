

#pragma once

#include "QtWidgets/QPushButton"
#include "QtWidgets/QWidget"

class Disconnect : public QWidget {
  Q_OBJECT

 public:
  Disconnect(QWidget* parent = nullptr);

 private slots:
  auto onClick() -> void;
  auto onCheck(int) -> void;

 private:
  QPushButton* clickBtn{nullptr};
};