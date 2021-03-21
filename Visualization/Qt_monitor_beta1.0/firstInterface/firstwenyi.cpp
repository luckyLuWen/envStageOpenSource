#include "firstwenyi.h"
#include "ui_firstwenyi.h"

FirstWenyi::FirstWenyi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FirstWenyi)
{
    ui->setupUi(this);                                  //Generate the layout

    startThread1    = new startThread(this);
    timeTread1      = new QTimer(this);
    startInit();

    ui->labelImage->resize(400 ,400);
    QPixmap pix(":/over.jpg");
    QPixmap dest=pix.scaled(ui->labelImage->size(), Qt::KeepAspectRatioByExpanding);
    ui->labelImage->setPixmap(dest);

    ui->lcdNumber->display("");
    connect(timeTread1, &QTimer::timeout, this, [=]{
#if DEBUG
        //static int num=0;
        //ui->lcdNumber->display(num++);
#endif
    });
    connect(startThread1, &startThread::sigRun, timeTread1, &QTimer::stop);
    connect(startThread1, &startThread::sigRun, this, &FirstWenyi::startToNext);
}

FirstWenyi::~FirstWenyi()
{
    startThread1->quit();
    startThread1->wait();
    delete ui;
}


void FirstWenyi::startInit(){
    timeTread1->start(50);
    startThread1->start();
}

void FirstWenyi::startToNext(){
    //delete itself
    mainWindow1 = new MianWindowsWenyi();
    emit display(10);
    mainWindow1->show();
    this->close();
}

/*
 * QObject::connect
 * You can connect a signal to multiple slots, and when the signal is emitted, the slots will be called in the order in which the contact was declared.
 MyStr  a;
 MyStr  b;
 MyStr  c;
//connect to two slot
 QObject::connect(&a,SIGNAL(valueChanged(QString)),&b,SLOT(setValue(QString)));
 QObject::connect(&a,SIGNAL(valueChanged(QString)),&c,SLOT(setValue(QString)));
 a.setValue("this is A");
//calling in the order——b.setValue()、c.setValue()

*/
/*
MyStr  a;
MyStr  b;
MyStr  c;
//a slot connect to one signal
QObject::connect(&a,SIGNAL(valueChanged(QString)),&c,SLOT(setValue(QString)));
QObject::connect(&b,SIGNAL(valueChanged(QString)),&c,SLOT(setValue(QString)));
//both of following will call c.setValue()
a.setValue("this is A");
b.setValue("this is B");
*/
/*
MyStr  a;
 MyStr  b;
 MyStr  c;
//two siganls connect together
 QObject::connect(&a,SIGNAL(valueChanged(QString)),&b,SIGNAL(valueChanged(QString)));
//the build the connection between b and c
 QObject::connect(&b,SIGNAL(valueChanged(QString)),&c,SLOT(setValue(QString)));
//send the signal a.valueChanged&b.valueChanged synchronous
 a.setValue("this is A");
//so the signal called b.valueChanged was recieved byc.setValue
*/
/*
The connection can be removed
//remove the connection of b and c
  QObject::disconnect(&b,SIGNAL(valueChanged(QString)),&c,SLOT(setValue(QString)));
*/
