#ifndef ESP32_H
#define ESP32_H

#include <QString>
#include <QSerialPort>

class ESP32
{
public:
    ESP32();
    ~ESP32();

    bool connect(const QString &portName);
    void sendServoCommand(int servoId, int angle);

private:
    QSerialPort serial;
};

#endif // ESP32_H
