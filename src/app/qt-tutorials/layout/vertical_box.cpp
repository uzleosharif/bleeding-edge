

#include "vertical_box.h"

#include "QtWidgets/QPushButton"
#include "QtWidgets/QVBoxLayout"

VerticalBox::VerticalBox(QWidget* parent) : QWidget{parent} {
  auto* vbox{new QVBoxLayout{this}};
  vbox->setSpacing(1);

  auto* settings{new QPushButton{"Settings", this}};
  settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  vbox->addWidget(settings);

  auto* accounts{new QPushButton{"Accounts", this}};
  accounts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  vbox->addWidget(accounts);

  auto* loans{new QPushButton{"Loans", this}};
  loans->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  vbox->addWidget(loans);

  auto* cash{new QPushButton{"Cash", this}};
  cash->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  vbox->addWidget(cash);

  auto* debts{new QPushButton{"Debts", this}};
  debts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  vbox->addWidget(debts);

  setLayout(vbox);
}