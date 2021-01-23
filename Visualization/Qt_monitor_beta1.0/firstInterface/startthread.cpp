#include "startthread.h"

startThread::startThread(QObject *parent) : QThread(parent)
{

}
startThread::~startThread(){

}

void startThread::run()
{
    //This is a complex operation/performance
    sleep(1);
//    for(long int i=0;i<100000;i++)
//        for(int j=0;j<10000;j++);
    emit sigRun();
}
