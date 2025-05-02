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

void ESP32::sendServoCommand(int servoId, int angle)
{
    if (serial.isOpen()) {
        QString command = QString("SERVO:%1:%2\n").arg(servoId).arg(angle);
        serial.write(command.toUtf8());
        serial.flush();
    } else {
        qDebug() << "Serial port not open. Cannot send command.";
    }
}
