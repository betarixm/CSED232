/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_watch;
    QLabel *clock_label_time;
    QLabel *clock_label_date;
    QWidget *tab_stopwatch;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *stopwatch_btn_start;
    QPushButton *stopwatch_btn_stop;
    QPushButton *stopwatch_btn_reset;
    QLabel *stopwatch_label;
    QWidget *tab_timer;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *timer_start;
    QPushButton *timer_stop;
    QPushButton *timer_reset;
    QPushButton *timer_btn_hour_up;
    QPushButton *timer_btn_sec_up;
    QPushButton *timer_btn_minute_up;
    QPushButton *timer_btn_hour_down;
    QPushButton *timer_btn_sec_down;
    QPushButton *timer_btn_minute_down;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *timer_label_hour;
    QLabel *label_20;
    QLabel *timer_label_minute;
    QLabel *label_22;
    QLabel *timer_label_sec;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 622);
        MainWindow->setDocumentMode(false);
        MainWindow->setDockNestingEnabled(false);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 801, 581));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setTabBarAutoHide(false);
        tab_watch = new QWidget();
        tab_watch->setObjectName(QString::fromUtf8("tab_watch"));
        clock_label_time = new QLabel(tab_watch);
        clock_label_time->setObjectName(QString::fromUtf8("clock_label_time"));
        clock_label_time->setGeometry(QRect(0, 190, 801, 70));
        QFont font;
        font.setPointSize(48);
        clock_label_time->setFont(font);
        clock_label_time->setAlignment(Qt::AlignCenter);
        clock_label_date = new QLabel(tab_watch);
        clock_label_date->setObjectName(QString::fromUtf8("clock_label_date"));
        clock_label_date->setGeometry(QRect(0, 260, 801, 57));
        QFont font1;
        font1.setPointSize(36);
        clock_label_date->setFont(font1);
        clock_label_date->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_watch, QString());
        tab_stopwatch = new QWidget();
        tab_stopwatch->setObjectName(QString::fromUtf8("tab_stopwatch"));
        horizontalLayoutWidget = new QWidget(tab_stopwatch);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 280, 801, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stopwatch_btn_start = new QPushButton(horizontalLayoutWidget);
        stopwatch_btn_start->setObjectName(QString::fromUtf8("stopwatch_btn_start"));

        horizontalLayout->addWidget(stopwatch_btn_start);

        stopwatch_btn_stop = new QPushButton(horizontalLayoutWidget);
        stopwatch_btn_stop->setObjectName(QString::fromUtf8("stopwatch_btn_stop"));

        horizontalLayout->addWidget(stopwatch_btn_stop);

        stopwatch_btn_reset = new QPushButton(horizontalLayoutWidget);
        stopwatch_btn_reset->setObjectName(QString::fromUtf8("stopwatch_btn_reset"));

        horizontalLayout->addWidget(stopwatch_btn_reset);

        stopwatch_label = new QLabel(tab_stopwatch);
        stopwatch_label->setObjectName(QString::fromUtf8("stopwatch_label"));
        stopwatch_label->setGeometry(QRect(0, 190, 801, 70));
        stopwatch_label->setFont(font);
        stopwatch_label->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_stopwatch, QString());
        tab_timer = new QWidget();
        tab_timer->setObjectName(QString::fromUtf8("tab_timer"));
        horizontalLayoutWidget_3 = new QWidget(tab_timer);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 310, 801, 32));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        timer_start = new QPushButton(horizontalLayoutWidget_3);
        timer_start->setObjectName(QString::fromUtf8("timer_start"));

        horizontalLayout_3->addWidget(timer_start);

        timer_stop = new QPushButton(horizontalLayoutWidget_3);
        timer_stop->setObjectName(QString::fromUtf8("timer_stop"));

        horizontalLayout_3->addWidget(timer_stop);

        timer_reset = new QPushButton(horizontalLayoutWidget_3);
        timer_reset->setObjectName(QString::fromUtf8("timer_reset"));

        horizontalLayout_3->addWidget(timer_reset);

        timer_btn_hour_up = new QPushButton(tab_timer);
        timer_btn_hour_up->setObjectName(QString::fromUtf8("timer_btn_hour_up"));
        timer_btn_hour_up->setGeometry(QRect(260, 150, 61, 32));
        timer_btn_sec_up = new QPushButton(tab_timer);
        timer_btn_sec_up->setObjectName(QString::fromUtf8("timer_btn_sec_up"));
        timer_btn_sec_up->setGeometry(QRect(480, 150, 61, 32));
        timer_btn_minute_up = new QPushButton(tab_timer);
        timer_btn_minute_up->setObjectName(QString::fromUtf8("timer_btn_minute_up"));
        timer_btn_minute_up->setGeometry(QRect(370, 150, 61, 32));
        timer_btn_hour_down = new QPushButton(tab_timer);
        timer_btn_hour_down->setObjectName(QString::fromUtf8("timer_btn_hour_down"));
        timer_btn_hour_down->setGeometry(QRect(260, 270, 61, 32));
        timer_btn_sec_down = new QPushButton(tab_timer);
        timer_btn_sec_down->setObjectName(QString::fromUtf8("timer_btn_sec_down"));
        timer_btn_sec_down->setGeometry(QRect(480, 270, 61, 32));
        timer_btn_minute_down = new QPushButton(tab_timer);
        timer_btn_minute_down->setObjectName(QString::fromUtf8("timer_btn_minute_down"));
        timer_btn_minute_down->setGeometry(QRect(370, 270, 61, 32));
        horizontalLayoutWidget_2 = new QWidget(tab_timer);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 190, 801, 66));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        timer_label_hour = new QLabel(horizontalLayoutWidget_2);
        timer_label_hour->setObjectName(QString::fromUtf8("timer_label_hour"));
        timer_label_hour->setFont(font);
        timer_label_hour->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(timer_label_hour);

        label_20 = new QLabel(horizontalLayoutWidget_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);
        label_20->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_20);

        timer_label_minute = new QLabel(horizontalLayoutWidget_2);
        timer_label_minute->setObjectName(QString::fromUtf8("timer_label_minute"));
        timer_label_minute->setFont(font);
        timer_label_minute->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(timer_label_minute);

        label_22 = new QLabel(horizontalLayoutWidget_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font);
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_22);

        timer_label_sec = new QLabel(horizontalLayoutWidget_2);
        timer_label_sec->setObjectName(QString::fromUtf8("timer_label_sec"));
        timer_label_sec->setFont(font);
        timer_label_sec->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(timer_label_sec);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        tabWidget->addTab(tab_timer, QString());
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(3, 580, 801, 20));
        label->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "20190084", nullptr));
        clock_label_time->setText(QString());
        clock_label_date->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_watch), QCoreApplication::translate("MainWindow", "Watch", nullptr));
        stopwatch_btn_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stopwatch_btn_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        stopwatch_btn_reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        stopwatch_label->setText(QCoreApplication::translate("MainWindow", "00 : 00.00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_stopwatch), QCoreApplication::translate("MainWindow", "Stopwatch", nullptr));
        timer_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        timer_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        timer_reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        timer_btn_hour_up->setText(QCoreApplication::translate("MainWindow", "Up", nullptr));
        timer_btn_sec_up->setText(QCoreApplication::translate("MainWindow", "Up", nullptr));
        timer_btn_minute_up->setText(QCoreApplication::translate("MainWindow", "Up", nullptr));
        timer_btn_hour_down->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
        timer_btn_sec_down->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
        timer_btn_minute_down->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
        timer_label_hour->setText(QCoreApplication::translate("MainWindow", "00", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        timer_label_minute->setText(QCoreApplication::translate("MainWindow", "00", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        timer_label_sec->setText(QCoreApplication::translate("MainWindow", "00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_timer), QCoreApplication::translate("MainWindow", "Timer", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CSED232 ASSN5: 20190084", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
