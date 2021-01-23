#include "mainnwindowswenyi.h"
//-----------------------------------------------------------------
#include "ui_mainwindowswenyi.h"
//-----------------------------------------------------------------


MianWindowsWenyi::MianWindowsWenyi(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_3->text()="Generate";
    ui->textEdit->setFontPointSize(36);

    ui->textEdit->setText(QString::number(1));
    ui->textEdit->setAlignment(Qt::AlignCenter);
    oneInterface = new InterfaceThread();
    onechartsmy = new chartsmy();
    //----------------------------------------
    ui->chart_view->setChart(onechartsmy->chart1);
    ui->chart_view1->setChart(onechartsmy->chart2);
    //connect(ui->actionNew, &QAction::triggered, this, [=]{
        //button initial
       /* switch(buildnum){
        case 0:{
            thread0 = new InterfaceThread(this);

            thread0->start();
            thread0->buildflag=buildnum+1;
            break;
        }*//*
        case 1:{
             thread1 = new InterfaceThread(this);
             thread1->start();
             thread1->buildflag=buildnum+1;
            break;
        }
        case 2:{
            thread2 = new InterfaceThread(this);
            thread2->start();
            thread2->buildflag=buildnum+1;
            break;
        }*/
//        }
//-------------------------------------------------------
        //buildnum++;
        //buildflag=buildnum;

        //randomTimer = new QTimer(this);
        //randomTimer << new QTimer(this);
        //randomTimer.append(new QTimer(this));
        //randomTimer[0]->stop();
        //randomTimer[0]->setInterval(500);//0.5s
    //}
//);
    //connect function can ignore the performed order
    //connect(randomTimer, &Worker::returnRandomUserFinal, this, &MianWindowsWenyi::randomFinal);


//    void (MianWindowsWenyi::*pointerParastop)(int ) = &MianWindowsWenyi::buildFlagstop;

    void (MianWindowsWenyi::*pointerPara)() = &MianWindowsWenyi::buildFlagchange;
    connect(this, pointerPara ,oneInterface->m_worker0, &Worker::startTimer);
    connect(this, pointerPara ,oneInterface->m_worker1, &Worker::startTimer);
    connect(this, pointerPara ,oneInterface->m_worker2, &Worker::startTimer);
    connect(this, pointerPara ,oneInterface->m_worker3, &Worker::startTimer);
    //connect(this, pointerPara ,oneInterface, &InterfaceThread::startAllTimer);

    pointerPara = &MianWindowsWenyi::buildFlagstop;
    connect(this, pointerPara ,oneInterface->m_worker0, &Worker::stopTimer);
    connect(this, pointerPara ,oneInterface->m_worker1, &Worker::stopTimer);
    connect(this, pointerPara ,oneInterface->m_worker2, &Worker::stopTimer);
    connect(this, pointerPara ,oneInterface->m_worker3, &Worker::stopTimer);

    connect(oneInterface->m_worker0, &Worker::returnRandomUserFinal, this, &MianWindowsWenyi::randomFinal);
    connect(oneInterface->m_worker1, &Worker::returnRandomUserFinal, this, &MianWindowsWenyi::randomFinal);
    connect(oneInterface->m_worker2, &Worker::returnRandomUserFinal, this, &MianWindowsWenyi::randomFinal);
    connect(oneInterface->m_worker3, &Worker::returnRandomUserFinal, this, &MianWindowsWenyi::randomFinal);

    //connect to chart showing
    connect(this, &MianWindowsWenyi::chartsShot, onechartsmy, &chartsmy::updateLine);
    //start the threads
    oneInterface->m_workThread0.start();
    oneInterface->m_workThread1.start();
    oneInterface->m_workThread2.start();
    oneInterface->m_workThread3.start();

//    connect(thread1, &InterfaceThread::returnRandomUserFinal, this, [=](float temp, float humi, int co2, float solarV, int buildflag){
//            ui->lcdNumber->display(temp);
//            ui->lcdNumber_2->display(humi);
//            ui->lcdNumber_3->display(co2);
//            ui->lcdNumber_4->display(solarV);
//            ui->textEdit->setMarkdown(QString::number(buildflag));
//        });
//    connect(thread2, &InterfaceThread::returnRandomUserFinal, this, [=](float temp, float humi, int co2, float solarV, int buildflag){
//            ui->lcdNumber->display(temp);
//            ui->lcdNumber_2->display(humi);
//            ui->lcdNumber_3->display(co2);
//            ui->lcdNumber_4->display(solarV);
//            ui->textEdit->setMarkdown(QString::number(buildflag));
//        });
}


void MianWindowsWenyi::showMainWindow(int num){
    if (num==10)
        this->show();
    num=0;
}

void MianWindowsWenyi::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->text()=="Generate")
    {
        ui->pushButton_3->setText("stop");
        //randomTimer[0]->start();//1st version
        emit(buildFlagchange());
        //qDebug()<<"buildFlagchange\n";
    }
    else
    {
        ui->pushButton_3->setText("Generate");
        emit(buildFlagstop());
    }
}

void MianWindowsWenyi::randomFinal(float temp, float humi, int co2, float solarV, int buildflag){

    //qDebug()<<ui->textEdit->toMarkdown();
    QString a(ui->textEdit->toMarkdown()[0]);
    int b = a.toInt();
    if(direct)
    {
        if(buildflag==b)
        {
            ui->lcdNumber->display(temp);
            ui->lcdNumber_2->display(humi);
            ui->lcdNumber_3->display(co2);
            ui->lcdNumber_4->display(solarV);
            ui->textEdit->setFontPointSize(36);
            //ui->textEdit->setMarkdown(QString::number(buildflag));
            ui->textEdit->setText(QString::number(buildflag));
            ui->textEdit->setAlignment(Qt::AlignCenter);
            //onechartsmy->updateLine(temp, humi, co2, solarV, buildflag, );
            emit(chartsShot(temp, humi, co2, solarV, true));
            qDebug()<<"buildflag_true: "<<buildflag;
        }
        if(b==0)
        {
            if(buildflag==3){
                emit(chartsShot(temp, humi, co2, solarV, false));
                qDebug()<<"buildflag_true_other: "<<buildflag;
            }
        }
        else{
            if(buildflag==b-1)
            {
                emit(chartsShot(temp, humi, co2, solarV, false));
                qDebug()<<"buildflag_true_other: "<<b-1;
            }
        }
    }
    else{
        if(buildflag==b)
        {
            ui->lcdNumber->display(temp);
            ui->lcdNumber_2->display(humi);
            ui->lcdNumber_3->display(co2);
            ui->lcdNumber_4->display(solarV);
            ui->textEdit->setFontPointSize(36);
            //ui->textEdit->setMarkdown(QString::number(buildflag));
            ui->textEdit->setText(QString::number(buildflag));
            ui->textEdit->setAlignment(Qt::AlignCenter);
            //onechartsmy->updateLine(temp, humi, co2, solarV, buildflag, );
            emit(chartsShot(temp, humi, co2, solarV, true));
            qDebug()<<"buildflag_false: "<<buildflag;
        }
        if(b==3)
        {
            if(buildflag==0)
            {
                emit(chartsShot(temp, humi, co2, solarV, false));
                qDebug()<<"buildflag_false_other: "<<buildflag;
            }
        }
        else{
            if(buildflag==b+1)
            {
                emit(chartsShot(temp, humi, co2, solarV, false));
                qDebug()<<"buildflag_false_other: "<<b+1;
            }
        }


    }
}
MianWindowsWenyi::~MianWindowsWenyi()
{
    //qDeleteAll(randomTimer);
    delete ui;
}

void MianWindowsWenyi::on_pushButton_clicked()
{
    direct = false;
    QString a(ui->textEdit->toMarkdown()[0]);
    int b = a.toInt();
    //qDebug()<<"Markdown: "<<b;
    ui->textEdit->setFontPointSize(36);
    switch(b){
    case 0:
        ui->textEdit->setText(QString::number(b+3));
        break;
    case 1:
        ui->textEdit->setText(QString::number(b-1));
        break;
    case 2:
        ui->textEdit->setText(QString::number(b-1));
        break;
    case 3:
        ui->textEdit->setText(QString::number(b-1));
        break;
    default:
        break;
    }
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MianWindowsWenyi::on_pushButton_2_clicked()
{
    direct = true;
    QString a(ui->textEdit->toMarkdown()[0]);
    int b = a.toInt();
    //qDebug()<<"Markdown: "<<b;
    ui->textEdit->setFontPointSize(36);
    switch(b){
    case 0:
        ui->textEdit->setText(QString::number(b+1));
        break;
    case 1:
        ui->textEdit->setText(QString::number(b+1));
        break;
    case 2:
        ui->textEdit->setText(QString::number(b+1));
        break;
    case 3:
        ui->textEdit->setText(QString::number(b-3));
        break;
    default:
        break;
    }
    ui->textEdit->setAlignment(Qt::AlignCenter);
}
