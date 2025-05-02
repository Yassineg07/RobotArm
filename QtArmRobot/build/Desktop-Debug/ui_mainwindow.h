/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *verticalSlider_1;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QLabel *slider_1;
    QLabel *slider_2;
    QLabel *slider_3;
    QLabel *degree_1;
    QLabel *degree_2;
    QLabel *degree_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalSlider_1 = new QSlider(centralwidget);
        verticalSlider_1->setObjectName("verticalSlider_1");
        verticalSlider_1->setGeometry(QRect(540, 140, 51, 261));
        verticalSlider_1->setOrientation(Qt::Orientation::Vertical);
        verticalSlider_2 = new QSlider(centralwidget);
        verticalSlider_2->setObjectName("verticalSlider_2");
        verticalSlider_2->setGeometry(QRect(380, 140, 51, 261));
        verticalSlider_2->setOrientation(Qt::Orientation::Vertical);
        verticalSlider_3 = new QSlider(centralwidget);
        verticalSlider_3->setObjectName("verticalSlider_3");
        verticalSlider_3->setGeometry(QRect(210, 140, 51, 261));
        verticalSlider_3->setOrientation(Qt::Orientation::Vertical);
        slider_1 = new QLabel(centralwidget);
        slider_1->setObjectName("slider_1");
        slider_1->setGeometry(QRect(550, 410, 81, 31));
        slider_1->setMinimumSize(QSize(81, 0));
        slider_1->setMaximumSize(QSize(81, 61));
        slider_2 = new QLabel(centralwidget);
        slider_2->setObjectName("slider_2");
        slider_2->setGeometry(QRect(390, 410, 51, 41));
        slider_3 = new QLabel(centralwidget);
        slider_3->setObjectName("slider_3");
        slider_3->setGeometry(QRect(210, 410, 51, 41));
        degree_1 = new QLabel(centralwidget);
        degree_1->setObjectName("degree_1");
        degree_1->setGeometry(QRect(540, 100, 49, 16));
        degree_2 = new QLabel(centralwidget);
        degree_2->setObjectName("degree_2");
        degree_2->setGeometry(QRect(380, 100, 49, 16));
        degree_3 = new QLabel(centralwidget);
        degree_3->setObjectName("degree_3");
        degree_3->setGeometry(QRect(210, 100, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        slider_1->setText(QCoreApplication::translate("MainWindow", "slider 1", nullptr));
        slider_2->setText(QCoreApplication::translate("MainWindow", "slider 2", nullptr));
        slider_3->setText(QCoreApplication::translate("MainWindow", "slider 3", nullptr));
        degree_1->setText(QCoreApplication::translate("MainWindow", "0 Degree", nullptr));
        degree_2->setText(QCoreApplication::translate("MainWindow", "0 Degree", nullptr));
        degree_3->setText(QCoreApplication::translate("MainWindow", "0 Degree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
