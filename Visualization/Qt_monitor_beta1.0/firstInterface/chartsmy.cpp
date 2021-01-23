#include "chartsmy.h"
QT_CHARTS_BEGIN_NAMESPACE
chartsmy::chartsmy(QObject *parent) : QObject(parent)
{
    chart1 = new QChart();
    series1 = new QLineSeries();
    series2 = new QLineSeries();
    series3 = new QLineSeries();
    series4 = new QLineSeries();

    chart2 = new QChart();
    series11 = new QLineSeries();
    series12 = new QLineSeries();
    series13 = new QLineSeries();
    series14 = new QLineSeries();
    //m_series.append(series1);
    //m_series.append(series2);
    //设置线条名称
    series1->setName(QString("Temperature"));
    series2->setName(QString("Humidity"));
    series3->setName(QString("CO2"));
    series4->setName(QString("Solar"));
    series11->setName(QString("Temperature"));
    series12->setName(QString("Humidity"));
    series13->setName(QString("CO2"));
    series14->setName(QString("Solar"));
    //Deprecated
    //series4->setName(QString("Solar" + QString::number(1)));
    //series->setName(QString("line " + QString::number(m_series.count())));

    //设置线条颜色，如果不设置会给默认颜色
    series1->setColor(QColor(255,0,255));
    series2->setColor(QColor(0,255,255));
    series3->setColor(QColor(255,0,100));
    series4->setColor(QColor(100,0,255));
    series11->setColor(QColor(255,0,255));
    series12->setColor(QColor(0,255,255));
    series13->setColor(QColor(255,0,100));
    series14->setColor(QColor(100,0,255));
    //Deprecated
    //series1->setBrush(QColor(255,0,255));
    //series1->setPen(QColor(255,0,255));
    //设置是否线条可视
    series1->setVisible(true);
    series2->setVisible(true);
    series3->setVisible(true);
    series4->setVisible(true);
    series11->setVisible(true);
    series12->setVisible(true);
    series13->setVisible(true);
    series14->setVisible(true);
    chart1->addSeries(series1);//添加系列到QChart1上
    chart1->addSeries(series2);
    chart1->addSeries(series3);
    chart1->addSeries(series4);
    chart2->addSeries(series11);//添加系列到QChart2上
    chart2->addSeries(series12);
    chart2->addSeries(series13);
    chart2->addSeries(series14);

    //Deprecated
    /*
    //点标签是否可视
    series1->setPointLabelsVisible(false);
    series2->setPointLabelsVisible(false);
    //点标签颜色
    series1->setPointLabelsColor(QColor(255,255,255));
    series2->setPointLabelsColor(QColor(255,255,255));
    //点标签字体
    series1->setPointLabelsFont(QFont("楷体"));
    series2->setPointLabelsFont(QFont("楷体"));
    //设置点标签显示格式
    series1->setPointLabelsFormat("(@xPoint,@yPoint)");
    series2->setPointLabelsFormat("(@xPoint,@yPoint)");
    //是否切割边缘点标签，默认为true
    series1->setPointLabelsClipping(false);
    series2->setPointLabelsClipping(true);
    //设置点标签是否可视
    series1->setPointsVisible(true);
    series2->setPointsVisible(true);
    */
    /*
    for (quint32 i = 0; i < 100; i++) {
        series1->append(i, sin(0.6f*i));
        series2->append(i, sin(0.3f*i));
    }
    */

    //------------------------------------------------------------------
    QDateTimeAxis *axisX=new QDateTimeAxis();
    //QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY_1=new QValueAxis();//temp
    QValueAxis *axisY_2=new QValueAxis();//humi
    QValueAxis *axisY_3=new QValueAxis();//CO2
    QValueAxis *axisY_4=new QValueAxis();//solar
    //设置坐标轴显示的范围

    axisX->setMin(QDateTime::currentDateTime().addSecs(-60*1));
    axisX->setMax(QDateTime::currentDateTime().addSecs(0));
    axisY_1->setMin(0);
    axisY_1->setMax(25);
    axisY_2->setMin(0);
    axisY_2->setMax(100);
    axisY_3->setMin(399);
    axisY_3->setMax(551);
    axisY_4->setMin(0);
    axisY_4->setMax(5.1);
    //设置坐标轴上的格点
    axisY_1->setTickCount(7);
    axisY_2->setTickCount(11);

    //设置坐标轴显示的名称
    axisX->setTitleText("date/time");
    axisY_1->setTitleText("temperature");
    axisY_2->setTitleText("humidity");
    axisY_3->setTitleText("CO2");
    axisY_4->setTitleText("solar");
    //设置坐标轴的颜色，粗细，设置网格不显示
    axisY_1->setLinePenColor(QColor(Qt::darkBlue));
    axisY_1->setGridLineColor(QColor(Qt::darkBlue));
    axisY_2->setLinePenColor(QColor(Qt::darkGreen));
    axisY_2->setGridLineColor(QColor(Qt::darkGreen));
    axisY_1->setGridLineVisible(false);
    axisY_2->setGridLineVisible(false);
    //------------------------------------------------------------------------------------
    QPen penY1(Qt::darkBlue,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    QPen penY2(Qt::darkGreen,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    QPen penY3(Qt::darkRed,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    QPen penY4(Qt::darkCyan,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    axisY_1->setLinePen(penY1);
    axisY_2->setLinePen(penY2);
    axisY_3->setLinePen(penY3);
    axisY_4->setLinePen(penY4);
    //------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------
    axisX->setVisible(true);
    axisY_1->setVisible(true);
    axisY_2->setVisible(true);
    axisY_3->setVisible(true);
    //把坐标轴添加到chart中，
    //addAxis函数的第二个参数是设置坐标轴的位置，
    //只有四个选项，下方：Qt::AlignBottom，左边：Qt::AlignLeft，右边：Qt::AlignRight，上方：Qt::AlignTop
    chart1->addAxis(axisX,Qt::AlignBottom);
    chart1->addAxis(axisY_1,Qt::AlignLeft);
    chart1->addAxis(axisY_2,Qt::AlignRight);
    chart1->addAxis(axisY_3,Qt::AlignLeft);
    chart1->addAxis(axisY_4,Qt::AlignRight);
    //把曲线关联到坐标轴
    series1->attachAxis(axisX);
    series1->attachAxis(axisY_1);
    series2->attachAxis(axisX);
    series2->attachAxis(axisY_2);
    series3->attachAxis(axisX);
    series3->attachAxis(axisY_3);
    series4->attachAxis(axisX);
    series4->attachAxis(axisY_4);

    QDateTimeAxis *axisX1=new QDateTimeAxis();
    QValueAxis *axisY_11=new QValueAxis();//temp
    QValueAxis *axisY_12=new QValueAxis();//humi
    QValueAxis *axisY_13=new QValueAxis();//CO2
    QValueAxis *axisY_14=new QValueAxis();//solar
    axisX1->setMin(QDateTime::currentDateTime().addSecs(-60*1));
    axisX1->setMax(QDateTime::currentDateTime().addSecs(0));
    axisY_11->setMin(0);
    axisY_11->setMax(25);
    axisY_12->setMin(0);
    axisY_12->setMax(100);
    axisY_13->setMin(399);
    axisY_13->setMax(551);
    axisY_14->setMin(0);
    axisY_14->setMax(5.1);
    //设置坐标轴上的格点
    axisY_11->setTickCount(7);
    axisY_12->setTickCount(11);
    axisY_13->setTickCount(7);
    axisY_14->setTickCount(11);
    axisX1->setVisible(false);
    axisY_11->setVisible(false);
    axisY_12->setVisible(false);
    axisY_13->setVisible(false);
    chart2->addAxis(axisX1,Qt::AlignBottom);
    chart2->addAxis(axisY_11,Qt::AlignLeft);
    chart2->addAxis(axisY_12,Qt::AlignRight);
    chart2->addAxis(axisY_13,Qt::AlignLeft);
    chart2->addAxis(axisY_14,Qt::AlignRight);
    series11->attachAxis(axisX1);
    series11->attachAxis(axisY_11);
    series12->attachAxis(axisX1);
    series12->attachAxis(axisY_12);
    series13->attachAxis(axisX1);
    series13->attachAxis(axisY_13);
    series14->attachAxis(axisX1);
    series14->attachAxis(axisY_14);

    chart1->setTheme(QChart::ChartThemeBlueCerulean);//设置系统主题
    chart1->setAnimationOptions(QChart::SeriesAnimations);//设置启用或禁用动画
    chart1->setBackgroundBrush(QBrush(QColor(170,170,255)));//设置背景色,主题和背景二选一
    chart1->setDropShadowEnabled(true);//是否背景阴影
    chart1->setLocalizeNumbers(true);//数字是否本地化
//    chart1->legend()->show();//legend是否显示，show和hide
//    chart1->addSeries(series1);//添加系列到QChart上
//    chart1->addSeries(series2);//添加系列到QChart上
//    chart1->createDefaultAxes();//创建默认轴
    chart1->setTitle("Visual data");//设置标题
    chart1->setTitleBrush(QBrush(QColor(255,170,255)));//设置标题Brush
    chart1->setTitleFont(QFont("宋体"));//设置标题字体
   /*
    chart1->legend()->setVisible(true);
    chart1->legend()->setAlignment(Qt::AlignBottom);//底部对齐
    //chart->legend()->detachFromChart();
    chart1->legend()->setBackgroundVisible(true);//设置背景是否可视
    //chart->legend()->setAutoFillBackground(true);//设置背景自动填充
    //chart->legend()->setColor(QColor(255,128,128,128));//设置颜色
    //chart->legend()->setContentsMargins(10,10,10,10);//设置边距left,top,right,bottom
    chart1->legend()->setLabelColor(QColor(0,128,120));//设置标签颜色
    chart1->legend()->setVisible(true);//设置是否可视
    //chart->legend()->setMaximumHeight(50);
    //chart->legend()->setMaximumWidth(120);
    //chart->legend()->setMaximumSize(10000);
    //chart->legend()->setGeometry(50,50,120,50);//设置几何位置x,y,w,h
    //chart->legend()->setBrush(QBrush(QColor(128,128,128,128)));
    //chart->legend()->setPen(QPen(QColor(192,192, 192,192)));
    chart1->legend()->setBorderColor(QColor(255,255,170,185));//设置边框颜色
//------------------------------------------------------------------------------------------------

    QFont font = chart1->legend()->font();
    font.setItalic(!font.italic());
    chart1->legend()->setFont(font);//设置字体为斜体
    font.setPointSizeF(12);
    chart1->legend()->setFont(font);//设置字体大小
    chart1->legend()->setFont(QFont("华文新魏"));//设置字体类型
    */
//------------------------------------------------------------------------------------------------
    /*
    //添加坐标点
    series1->append(0, 6);
    series1->append(2, 4);
    series1->append(3, 8);
    series1->append(7, 4);
    series1->append(10, 5);
    *series1 << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
    series2->append(0, 8);
    series2->append(2, 5);
    series2->append(3, 3);
    series2->append(7, 9);
    series2->append(10, 2);
    *series2 << QPointF(11, 3) << QPointF(13, 8) << QPointF(17, 2) << QPointF(18, 5) << QPointF(20, 7);
    */
}
void chartsmy::initLine(){

}

void chartsmy::updateLine(float temp, float humi, int co2, float solarV, bool direct){
    //实现画线函数，动态更新
    //每增加一个点改变X轴的范围，实现曲线的动态更新效果
    QDateTime bjtime=QDateTime::currentDateTime();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    chart1->axisX()->setMin(QDateTime::currentDateTime().addSecs(-60*1));
    chart1->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    chart2->axisX()->setMin(QDateTime::currentDateTime().addSecs(-60*1));
    chart2->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));
    //当曲线上最早的点超出X轴的范围时，剔除最早的点，
    if(series1->count()>118){
        series1->removePoints(0,series1->count()-118);
     }
    if(series2->count()>118){
        series2->removePoints(0,series2->count()-118);
    }
    if(series3->count()>118){
        series3->removePoints(0,series3->count()-118);
    }
    if(series4->count()>118){
        series4->removePoints(0,series4->count()-118);
    }

    if(series11->count()>119){
        series11->removePoints(0,series1->count()-119);
     }
    if(series12->count()>119){
        series12->removePoints(0,series2->count()-119);
    }
    if(series13->count()>119){
        series13->removePoints(0,series3->count()-119);
    }
    if(series14->count()>119){
        series14->removePoints(0,series4->count()-119);
    }

    if(direct){
        series1->append(bjtime.toMSecsSinceEpoch(),temp);
        series2->append(bjtime.toMSecsSinceEpoch(),humi);
        series3->append(bjtime.toMSecsSinceEpoch(),co2);
        series4->append(bjtime.toMSecsSinceEpoch(),solarV);
    }
    else{
    series11->append(bjtime.toMSecsSinceEpoch(),temp);
    series12->append(bjtime.toMSecsSinceEpoch(),humi);
    series13->append(bjtime.toMSecsSinceEpoch(),co2);
    series14->append(bjtime.toMSecsSinceEpoch(),solarV);
    //增加新的点到曲线末端
    }
}
QT_CHARTS_END_NAMESPACE
