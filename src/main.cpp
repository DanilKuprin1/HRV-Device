#include "MainWindow.hpp"

#include <QApplication>
#include <QGuiApplication>

auto main(int argc, char* argv[]) -> int {
  QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  auto app = QApplication{argc, argv};
  auto window = MainWindow{};

  window.show();

  return QApplication::exec();
}
