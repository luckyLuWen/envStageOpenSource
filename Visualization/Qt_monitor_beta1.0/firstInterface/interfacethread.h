#ifndef INTERFACETHREAD_H
#define INTERFACETHREAD_H
#include <QtCore>
#include <QThread>
#include <QMutex>

#include "Worker.h"        //define a worker
class InterfaceThread : public QObject
{
    Q_OBJECT
public:
    explicit InterfaceThread(QObject *parent = nullptr);

    Worker *m_worker0;
    Worker *m_worker1;
    Worker *m_worker2;
    Worker *m_worker3;

    QThread m_workThread0;
    QThread m_workThread1;
    QThread m_workThread2;
    QThread m_workThread3;
    ~InterfaceThread();
    void startAllTimer();
//protected:
    //void run(); //entrance function -- be started by a singal
};

#endif // INTERFACETHREAD_H
