#ifndef STARTTHREAD_H
#define STARTTHREAD_H

//#include <QObject>
#include <QThread>

class startThread : public QThread
{
    Q_OBJECT
public:
    explicit startThread(QObject *parent = nullptr);
    ~startThread();
protected://run is vitural function , can be called by method/methodology: start()
    void run(); //entrance function -- be started by a singal
signals:
    void sigRun();
//slots:
    //void slotRun();
};

#endif // STARTTHREAD_H
