
#include "CoherenceIndicatorWidget.hpp"

#include <QColor>
#include <QDebug>
#include <QPainter>

CoherenceIndicatorWidget::CoherenceIndicatorWidget(QWidget* parent)
  : QFrame{parent}, level{CoherenceLevel::Low} {}

void CoherenceIndicatorWidget::set_level(CoherenceLevel level) {
  qDebug() << "set level" << static_cast<int>(level);
  this->level = level;
  this->update();
}

CoherenceLevel CoherenceIndicatorWidget::get_level() {
  return this->level;
}

void CoherenceIndicatorWidget::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.setRenderHints(QPainter::Antialiasing);

  QRect cr = this->rect();

  // inset cr by 1 px
  cr.adjust(1, 1, -1, -1);

  // calculate rect of 3 circles with 4px spacing
  QRect r1 = cr;
  r1.setWidth(r1.width() / 3 - 4);
  r1.setHeight(r1.width());
  QRect r2 = r1;
  r2.translate(r1.width() + 4, 0);
  QRect r3 = r2;
  r3.translate(r2.width() + 4, 0);

  if (this->isEnabled() && this->level == CoherenceLevel::Low) {
    painter.setBrush(Qt::red);
  } else {
    painter.setBrush(Qt::darkRed);
  }
  painter.drawEllipse(r1);

  if (this->isEnabled() && this->level == CoherenceLevel::Medium) {
    painter.setBrush(Qt::yellow);
  } else {
    painter.setBrush(Qt::darkYellow);
  }
  painter.drawEllipse(r2);

  if (this->isEnabled() && this->level == CoherenceLevel::High) {
    painter.setBrush(Qt::green);
  } else {
    painter.setBrush(Qt::darkGreen);
  }
  painter.drawEllipse(r3);
}
