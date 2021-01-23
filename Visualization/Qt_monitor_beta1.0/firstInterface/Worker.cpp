#include "Worker.h"

//extern MianWindowsWenyi *mainWindow1;
/*
Worker::Worker(QObject *parent) : QObject(parent)
{
    randomTimer = new QTimer(this);
    randomAll = new randomGeneration(this);
    randomTimer->stop();
    randomTimer->setInterval(200);//200ms
    //if(status)
    //{
    //    randomAll->run();//continue to generate the random values
    //}
    //emit returnRandom(temp, humi, co2, solarV);
    connect(randomTimer, &QTimer::timeout, this, &Worker::returnRandomUser);
    connect(this, &Worker::returnRandomUserFinal, mainWindow1, &MianWindowsWenyi::randomFinal);
}
*/
Worker::Worker(int buildnum) : buildnum(buildnum)
{
    randomTimer = new QTimer(this);
    randomAll = new randomGeneration(this);
    randomTimer->stop();
    randomTimer->setInterval(500);//500ms

    connect(randomTimer, &QTimer::timeout, this, &Worker::returnRandomUser);
    //connect(this, &Worker::returnRandomUserFinal, mainWindow1, &MianWindowsWenyi::randomFinal);
}
//----------------------
void Worker::on_doSomething()
{
  qDebug() << "I'm working in thread:" << QThread::currentThreadId();
  emit resultReady("Hello");
}
/*
void Worker::startTimer(int buildflag){
    randomTimer->start();
    this->buildnum=buildflag;
}
*/
void Worker::startTimer(){
    randomTimer->start();
}
/*
void Worker::stopTimer(){
    randomTimer->stop();
    this->buildnum=buildflag;
}
*/
void Worker::stopTimer(){
    randomTimer->stop();
}
void Worker::returnRandomUser(){
    randomAll->run();
    emit(returnRandomUserFinal(randomAll->temp,
                               randomAll->humi,
                               randomAll->co2,
                               randomAll->solarV, this->buildnum));
}
