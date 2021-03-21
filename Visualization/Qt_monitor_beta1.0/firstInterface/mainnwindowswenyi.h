#ifndef MIANWINDOWSWENYI_H
#define MIANWINDOWSWENYI_H

#include <QMainWindow>//it has a class "ui" dialog and widget also already have
#include <QTimer>
#include <QString>
#include <QtDebug>
#include <QDateTime>
#include "interfacethread.h"
#include "chartsmy.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }//same name as class MianWindowsWenyi

QT_CHARTS_USE_NAMESPACE
QT_END_NAMESPACE

class MianWindowsWenyi : public QMainWindow
{
    Q_OBJECT
public:
    explicit MianWindowsWenyi(QWidget *parent = nullptr);
    ~MianWindowsWenyi();
    int buildnum=4;       //create 4 timers
    int buildflag=0;        //current timer flag
    bool direct = true;    //true — left side
signals:
   void buildFlagchange();
   void buildFlagstop();
   void chartsShot(float, float, int, float, bool);
public slots:
    void on_pushButton_3_clicked();
    void randomFinal(float, float, int, float, int);//function: receive the return values

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    //void showMainWindow(int num);
    InterfaceThread *oneInterface;
    chartsmy *onechartsmy;
    QDateTime *RealTime;
    QTimer * RealTimer;
};

#endif // MIANWINDOWSWENYI_H
