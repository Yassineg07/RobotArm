#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->verticalSlider_1->setRange(0, 180);
    ui->verticalSlider_2->setRange(0, 180);
    ui->verticalSlider_3->setRange(0, 180);

    connect(ui->verticalSlider_1, &QSlider::valueChanged, this, &MainWindow::onSlider1ValueChanged);
    connect(ui->verticalSlider_2, &QSlider::valueChanged, this, &MainWindow::onSlider2ValueChanged);
    connect(ui->verticalSlider_3, &QSlider::valueChanged, this, &MainWindow::onSlider3ValueChanged);

    esp32.connect("COM5");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//changes to slider 1's value
void MainWindow::onSlider1ValueChanged(int value)
{
    Q_UNUSED(value); // Value is unused here
    updateDegreeLabels(); // Update the labels
    sendAllServoCommands(); // Send updated values to ESP32
}

//changes to slider 2's value
void MainWindow::onSlider2ValueChanged(int value)
{
    Q_UNUSED(value);
    updateDegreeLabels();
    sendAllServoCommands();
}

//changes to slider 3's value
void MainWindow::onSlider3ValueChanged(int value)
{
    Q_UNUSED(value);
    updateDegreeLabels();
    sendAllServoCommands();
}

//sends the current slider values to the ESP32
void MainWindow::sendAllServoCommands()
{
    int value1 = ui->verticalSlider_1->value();
    int value2 = ui->verticalSlider_2->value();
    int value3 = ui->verticalSlider_3->value();

    esp32.sendServoCommand(value1, value2, value3);
}

//changes the degree labels to reflect the current slider values
void MainWindow::updateDegreeLabels()
{
    int value1 = ui->verticalSlider_1->value();
    int value2 = ui->verticalSlider_2->value();
    int value3 = ui->verticalSlider_3->value();

    ui->degree_1->setText(QString::number(value1) + " Degree");
    ui->degree_2->setText(QString::number(value2) + " Degree");
    ui->degree_3->setText(QString::number(value3) + " Degree");
}
