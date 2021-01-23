#include "interfacethread.h"

InterfaceThread::InterfaceThread(QObject *parent) : QObject(parent)
{
    m_worker0 = new Worker(0);
    m_worker1 = new Worker(1);
    m_worker2 = new Worker(2);
    m_worker3 = new Worker(3);


    m_worker0->moveToThread(&m_workThread0);
    m_worker1->moveToThread(&m_workThread1);
    m_worker2->moveToThread(&m_workThread2);
    m_worker3->moveToThread(&m_workThread3);

    connect(&m_workThread0, &QThread::finished, m_worker0, &QObject::deleteLater);
    connect(&m_workThread1, &QThread::finished, m_worker1, &QObject::deleteLater);
    connect(&m_workThread2, &QThread::finished, m_worker2, &QObject::deleteLater);
    connect(&m_workThread3, &QThread::finished, m_worker3, &QObject::deleteLater);
 }
void InterfaceThread::startAllTimer(){
    m_worker0->startTimer();
    m_worker1->startTimer();
    m_worker2->startTimer();
    m_worker3->startTimer();
}
InterfaceThread::~InterfaceThread()
{
  m_workThread0.quit();
  m_workThread0.wait();
  m_workThread1.quit();
  m_workThread1.wait();
  m_workThread2.quit();
  m_workThread2.wait();
  m_workThread3.quit();
  m_workThread3.wait();
}

