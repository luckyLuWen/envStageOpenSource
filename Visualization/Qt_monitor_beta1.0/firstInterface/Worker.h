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
    //explicit Worker(QObject *parent = nullptr);
    //explicit Worker(QObject *parent = nullptr, int buildnum=0);
    explicit Worker(int =0);

signals:
    void resultReady(const QString &str);
    void returnRandomUserFinal(float, float, int, float, int);// 向外界发送结果

public slots:
    void on_doSomething(); // 耗时操作
    //void startTimer(int buildflag);
    void startTimer();
    void stopTimer();
    //----------------------------------------
    void returnRandomUser();

private:
    //each Worker with a class "randomGeneration" and a class "QTimer", as well as a bool various "status"
    QTimer *randomTimer;
    randomGeneration *randomAll;
    bool status=false;
    int buildnum;
};

#endif // WORKCLASSES_H
