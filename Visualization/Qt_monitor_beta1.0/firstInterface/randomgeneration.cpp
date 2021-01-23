#include "randomgeneration.h"

randomGeneration::randomGeneration(QObject *parent) : QObject(parent)
{
     run();
}
void randomGeneration::run(){
    temp = 5+QRandomGenerator::global()->bounded(20.0);
    humi = 20+QRandomGenerator::global()->bounded(19.9);
    co2 = 450+QRandomGenerator::global()->bounded(100);
    solarV = QRandomGenerator::global()->bounded(3.0);
}
