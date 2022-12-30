

#include "QtGui/QKeyEvent"
#include "QtWidgets/QApplication"
#include "QtWidgets/QWidget"

class KeyPress : public QWidget {
 public:
  KeyPress(QWidget* parent = nullptr) : QWidget{parent} {}

 protected:
  auto keyPressEvent(QKeyEvent* e) -> void {
    if (e->key() == Qt::Key_Escape) {
      qApp->quit();
    }
  }
};

auto main(int argc, char** argv) -> int {
  QApplication app{argc, argv};

  KeyPress window{};
  window.resize(250, 150);
  window.setWindowTitle("Key Press");
  window.show();

  return app.exec();
}