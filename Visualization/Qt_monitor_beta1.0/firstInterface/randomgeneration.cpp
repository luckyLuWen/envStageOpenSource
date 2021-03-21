#include "randomgeneration.h"

randomGeneration::randomGeneration(QObject *parent, int buildnum) : QObject(parent)
{
     run(buildnum);
}
void randomGeneration::run(int buildnum){
    switch (buildnum%4) {
        case 0:
            temp    = 5+  QRandomGenerator::global()->bounded(20.0);        //5.0  - 25.0
            humi    = 20+QRandomGenerator::global()->bounded(19.9);     //20.0 - 49.9
            co2      = 450+QRandomGenerator::global()->bounded(100);      // 450 - 550
            solarV =    QRandomGenerator::global()->bounded(3.0);          // 0 - 3.0
        break;
        case 1:
            temp = 0+QRandomGenerator::global()->bounded(5.0);        //0 - 5.0
            humi = 0+QRandomGenerator::global()->bounded(19.9);      //0 - 19.9
            co2 = 350+QRandomGenerator::global()->bounded(100);     //350 - 450
            solarV = QRandomGenerator::global()->bounded(1.0);         //0 - 1.0
        break;
        case 2:
            temp = 5+QRandomGenerator::global()->bounded(5.0);      //5.0 - 10.0
            humi = 0+QRandomGenerator::global()->bounded(39.9);    //0 - 39.9
            co2   = 250+QRandomGenerator::global()->bounded(100);    //250 - 350
            solarV = QRandomGenerator::global()->bounded(0.5);        // 0 - 0.5
        break;
        case 3:
            temp = 10+QRandomGenerator::global()->bounded(30.0);        //10.0 - 40.0
            humi = 0+QRandomGenerator::global()->bounded(99.9);         //0 - 99.9
            co2 = 300+QRandomGenerator::global()->bounded(200);        //300 - 500
            solarV = 0.5+ QRandomGenerator::global()->bounded(3.0);            // 0.5 - 3.5
        break;
    }

}
