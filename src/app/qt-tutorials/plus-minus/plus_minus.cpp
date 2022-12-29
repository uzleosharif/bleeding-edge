

#include "plus_minus.h"

#include "QtWidgets/QGridLayout"

PlusMinus::PlusMinus(QWidget* parent) : QWidget{parent} {
  auto* plsBtn{new QPushButton{"+", this}};
  auto* minBtn{new QPushButton{"-", this}};
  lbl = new QLabel{"0", this};

  auto* grid{new QGridLayout{this}};
  grid->addWidget(plsBtn, 0, 0);
  grid->addWidget(minBtn, 0, 1);
  grid->addWidget(lbl, 1, 1);

  setLayout(grid);

  connect(plsBtn, &QPushButton::clicked, this, &PlusMinus::OnPlus);
  connect(minBtn, &QPushButton::clicked, this, &PlusMinus::OnMinus);
}

auto PlusMinus::OnPlus() -> void {
  auto val{lbl->text().toInt()};
  val++;
  lbl->setText(QString::number(val));
}

auto PlusMinus::OnMinus() -> void {
  auto val{lbl->text().toInt()};
  val--;
  lbl->setText(QString::number(val));
}