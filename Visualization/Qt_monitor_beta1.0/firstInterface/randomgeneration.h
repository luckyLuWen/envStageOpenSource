#ifndef RANDOMGENERATION_H
#define RANDOMGENERATION_H

#include <QObject>
#include <QRandomGenerator>//This class was introduced in Qt 5.10.
class randomGeneration : public QObject
{
    Q_OBJECT
public:
    explicit randomGeneration(QObject *parent = nullptr);
    float temp, humi, solarV=0.0;
    int co2=0;
    void run();
    /*
public slots://defined slot
    void run();

signals:
    void returnRandom(float, float, int, float);
    */
};

#endif // RANDOMGENERATION_H
