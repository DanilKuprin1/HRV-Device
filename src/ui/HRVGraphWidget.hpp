#pragma once

#include <QChartView>
#include <QLineSeries>
#include <QPointF>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

class HRVGraphWidget : public QWidget {
  Q_OBJECT

  public:
    explicit HRVGraphWidget(QWidget* parent = nullptr);

    void clear();

  public slots:
    void add_point(double x, double y);
    void seal();

  private:
    QLineSeries* series;
    int window_size;
    QChart* chart;
    QValueAxis* axis_x;
    QValueAxis* axis_y;
    QChartView* view;
    QScrollBar* scroll_bar;
    QVBoxLayout* layout;
    bool sealed;
};
