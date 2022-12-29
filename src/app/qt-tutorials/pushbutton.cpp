

// display a push button on the window. By clicking on the button we close the application

#include "QtWidgets/QApplication"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QWidget"

class MyButton : public QWidget {
 public:
  MyButton(QWidget* parent = nullptr);
};

MyButton::MyButton(QWidget* parent) : QWidget{parent} {
  auto* quitBtn{new QPushButton{"Quit", this}};
  quitBtn->setGeometry(50, 40, 75, 30);
  connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  MyButton window{};
  window.resize(250, 150);
  window.setWindowTitle("QPushButton");
  window.show();

  return app.exec();
}