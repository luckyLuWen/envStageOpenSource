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
