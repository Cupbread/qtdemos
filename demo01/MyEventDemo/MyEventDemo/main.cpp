#include "myeventdemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyEventDemo w;
    w.show();
    return a.exec();
}
