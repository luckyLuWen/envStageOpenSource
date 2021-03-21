#ifndef FIRSTWENYI_H
#define FIRSTWENYI_H

#include <QDialog>
#include <QBitmap>
#include <QTimer>

#include "startthread.h"
#include "mainnwindowswenyi.h"
QT_BEGIN_NAMESPACE
namespace Ui { class FirstWenyi; }
QT_END_NAMESPACE

class FirstWenyi : public QDialog
{
    Q_OBJECT//It can be used for invoke signal & slot function

public:
    FirstWenyi(QWidget *parent = nullptr);         //Structure function
    ~FirstWenyi();                                                  //The destructor
    MianWindowsWenyi *mainWindow1;
signals:
    void display(int num);

private:
    Ui::FirstWenyi *ui;
    QTimer * timeTread1;            //Define pointer, need the "new"
    startThread *startThread1;      //Define pointer, need the "new"
    void startInit();
    void startToNext();
};
#endif // FIRSTWENYI_H
