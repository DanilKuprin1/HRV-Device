/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../../src/ui/BreathPacerWidget.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *rootWidget;
    QGroupBox *historyGroupBox;
    QListWidget *sessionHistoryListWidget;
    QWidget *layoutWidget;
    QHBoxLayout *historyToolButtonsHBoxLayout;
    QHBoxLayout *historyToolButtonsLeftHBoxLayout;
    QToolButton *createToolButton;
    QToolButton *deleteToolButton;
    QSpacerItem *historyToolButtonsSpacer;
    QToolButton *clearAllToolButton;
    QGroupBox *sessionGroupBox;
    QProgressBar *batteryLevelProgressBar;
    QChartView *sessionChartView;
    QWidget *layoutWidget1;
    QHBoxLayout *sessionToolButtonsLayout;
    QToolButton *playToolButton;
    QToolButton *pauseToolButton;
    QToolButton *stopToolButton;
    QToolButton *powerToolButton;
    QLabel *HRContactLabel;
    BreathPacerWidget *breathPacer;
    QWidget *layoutWidget2;
    QHBoxLayout *settingsAndMetricsHBoxLayout;
    QGroupBox *settingsGroupBox;
    QWidget *layoutWidget3;
    QVBoxLayout *settingsVBoxLayout;
    QHBoxLayout *challengeLevelHBoxLayout;
    QLabel *challengeLevelLabel;
    QSpinBox *challengeLevelSpinBox;
    QHBoxLayout *breathPacerIntervalHBoxLayout;
    QLabel *breathPacerIntervalLabel;
    QSpinBox *breathPacerIntervalSpinBox;
    QHBoxLayout *simulatedCoherenceLevelHBoxLayout;
    QLabel *simulatedCoherenceLevelLabel;
    QSpinBox *simulatedCoherenceLevelSpinBox;
    QGroupBox *metricsGroupBox;
    QWidget *layoutWidget4;
    QVBoxLayout *metricsVBoxLayout;
    QHBoxLayout *sessionLengthHBoxLayout;
    QLabel *sessionLengthLabel;
    QLCDNumber *sessionLengthLCDNumber;
    QHBoxLayout *coherenceScoreHBoxLayout;
    QLabel *coherenceScoreLabel;
    QLCDNumber *coherenceScoreLCDNumber;
    QHBoxLayout *achievementScoreHBoxLayout;
    QLabel *achievementScoreLabel;
    QLCDNumber *achievementScoreLCDNumber;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        rootWidget = new QWidget(MainWindow);
        rootWidget->setObjectName("rootWidget");
        historyGroupBox = new QGroupBox(rootWidget);
        historyGroupBox->setObjectName("historyGroupBox");
        historyGroupBox->setGeometry(QRect(21, 11, 200, 579));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(historyGroupBox->sizePolicy().hasHeightForWidth());
        historyGroupBox->setSizePolicy(sizePolicy);
        historyGroupBox->setMinimumSize(QSize(200, 0));
        sessionHistoryListWidget = new QListWidget(historyGroupBox);
        sessionHistoryListWidget->setObjectName("sessionHistoryListWidget");
        sessionHistoryListWidget->setGeometry(QRect(10, 30, 181, 511));
        layoutWidget = new QWidget(historyGroupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 550, 181, 30));
        historyToolButtonsHBoxLayout = new QHBoxLayout(layoutWidget);
        historyToolButtonsHBoxLayout->setObjectName("historyToolButtonsHBoxLayout");
        historyToolButtonsHBoxLayout->setContentsMargins(0, 0, 0, 0);
        historyToolButtonsLeftHBoxLayout = new QHBoxLayout();
        historyToolButtonsLeftHBoxLayout->setObjectName("historyToolButtonsLeftHBoxLayout");
        createToolButton = new QToolButton(layoutWidget);
        createToolButton->setObjectName("createToolButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/fontawesome/solid/plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        createToolButton->setIcon(icon);

        historyToolButtonsLeftHBoxLayout->addWidget(createToolButton);

        deleteToolButton = new QToolButton(layoutWidget);
        deleteToolButton->setObjectName("deleteToolButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/fontawesome/solid/minus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        deleteToolButton->setIcon(icon1);

        historyToolButtonsLeftHBoxLayout->addWidget(deleteToolButton);


        historyToolButtonsHBoxLayout->addLayout(historyToolButtonsLeftHBoxLayout);

        historyToolButtonsSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        historyToolButtonsHBoxLayout->addItem(historyToolButtonsSpacer);

        clearAllToolButton = new QToolButton(layoutWidget);
        clearAllToolButton->setObjectName("clearAllToolButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/fontawesome/solid/trash.svg"), QSize(), QIcon::Normal, QIcon::Off);
        clearAllToolButton->setIcon(icon2);

        historyToolButtonsHBoxLayout->addWidget(clearAllToolButton);

        sessionGroupBox = new QGroupBox(rootWidget);
        sessionGroupBox->setObjectName("sessionGroupBox");
        sessionGroupBox->setGeometry(QRect(228, 12, 561, 431));
        batteryLevelProgressBar = new QProgressBar(sessionGroupBox);
        batteryLevelProgressBar->setObjectName("batteryLevelProgressBar");
        batteryLevelProgressBar->setGeometry(QRect(470, 40, 71, 21));
        batteryLevelProgressBar->setValue(100);
        sessionChartView = new QChartView(sessionGroupBox);
        sessionChartView->setObjectName("sessionChartView");
        sessionChartView->setGeometry(QRect(10, 31, 541, 361));
        layoutWidget1 = new QWidget(sessionGroupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(210, 400, 130, 28));
        sessionToolButtonsLayout = new QHBoxLayout(layoutWidget1);
        sessionToolButtonsLayout->setObjectName("sessionToolButtonsLayout");
        sessionToolButtonsLayout->setContentsMargins(0, 0, 0, 0);
        playToolButton = new QToolButton(layoutWidget1);
        playToolButton->setObjectName("playToolButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/fontawesome/solid/play.svg"), QSize(), QIcon::Normal, QIcon::Off);
        playToolButton->setIcon(icon3);

        sessionToolButtonsLayout->addWidget(playToolButton);

        pauseToolButton = new QToolButton(layoutWidget1);
        pauseToolButton->setObjectName("pauseToolButton");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/fontawesome/solid/pause.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pauseToolButton->setIcon(icon4);

        sessionToolButtonsLayout->addWidget(pauseToolButton);

        stopToolButton = new QToolButton(layoutWidget1);
        stopToolButton->setObjectName("stopToolButton");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/fontawesome/solid/stop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stopToolButton->setIcon(icon5);

        sessionToolButtonsLayout->addWidget(stopToolButton);

        powerToolButton = new QToolButton(layoutWidget1);
        powerToolButton->setObjectName("powerToolButton");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/fontawesome/solid/power-off.svg"), QSize(), QIcon::Normal, QIcon::Off);
        powerToolButton->setIcon(icon6);

        sessionToolButtonsLayout->addWidget(powerToolButton);

        HRContactLabel = new QLabel(sessionGroupBox);
        HRContactLabel->setObjectName("HRContactLabel");
        HRContactLabel->setEnabled(true);
        HRContactLabel->setGeometry(QRect(440, 40, 21, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(100);
        sizePolicy1.setHeightForWidth(HRContactLabel->sizePolicy().hasHeightForWidth());
        HRContactLabel->setSizePolicy(sizePolicy1);
        HRContactLabel->setMaximumSize(QSize(100, 100));
        HRContactLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/fontawesome/solid/heart-pulse.svg")));
        HRContactLabel->setScaledContents(true);
        HRContactLabel->setWordWrap(false);
        breathPacer = new BreathPacerWidget(sessionGroupBox);
        breathPacer->setObjectName("breathPacer");
        breathPacer->setGeometry(QRect(20, 360, 521, 23));
        breathPacer->setMaximum(1000);
        breathPacer->setValue(0);
        breathPacer->setAlignment(Qt::AlignCenter);
        layoutWidget1->raise();
        sessionChartView->raise();
        batteryLevelProgressBar->raise();
        HRContactLabel->raise();
        breathPacer->raise();
        layoutWidget2 = new QWidget(rootWidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(230, 450, 561, 141));
        settingsAndMetricsHBoxLayout = new QHBoxLayout(layoutWidget2);
        settingsAndMetricsHBoxLayout->setObjectName("settingsAndMetricsHBoxLayout");
        settingsAndMetricsHBoxLayout->setContentsMargins(0, 0, 0, 0);
        settingsGroupBox = new QGroupBox(layoutWidget2);
        settingsGroupBox->setObjectName("settingsGroupBox");
        layoutWidget3 = new QWidget(settingsGroupBox);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 30, 261, 101));
        settingsVBoxLayout = new QVBoxLayout(layoutWidget3);
        settingsVBoxLayout->setObjectName("settingsVBoxLayout");
        settingsVBoxLayout->setContentsMargins(0, 0, 0, 0);
        challengeLevelHBoxLayout = new QHBoxLayout();
        challengeLevelHBoxLayout->setObjectName("challengeLevelHBoxLayout");
        challengeLevelLabel = new QLabel(layoutWidget3);
        challengeLevelLabel->setObjectName("challengeLevelLabel");

        challengeLevelHBoxLayout->addWidget(challengeLevelLabel);

        challengeLevelSpinBox = new QSpinBox(layoutWidget3);
        challengeLevelSpinBox->setObjectName("challengeLevelSpinBox");
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(challengeLevelSpinBox->sizePolicy().hasHeightForWidth());
        challengeLevelSpinBox->setSizePolicy(sizePolicy2);
        challengeLevelSpinBox->setMinimumSize(QSize(48, 0));
        challengeLevelSpinBox->setMinimum(1);
        challengeLevelSpinBox->setMaximum(4);

        challengeLevelHBoxLayout->addWidget(challengeLevelSpinBox);


        settingsVBoxLayout->addLayout(challengeLevelHBoxLayout);

        breathPacerIntervalHBoxLayout = new QHBoxLayout();
        breathPacerIntervalHBoxLayout->setObjectName("breathPacerIntervalHBoxLayout");
        breathPacerIntervalLabel = new QLabel(layoutWidget3);
        breathPacerIntervalLabel->setObjectName("breathPacerIntervalLabel");

        breathPacerIntervalHBoxLayout->addWidget(breathPacerIntervalLabel);

        breathPacerIntervalSpinBox = new QSpinBox(layoutWidget3);
        breathPacerIntervalSpinBox->setObjectName("breathPacerIntervalSpinBox");
        sizePolicy2.setHeightForWidth(breathPacerIntervalSpinBox->sizePolicy().hasHeightForWidth());
        breathPacerIntervalSpinBox->setSizePolicy(sizePolicy2);
        breathPacerIntervalSpinBox->setMaximumSize(QSize(48, 16777215));
        breathPacerIntervalSpinBox->setMinimum(1);
        breathPacerIntervalSpinBox->setMaximum(30);
        breathPacerIntervalSpinBox->setValue(10);

        breathPacerIntervalHBoxLayout->addWidget(breathPacerIntervalSpinBox);


        settingsVBoxLayout->addLayout(breathPacerIntervalHBoxLayout);

        simulatedCoherenceLevelHBoxLayout = new QHBoxLayout();
        simulatedCoherenceLevelHBoxLayout->setObjectName("simulatedCoherenceLevelHBoxLayout");
        simulatedCoherenceLevelLabel = new QLabel(layoutWidget3);
        simulatedCoherenceLevelLabel->setObjectName("simulatedCoherenceLevelLabel");

        simulatedCoherenceLevelHBoxLayout->addWidget(simulatedCoherenceLevelLabel);

        simulatedCoherenceLevelSpinBox = new QSpinBox(layoutWidget3);
        simulatedCoherenceLevelSpinBox->setObjectName("simulatedCoherenceLevelSpinBox");
        sizePolicy2.setHeightForWidth(simulatedCoherenceLevelSpinBox->sizePolicy().hasHeightForWidth());
        simulatedCoherenceLevelSpinBox->setSizePolicy(sizePolicy2);
        simulatedCoherenceLevelSpinBox->setMaximumSize(QSize(48, 16777215));
        simulatedCoherenceLevelSpinBox->setMinimum(1);
        simulatedCoherenceLevelSpinBox->setMaximum(3);
        simulatedCoherenceLevelSpinBox->setValue(1);

        simulatedCoherenceLevelHBoxLayout->addWidget(simulatedCoherenceLevelSpinBox);


        settingsVBoxLayout->addLayout(simulatedCoherenceLevelHBoxLayout);


        settingsAndMetricsHBoxLayout->addWidget(settingsGroupBox);

        metricsGroupBox = new QGroupBox(layoutWidget2);
        metricsGroupBox->setObjectName("metricsGroupBox");
        layoutWidget4 = new QWidget(metricsGroupBox);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(10, 30, 261, 101));
        metricsVBoxLayout = new QVBoxLayout(layoutWidget4);
        metricsVBoxLayout->setObjectName("metricsVBoxLayout");
        metricsVBoxLayout->setContentsMargins(0, 0, 0, 0);
        sessionLengthHBoxLayout = new QHBoxLayout();
        sessionLengthHBoxLayout->setObjectName("sessionLengthHBoxLayout");
        sessionLengthLabel = new QLabel(layoutWidget4);
        sessionLengthLabel->setObjectName("sessionLengthLabel");

        sessionLengthHBoxLayout->addWidget(sessionLengthLabel);

        sessionLengthLCDNumber = new QLCDNumber(layoutWidget4);
        sessionLengthLCDNumber->setObjectName("sessionLengthLCDNumber");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sessionLengthLCDNumber->sizePolicy().hasHeightForWidth());
        sessionLengthLCDNumber->setSizePolicy(sizePolicy3);
        sessionLengthLCDNumber->setMinimumSize(QSize(64, 0));
        sessionLengthLCDNumber->setMaximumSize(QSize(64, 16777215));
        sessionLengthLCDNumber->setSmallDecimalPoint(false);

        sessionLengthHBoxLayout->addWidget(sessionLengthLCDNumber);


        metricsVBoxLayout->addLayout(sessionLengthHBoxLayout);

        coherenceScoreHBoxLayout = new QHBoxLayout();
        coherenceScoreHBoxLayout->setObjectName("coherenceScoreHBoxLayout");
        coherenceScoreLabel = new QLabel(layoutWidget4);
        coherenceScoreLabel->setObjectName("coherenceScoreLabel");

        coherenceScoreHBoxLayout->addWidget(coherenceScoreLabel);

        coherenceScoreLCDNumber = new QLCDNumber(layoutWidget4);
        coherenceScoreLCDNumber->setObjectName("coherenceScoreLCDNumber");
        coherenceScoreLCDNumber->setMinimumSize(QSize(64, 0));
        coherenceScoreLCDNumber->setMaximumSize(QSize(64, 16777215));
        coherenceScoreLCDNumber->setDigitCount(5);

        coherenceScoreHBoxLayout->addWidget(coherenceScoreLCDNumber);


        metricsVBoxLayout->addLayout(coherenceScoreHBoxLayout);

        achievementScoreHBoxLayout = new QHBoxLayout();
        achievementScoreHBoxLayout->setObjectName("achievementScoreHBoxLayout");
        achievementScoreLabel = new QLabel(layoutWidget4);
        achievementScoreLabel->setObjectName("achievementScoreLabel");

        achievementScoreHBoxLayout->addWidget(achievementScoreLabel);

        achievementScoreLCDNumber = new QLCDNumber(layoutWidget4);
        achievementScoreLCDNumber->setObjectName("achievementScoreLCDNumber");
        achievementScoreLCDNumber->setMinimumSize(QSize(64, 0));
        achievementScoreLCDNumber->setMaximumSize(QSize(64, 16777215));

        achievementScoreHBoxLayout->addWidget(achievementScoreLCDNumber);


        metricsVBoxLayout->addLayout(achievementScoreHBoxLayout);


        settingsAndMetricsHBoxLayout->addWidget(metricsGroupBox);

        MainWindow->setCentralWidget(rootWidget);
        QWidget::setTabOrder(sessionHistoryListWidget, createToolButton);
        QWidget::setTabOrder(createToolButton, deleteToolButton);
        QWidget::setTabOrder(deleteToolButton, clearAllToolButton);
        QWidget::setTabOrder(clearAllToolButton, sessionChartView);
        QWidget::setTabOrder(sessionChartView, playToolButton);
        QWidget::setTabOrder(playToolButton, pauseToolButton);
        QWidget::setTabOrder(pauseToolButton, stopToolButton);
        QWidget::setTabOrder(stopToolButton, powerToolButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "HeartWave Simulator", nullptr));
        historyGroupBox->setTitle(QCoreApplication::translate("MainWindow", "History", nullptr));
#if QT_CONFIG(tooltip)
        createToolButton->setToolTip(QCoreApplication::translate("MainWindow", "Create", nullptr));
#endif // QT_CONFIG(tooltip)
        createToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        deleteToolButton->setToolTip(QCoreApplication::translate("MainWindow", "Delete", nullptr));
#endif // QT_CONFIG(tooltip)
        deleteToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        clearAllToolButton->setToolTip(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
#endif // QT_CONFIG(tooltip)
        clearAllToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        sessionGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Session", nullptr));
#if QT_CONFIG(tooltip)
        batteryLevelProgressBar->setToolTip(QCoreApplication::translate("MainWindow", "Battery Level", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        playToolButton->setToolTip(QCoreApplication::translate("MainWindow", "Start", nullptr));
#endif // QT_CONFIG(tooltip)
        playToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        pauseToolButton->setToolTip(QCoreApplication::translate("MainWindow", "Pause", nullptr));
#endif // QT_CONFIG(tooltip)
        pauseToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        stopToolButton->setToolTip(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#endif // QT_CONFIG(tooltip)
        stopToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        powerToolButton->setToolTip(QCoreApplication::translate("MainWindow", "Power", nullptr));
#endif // QT_CONFIG(tooltip)
        powerToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        HRContactLabel->setText(QString());
        breathPacer->setFormat(QString());
        settingsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        challengeLevelLabel->setText(QCoreApplication::translate("MainWindow", "Challenge Level", nullptr));
        breathPacerIntervalLabel->setText(QCoreApplication::translate("MainWindow", "Breath Pacer Interval (seconds)", nullptr));
        simulatedCoherenceLevelLabel->setText(QCoreApplication::translate("MainWindow", "Simulated Coherence Level", nullptr));
        metricsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Metrics", nullptr));
        sessionLengthLabel->setText(QCoreApplication::translate("MainWindow", "Session Length (minutes)", nullptr));
        coherenceScoreLabel->setText(QCoreApplication::translate("MainWindow", "Coherence Score", nullptr));
        achievementScoreLabel->setText(QCoreApplication::translate("MainWindow", "Achievement Score", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
