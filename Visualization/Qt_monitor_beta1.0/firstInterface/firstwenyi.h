#ifndef FIRSTWENYI_H
#define FIRSTWENYI_H

#include <QDialog>
#include <QBitmap>
#include <startthread.h>
#include <QTimer>
#include "mainnwindowswenyi.h"


QT_BEGIN_NAMESPACE
namespace Ui { class FirstWenyi; }
QT_END_NAMESPACE

class FirstWenyi : public QDialog
{
    Q_OBJECT

public:
    FirstWenyi(QWidget *parent = nullptr);
    ~FirstWenyi();
    MianWindowsWenyi *mainWindow1;
signals:
    void display(int num);

private:
    Ui::FirstWenyi *ui;
    //---------------------------------
    startThread *startThread1;
    QTimer * timeTread1;
    //---------------------------------

    void startInit();
    void startToNext();
};
#endif // FIRSTWENYI_H
