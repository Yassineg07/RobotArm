#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect sliders to their respective slots
    connect(ui->verticalSlider_1, &QSlider::valueChanged, this, &MainWindow::onSlider1ValueChanged);
    connect(ui->verticalSlider_2, &QSlider::valueChanged, this, &MainWindow::onSlider2ValueChanged);
    connect(ui->verticalSlider_3, &QSlider::valueChanged, this, &MainWindow::onSlider3ValueChanged);

    // Initialize ESP32 connection
    esp32.connect("COM5");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSlider1ValueChanged(int value)
{
    Q_UNUSED(value);
    updateDegreeLabels();
    sendAllServoCommands();
}

void MainWindow::onSlider2ValueChanged(int value)
{
    Q_UNUSED(value);
    updateDegreeLabels();
    sendAllServoCommands();
}

void MainWindow::onSlider3ValueChanged(int value)
{
    Q_UNUSED(value);
    updateDegreeLabels();
    sendAllServoCommands();
}

void MainWindow::sendAllServoCommands()
{
    int value1 = ui->verticalSlider_1->value();
    int value2 = ui->verticalSlider_2->value();
    int value3 = ui->verticalSlider_3->value();

    esp32.sendServoCommand(1, value1);
    esp32.sendServoCommand(2, value2);
    esp32.sendServoCommand(3, value3);
}

void MainWindow::updateDegreeLabels()
{
    int value1 = ui->verticalSlider_1->value();
    int value2 = ui->verticalSlider_2->value();
    int value3 = ui->verticalSlider_3->value();

    ui->degree_1->setText(QString::number(value1) + " Degree");
    ui->degree_2->setText(QString::number(value2) + " Degree");
    ui->degree_3->setText(QString::number(value3) + " Degree");
}
