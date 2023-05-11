#include <QFrame>

enum class CoherenceLevel {
  Low,
  Medium,
  High,
};

class CoherenceIndicatorWidget : public QFrame {
  Q_OBJECT

  public:
    explicit CoherenceIndicatorWidget(QWidget* parent = nullptr);

    // Disable copy
    CoherenceIndicatorWidget(const CoherenceIndicatorWidget&) = delete;

    // Disable move
    CoherenceIndicatorWidget(CoherenceIndicatorWidget &&) = delete;

    // Disable copy assignment
    CoherenceIndicatorWidget& operator=(const CoherenceIndicatorWidget&) = delete;

    void set_level(CoherenceLevel level);

    CoherenceLevel get_level();

  protected:
    void paintEvent(QPaintEvent * event) override;

  private:
    CoherenceLevel level;
};
