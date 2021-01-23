#ifndef CHARTSMY_H
#define CHARTSMY_H
/*
1. QSplineSeries: 用于创建有由一系列数据组成的曲线.类似的还有
    QPieSeries(饼图数据).
    QLineSeries:(折线数据).
-----------------------------------------------------------------
2. QChart: 图表界面,用来管理图表内容,颜色,大小等
3. QChartView: 负责显示QChart
*/
#include <QObject>
#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QSplineSeries>
#include <QDateTime>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QRandomGenerator>
QT_CHARTS_BEGIN_NAMESPACE
QT_CHARTS_USE_NAMESPACE

class chartsmy:public QObject
{
    Q_OBJECT
public:
    explicit chartsmy(QObject *parent = nullptr);
    void updateLine(float temp, float humi, int co2, float solarV, bool direct);
    void initLine();
    QChart* chart1;
    QChart* chart2;

private:
    QList<QLineSeries *> m_series;
    QLineSeries *series1;
    QLineSeries *series2;
    QLineSeries *series3;
    QLineSeries *series4;

    QLineSeries *series11;
    QLineSeries *series12;
    QLineSeries *series13;
    QLineSeries *series14;
};
QT_CHARTS_END_NAMESPACE
#endif // CHARTSMY_H
