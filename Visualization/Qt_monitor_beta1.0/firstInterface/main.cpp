#include "firstwenyi.h"

#include <QApplication>
#include <QObject>
int main(int argc, char *argv[])
{
    /*
     *  Some modification for testing my git commands
    */
    QApplication a(argc, argv);
    FirstWenyi w;
    w.show();
    return a.exec();
}
/*
 * public、protected&private - inheritance:
 * https://blog.csdn.net/lqk1985/article/details/4791293?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control&dist_request_id=1328680.39597.16163147854437703&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control
 * QT annoying parent how to understand:
 * https://blog.csdn.net/qq_41598072/article/details/82863281
 * QT namespace UI:
 * https://blog.csdn.net/hebbely/article/details/79267348
*/
