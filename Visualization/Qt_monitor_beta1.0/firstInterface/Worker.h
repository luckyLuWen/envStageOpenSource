
#ifndef WORKER_H
#define WORKER_H
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTimer>

#include "randomgeneration.h"
class Worker : public QObject
{
  Q_OBJECT
public:
    explicit Worker(int =0);

signals:
    void resultReady(const QString &str);
    void returnRandomUserFinal(float, float, int, float, int);// Send the results to the outside

public slots:
    void on_doSomething(); // The long-running
    //Operation of  Timer
    void startTimer();
    void stopTimer();
    //Operation of Random
    void returnRandomUser();

private:
    //each Worker with a class "randomGeneration" and a class "QTimer", as well as a bool various "status"
    QTimer *randomTimer;
    randomGeneration *randomAll;
    bool status=false;
    int buildnum;   //This is also denoted as Worker Number.
};

#endif // WORKCLASSES_H
