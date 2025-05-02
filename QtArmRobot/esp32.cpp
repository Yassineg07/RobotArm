#include "esp32.h"
#include <QSerialPortInfo>
#include <QDebug>

ESP32::ESP32()
{
}

ESP32::~ESP32()
{
    if (serial.isOpen()) {
        serial.close();
    }
}

bool ESP32::connect(const QString &portName)
{
    serial.setPortName(portName);
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if (!serial.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open port" << portName;
        return false;
    }

    qDebug() << "Connected to ESP32 on port" << portName;
    return true;
}

void ESP32::sendServoCommand(int angle1, int angle2, int angle3)
{
    if (serial.isOpen()) {
        QString command = QString("%1 %2 %3\n").arg(angle1).arg(angle2).arg(angle3);
        serial.write(command.toUtf8());
        serial.flush();

        qDebug() << "Sent values to ESP32:" << angle1 << angle2 << angle3;
    } else {
        qDebug() << "Serial port not open. Cannot send command.";
    }
}
