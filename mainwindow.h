#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "esp32.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSlider1ValueChanged(int value);
    void onSlider2ValueChanged(int value);
    void onSlider3ValueChanged(int value);

private:
    void sendAllServoCommands();

    void updateDegreeLabels();

    Ui::MainWindow *ui;
    ESP32 esp32;
};

#endif // MAINWINDOW_H
