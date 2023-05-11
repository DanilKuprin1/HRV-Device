#include "HRVGraphWidget.hpp"

HRVGraphWidget::HRVGraphWidget(QWidget* parent)
  : QWidget{parent}
  , series{new QLineSeries{}}
  , window_size{60}
  , chart{new QChart{}}
  , axis_x{new QValueAxis{}}
  , axis_y{new QValueAxis{}}
  , view{new QChartView{chart, this}}
  , scroll_bar{new QScrollBar{Qt::Horizontal, this}}
  , layout{new QVBoxLayout{this}}
  , sealed{false} {
  chart->addSeries(series);
  chart->legend()->setVisible(false);

  axis_x->setTitleText("Elapsed Time (s)");
  chart->addAxis(axis_x, Qt::AlignBottom);
  axis_x->setRange(0, window_size);
  axis_x->setLabelFormat("%.0f");

  axis_y->setTitleText("Heart Rate (bpm)");
  chart->addAxis(axis_y, Qt::AlignLeft);
  axis_y->setRange(50, 90);
  axis_y->setLabelFormat("%.0f");

  series->attachAxis(axis_x);
  series->attachAxis(axis_y);

  view->setRenderHint(QPainter::Antialiasing);

  layout->addWidget(view);
  layout->addWidget(scroll_bar);

  scroll_bar->hide();

  setLayout(layout);
}

void HRVGraphWidget::clear() {
  series->clear();

  axis_x->setRange(0, window_size);
  scroll_bar->hide();

  sealed = false;
}

void HRVGraphWidget::add_point(double x, double y) {
  if (sealed) {
    return;
  }

  series->append(QPointF{x, y});

  auto x_max = series->at(series->count() - 1).x();
  auto x_min = x_max - window_size + 1;
  if (x_min < 0) {
    x_min = 0;
    x_max = window_size;
  }

  axis_x->setRange(x_min, x_max);
}

void HRVGraphWidget::seal() {
  if (sealed) {
    return;
  }

  auto x_max = series->at(series->count() - 1).x();
  if (x_max < window_size) {
    sealed = true;
    return;
  }

  axis_x->setRange(x_max - window_size + 1, x_max);

  scroll_bar->setRange(0, x_max - window_size + 1);
  scroll_bar->setValue(x_max - window_size + 1);
  scroll_bar->show();

  connect(scroll_bar, &QScrollBar::valueChanged, [this](int value) {
    axis_x->setRange(value, value + window_size - 1);
  });

  sealed = true;
}
