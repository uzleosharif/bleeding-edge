

#include "QtWidgets/QApplication"
#include "QtWidgets/QHBoxLayout"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QWidget"

class Click : public QWidget {
 public:
  Click(QWidget* parent = nullptr) : QWidget{parent} {
    auto* hbox{new QHBoxLayout{this}};
    hbox->setSpacing(5);

    auto* quitBtn{new QPushButton{"Quit", this}};
    hbox->addWidget(quitBtn, 0, Qt::AlignLeft | Qt::AlignTop);
    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
  }
};

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  Click window{};
  window.resize(250, 150);
  window.setWindowTitle("Click");
  window.show();

  return app.exec();
}