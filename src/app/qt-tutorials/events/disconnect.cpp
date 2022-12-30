
#include "disconnect.h"

#include "QtCore/QTextStream"
#include "QtWidgets/QCheckBox"
#include "QtWidgets/QHBoxLayout"

Disconnect::Disconnect(QWidget* parent) : QWidget{parent} {
  QHBoxLayout* hbox{new QHBoxLayout{this}};
  hbox->setSpacing(5);

  clickBtn = new QPushButton{"Click", this};
  hbox->addWidget(clickBtn, 0, Qt::AlignLeft | Qt::AlignTop);

  QCheckBox* cb{new QCheckBox{"Connect", this}};
  cb->setCheckState(Qt::Checked);
  hbox->addWidget(cb, 0, Qt::AlignLeft | Qt::AlignTop);

  connect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);
  connect(cb, &QCheckBox::stateChanged, this, &Disconnect::onCheck);
}

auto Disconnect::onClick() -> void {
  QTextStream out{stdout};
  out << "Button clicked\n";
}

auto Disconnect::onCheck(int state) -> void {
  if (state == Qt::Checked) {
    connect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);
  } else {
    disconnect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);
  }
}