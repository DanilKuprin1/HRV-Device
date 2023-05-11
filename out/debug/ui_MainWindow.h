/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../../src/ui/BatteryIndicatorWidget.hpp"
#include "../../src/ui/BreathPacerWidget.hpp"
#include "../../src/ui/CoherenceIndicatorWidget.hpp"
#include "../../src/ui/HRVGraphWidget.hpp"

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
    QToolButton *deleteSession;
    QSpacerItem *historyToolButtonsSpacer;
    QToolButton *clearSessionHistory;
    QGroupBox *sessionGroupBox;
    BatteryIndicatorWidget *batteryIndicator;
    QWidget *layoutWidget1;
    QHBoxLayout *sessionToolButtonsLayout;
    QToolButton *startSession;
    QToolButton *stopSession;
    QToolButton *powerButton;
    BreathPacerWidget *breathPacer;
    HRVGraphWidget *hrvGraph;
    CoherenceIndicatorWidget *coherenceIndicator;
    QPushButton *interruptSensor;
    QLabel *HRContactLabel;
    QWidget *layoutWidget2;
    QHBoxLayout *settingsAndMetricsHBoxLayout;
    QGroupBox *metricsGroupBox;
    QWidget *layoutWidget3;
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
    QGroupBox *coherenceMetricsGroup;
    QWidget *layoutWidget4;
    QVBoxLayout *settingsVBoxLayout;
    QHBoxLayout *challengeLevelHBoxLayout;
    QLabel *label1;
    QLCDNumber *highCoherencePercent;
    QHBoxLayout *breathPacerIntervalHBoxLayout;
    QLabel *label2;
    QLCDNumber *mediumCoherencePercent;
    QHBoxLayout *simulatedCoherenceLevelHBoxLayout;
    QLabel *label3;
    QLCDNumber *lowCoherencePercent;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(800, 600));
        rootWidget = new QWidget(MainWindow);
        rootWidget->setObjectName("rootWidget");
        historyGroupBox = new QGroupBox(rootWidget);
        historyGroupBox->setObjectName("historyGroupBox");
        historyGroupBox->setGeometry(QRect(21, 11, 200, 579));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(historyGroupBox->sizePolicy().hasHeightForWidth());
        historyGroupBox->setSizePolicy(sizePolicy1);
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
        deleteSession = new QToolButton(layoutWidget);
        deleteSession->setObjectName("deleteSession");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/fontawesome/solid/minus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        deleteSession->setIcon(icon);

        historyToolButtonsLeftHBoxLayout->addWidget(deleteSession);


        historyToolButtonsHBoxLayout->addLayout(historyToolButtonsLeftHBoxLayout);

        historyToolButtonsSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        historyToolButtonsHBoxLayout->addItem(historyToolButtonsSpacer);

        clearSessionHistory = new QToolButton(layoutWidget);
        clearSessionHistory->setObjectName("clearSessionHistory");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/fontawesome/solid/trash.svg"), QSize(), QIcon::Normal, QIcon::Off);
        clearSessionHistory->setIcon(icon1);

        historyToolButtonsHBoxLayout->addWidget(clearSessionHistory);

        sessionGroupBox = new QGroupBox(rootWidget);
        sessionGroupBox->setObjectName("sessionGroupBox");
        sessionGroupBox->setGeometry(QRect(228, 12, 561, 431));
        batteryIndicator = new BatteryIndicatorWidget(sessionGroupBox);
        batteryIndicator->setObjectName("batteryIndicator");
        batteryIndicator->setGeometry(QRect(440, 50, 91, 21));
        batteryIndicator->setValue(100);
        batteryIndicator->setAlignment(Qt::AlignCenter);
        layoutWidget1 = new QWidget(sessionGroupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(210, 400, 130, 28));
        sessionToolButtonsLayout = new QHBoxLayout(layoutWidget1);
        sessionToolButtonsLayout->setObjectName("sessionToolButtonsLayout");
        sessionToolButtonsLayout->setContentsMargins(0, 0, 0, 0);
        startSession = new QToolButton(layoutWidget1);
        startSession->setObjectName("startSession");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/fontawesome/solid/play.svg"), QSize(), QIcon::Normal, QIcon::Off);
        startSession->setIcon(icon2);

        sessionToolButtonsLayout->addWidget(startSession);

        stopSession = new QToolButton(layoutWidget1);
        stopSession->setObjectName("stopSession");
        stopSession->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/fontawesome/solid/stop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stopSession->setIcon(icon3);

        sessionToolButtonsLayout->addWidget(stopSession);

        powerButton = new QToolButton(layoutWidget1);
        powerButton->setObjectName("powerButton");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/fontawesome/solid/power-off.svg"), QSize(), QIcon::Normal, QIcon::Off);
        powerButton->setIcon(icon4);

        sessionToolButtonsLayout->addWidget(powerButton);

        breathPacer = new BreathPacerWidget(sessionGroupBox);
        breathPacer->setObjectName("breathPacer");
        breathPacer->setGeometry(QRect(20, 360, 521, 23));
        breathPacer->setMaximum(1000);
        breathPacer->setValue(0);
        breathPacer->setAlignment(Qt::AlignCenter);
        hrvGraph = new HRVGraphWidget(sessionGroupBox);
        hrvGraph->setObjectName("hrvGraph");
        hrvGraph->setGeometry(QRect(19, 69, 531, 281));
        coherenceIndicator = new CoherenceIndicatorWidget(sessionGroupBox);
        coherenceIndicator->setObjectName("coherenceIndicator");
        coherenceIndicator->setGeometry(QRect(60, 40, 81, 31));
        coherenceIndicator->setFrameShape(QFrame::StyledPanel);
        coherenceIndicator->setFrameShadow(QFrame::Raised);
        interruptSensor = new QPushButton(sessionGroupBox);
        interruptSensor->setObjectName("interruptSensor");
        interruptSensor->setGeometry(QRect(10, 400, 111, 25));
        HRContactLabel = new QLabel(sessionGroupBox);
        HRContactLabel->setObjectName("HRContactLabel");
        HRContactLabel->setEnabled(true);
        HRContactLabel->setGeometry(QRect(30, 42, 21, 21));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(100);
        sizePolicy2.setHeightForWidth(HRContactLabel->sizePolicy().hasHeightForWidth());
        HRContactLabel->setSizePolicy(sizePolicy2);
        HRContactLabel->setMaximumSize(QSize(100, 100));
        HRContactLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/fontawesome/solid/heart-pulse.svg")));
        HRContactLabel->setScaledContents(true);
        HRContactLabel->setWordWrap(false);
        HRContactLabel->raise();
        layoutWidget3->raise();
        batteryIndicator->raise();
        breathPacer->raise();
        hrvGraph->raise();
        coherenceIndicator->raise();
        interruptSensor->raise();
        layoutWidget2 = new QWidget(rootWidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(230, 450, 561, 141));
        settingsAndMetricsHBoxLayout = new QHBoxLayout(layoutWidget2);
        settingsAndMetricsHBoxLayout->setObjectName("settingsAndMetricsHBoxLayout");
        settingsAndMetricsHBoxLayout->setContentsMargins(0, 0, 0, 0);
        metricsGroupBox = new QGroupBox(layoutWidget2);
        metricsGroupBox->setObjectName("metricsGroupBox");
        layoutWidget3 = new QWidget(metricsGroupBox);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 30, 261, 101));
        metricsVBoxLayout = new QVBoxLayout(layoutWidget3);
        metricsVBoxLayout->setObjectName("metricsVBoxLayout");
        metricsVBoxLayout->setContentsMargins(0, 0, 0, 0);
        sessionLengthHBoxLayout = new QHBoxLayout();
        sessionLengthHBoxLayout->setObjectName("sessionLengthHBoxLayout");
        sessionLengthLabel = new QLabel(layoutWidget3);
        sessionLengthLabel->setObjectName("sessionLengthLabel");

        sessionLengthHBoxLayout->addWidget(sessionLengthLabel);

        sessionLengthLCDNumber = new QLCDNumber(layoutWidget3);
        sessionLengthLCDNumber->setObjectName("sessionLengthLCDNumber");
        sessionLengthLCDNumber->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sessionLengthLCDNumber->sizePolicy().hasHeightForWidth());
        sessionLengthLCDNumber->setSizePolicy(sizePolicy3);
        sessionLengthLCDNumber->setMinimumSize(QSize(64, 0));
        sessionLengthLCDNumber->setMaximumSize(QSize(64, 16777215));
        sessionLengthLCDNumber->setSmallDecimalPoint(true);

        sessionLengthHBoxLayout->addWidget(sessionLengthLCDNumber);


        metricsVBoxLayout->addLayout(sessionLengthHBoxLayout);

        coherenceScoreHBoxLayout = new QHBoxLayout();
        coherenceScoreHBoxLayout->setObjectName("coherenceScoreHBoxLayout");
        coherenceScoreLabel = new QLabel(layoutWidget3);
        coherenceScoreLabel->setObjectName("coherenceScoreLabel");

        coherenceScoreHBoxLayout->addWidget(coherenceScoreLabel);

        coherenceScoreLCDNumber = new QLCDNumber(layoutWidget3);
        coherenceScoreLCDNumber->setObjectName("coherenceScoreLCDNumber");
        coherenceScoreLCDNumber->setEnabled(false);
        coherenceScoreLCDNumber->setMinimumSize(QSize(64, 0));
        coherenceScoreLCDNumber->setMaximumSize(QSize(64, 16777215));
        coherenceScoreLCDNumber->setSmallDecimalPoint(true);
        coherenceScoreLCDNumber->setDigitCount(5);

        coherenceScoreHBoxLayout->addWidget(coherenceScoreLCDNumber);


        metricsVBoxLayout->addLayout(coherenceScoreHBoxLayout);

        achievementScoreHBoxLayout = new QHBoxLayout();
        achievementScoreHBoxLayout->setObjectName("achievementScoreHBoxLayout");
        achievementScoreLabel = new QLabel(layoutWidget3);
        achievementScoreLabel->setObjectName("achievementScoreLabel");

        achievementScoreHBoxLayout->addWidget(achievementScoreLabel);

        achievementScoreLCDNumber = new QLCDNumber(layoutWidget3);
        achievementScoreLCDNumber->setObjectName("achievementScoreLCDNumber");
        achievementScoreLCDNumber->setEnabled(false);
        achievementScoreLCDNumber->setMinimumSize(QSize(64, 0));
        achievementScoreLCDNumber->setMaximumSize(QSize(64, 16777215));
        achievementScoreLCDNumber->setSmallDecimalPoint(true);

        achievementScoreHBoxLayout->addWidget(achievementScoreLCDNumber);


        metricsVBoxLayout->addLayout(achievementScoreHBoxLayout);


        settingsAndMetricsHBoxLayout->addWidget(metricsGroupBox);

        coherenceMetricsGroup = new QGroupBox(layoutWidget2);
        coherenceMetricsGroup->setObjectName("coherenceMetricsGroup");
        layoutWidget4 = new QWidget(coherenceMetricsGroup);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(10, 30, 262, 101));
        settingsVBoxLayout = new QVBoxLayout(layoutWidget4);
        settingsVBoxLayout->setObjectName("settingsVBoxLayout");
        settingsVBoxLayout->setContentsMargins(0, 0, 0, 0);
        challengeLevelHBoxLayout = new QHBoxLayout();
        challengeLevelHBoxLayout->setObjectName("challengeLevelHBoxLayout");
        label1 = new QLabel(layoutWidget4);
        label1->setObjectName("label1");

        challengeLevelHBoxLayout->addWidget(label1);

        highCoherencePercent = new QLCDNumber(layoutWidget4);
        highCoherencePercent->setObjectName("highCoherencePercent");
        highCoherencePercent->setMinimumSize(QSize(64, 0));
        highCoherencePercent->setMaximumSize(QSize(64, 16777215));
        highCoherencePercent->setSmallDecimalPoint(true);

        challengeLevelHBoxLayout->addWidget(highCoherencePercent);


        settingsVBoxLayout->addLayout(challengeLevelHBoxLayout);

        breathPacerIntervalHBoxLayout = new QHBoxLayout();
        breathPacerIntervalHBoxLayout->setObjectName("breathPacerIntervalHBoxLayout");
        label2 = new QLabel(layoutWidget4);
        label2->setObjectName("label2");

        breathPacerIntervalHBoxLayout->addWidget(label2);

        mediumCoherencePercent = new QLCDNumber(layoutWidget4);
        mediumCoherencePercent->setObjectName("mediumCoherencePercent");
        mediumCoherencePercent->setMinimumSize(QSize(64, 0));
        mediumCoherencePercent->setMaximumSize(QSize(64, 16777215));
        mediumCoherencePercent->setSmallDecimalPoint(true);

        breathPacerIntervalHBoxLayout->addWidget(mediumCoherencePercent);


        settingsVBoxLayout->addLayout(breathPacerIntervalHBoxLayout);

        simulatedCoherenceLevelHBoxLayout = new QHBoxLayout();
        simulatedCoherenceLevelHBoxLayout->setObjectName("simulatedCoherenceLevelHBoxLayout");
        label3 = new QLabel(layoutWidget4);
        label3->setObjectName("label3");

        simulatedCoherenceLevelHBoxLayout->addWidget(label3);

        lowCoherencePercent = new QLCDNumber(layoutWidget4);
        lowCoherencePercent->setObjectName("lowCoherencePercent");
        lowCoherencePercent->setMinimumSize(QSize(64, 0));
        lowCoherencePercent->setMaximumSize(QSize(64, 16777215));
        lowCoherencePercent->setSmallDecimalPoint(true);

        simulatedCoherenceLevelHBoxLayout->addWidget(lowCoherencePercent);


        settingsVBoxLayout->addLayout(simulatedCoherenceLevelHBoxLayout);


        settingsAndMetricsHBoxLayout->addWidget(coherenceMetricsGroup);

        MainWindow->setCentralWidget(rootWidget);
        QWidget::setTabOrder(sessionHistoryListWidget, deleteSession);
        QWidget::setTabOrder(deleteSession, clearSessionHistory);
        QWidget::setTabOrder(clearSessionHistory, startSession);
        QWidget::setTabOrder(startSession, stopSession);
        QWidget::setTabOrder(stopSession, powerButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "HeartWave Simulator", nullptr));
        historyGroupBox->setTitle(QCoreApplication::translate("MainWindow", "History", nullptr));
#if QT_CONFIG(tooltip)
        deleteSession->setToolTip(QCoreApplication::translate("MainWindow", "Delete", nullptr));
#endif // QT_CONFIG(tooltip)
        deleteSession->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        clearSessionHistory->setToolTip(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
#endif // QT_CONFIG(tooltip)
        clearSessionHistory->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        sessionGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Session", nullptr));
#if QT_CONFIG(tooltip)
        batteryIndicator->setToolTip(QCoreApplication::translate("MainWindow", "Battery Level", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        startSession->setToolTip(QCoreApplication::translate("MainWindow", "Start", nullptr));
#endif // QT_CONFIG(tooltip)
        startSession->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        stopSession->setToolTip(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#endif // QT_CONFIG(tooltip)
        stopSession->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        powerButton->setToolTip(QCoreApplication::translate("MainWindow", "Power", nullptr));
#endif // QT_CONFIG(tooltip)
        powerButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        breathPacer->setFormat(QString());
        interruptSensor->setText(QCoreApplication::translate("MainWindow", "Interrupt Sensor", nullptr));
        HRContactLabel->setText(QString());
        metricsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Session Metrics", nullptr));
        sessionLengthLabel->setText(QCoreApplication::translate("MainWindow", "Session Length (seconds)", nullptr));
        coherenceScoreLabel->setText(QCoreApplication::translate("MainWindow", "Coherence Score", nullptr));
        achievementScoreLabel->setText(QCoreApplication::translate("MainWindow", "Achievement Score", nullptr));
        coherenceMetricsGroup->setTitle(QCoreApplication::translate("MainWindow", "Coherence Metrics", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "High Coherence (%)", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "Medium Coherence (%)", nullptr));
        label3->setText(QCoreApplication::translate("MainWindow", "Low Coherence (%)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
