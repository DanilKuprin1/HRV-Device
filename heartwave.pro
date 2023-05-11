QT += \
  core \
  gui \
  widgets \
  charts

CONFIG += \
  c++17

SOURCES += \
  src/data/BatterySensor.cpp \
  src/data/PulseSensor.cpp \
  src/MainWindow.cpp \
  src/main.cpp \
  src/Session.cpp \
  src/SessionHistory.cpp \
  src/ui/SessionListWidgetItem.cpp \
  src/ui/BatteryIndicatorWidget.cpp \
  src/ui/BreathPacerWidget.cpp \
  src/ui/CoherenceIndicatorWidget.cpp \
  src/ui/HRVGraphWidget.cpp \
  src/AppState.cpp

HEADERS += \
  src/data/BatterySensor.hpp \
  src/data/PulseSensor.hpp \
  src/MainWindow.hpp \
  src/Session.hpp \
  src/SessionHistory.hpp \
  src/ui/SessionListWidgetItem.hpp \
  src/ui/BatteryIndicatorWidget.hpp \
  src/ui/BreathPacerWidget.hpp \
  src/ui/CoherenceIndicatorWidget.hpp \
  src/ui/HRVGraphWidget.hpp \
  src/AppState.hpp

FORMS += \
  src/MainWindow.ui

RESOURCES += \
  res/data.qrc \
  res/icons.qrc
