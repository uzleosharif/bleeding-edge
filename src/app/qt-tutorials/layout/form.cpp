

#include "form.h"

#include "QtWidgets/QFormLayout"
#include "QtWidgets/QLabel"
#include "QtWidgets/QLineEdit"

FormEx::FormEx(QWidget* parent) : QWidget{parent} {
  auto* nameEdit{new QLineEdit{this}};
  auto* addrEdit{new QLineEdit{this}};
  auto* occpEdit{new QLineEdit{this}};

  auto* formLayout{new QFormLayout};
  formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
  formLayout->addRow("Name:", nameEdit);
  formLayout->addRow("Email:", addrEdit);
  formLayout->addRow("Age:", occpEdit);

  setLayout(formLayout);
}