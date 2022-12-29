

#include "checkable.h"

#include "QtWidgets/QMenu"
#include "QtWidgets/QMenuBar"
#include "QtWidgets/QStatusBar"

Checkable::Checkable(QWidget* parent) : QMainWindow{parent} {
  viewst = new QAction{"&View statusbar", this};
  viewst->setCheckable(true);
  viewst->setChecked(true);

  auto* file{menuBar()->addMenu("&File")};
  file->addAction(viewst);

  statusBar();

  connect(viewst, &QAction::triggered, this, &Checkable::toggleStatusbar);
}

auto Checkable::toggleStatusbar() -> void {
  if (viewst->isChecked()) {
    statusBar()->show();
  } else {
    statusBar()->hide();
  }
}