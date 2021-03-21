#include "Worker.h"

Worker::Worker(int buildnum) : buildnum(buildnum)
{
    randomAll           = new randomGeneration(this, buildnum);

    randomTimer      = new QTimer(this);
    randomTimer->stop();
    randomTimer->setInterval(500);//500ms
    //bind the function called [returnRandomUser] to timeout of A TIMER
    connect(randomTimer, &QTimer::timeout, this, &Worker::returnRandomUser);
}

void Worker::on_doSomething()
{
  qDebug() << "I'm working in thread:" << QThread::currentThreadId();
  emit resultReady("Hello");
}

void Worker::startTimer(){
    randomTimer->start();
}

void Worker::stopTimer(){
    randomTimer->stop();
}

void Worker::returnRandomUser(){
    randomAll->run(buildnum);
    emit(returnRandomUserFinal(randomAll->temp,
                               randomAll->humi,
                               randomAll->co2,
                               randomAll->solarV, this->buildnum));
}
