#include "teachingboard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TeachingBoard w;
    w.showMaximized();
    w.show();
    return a.exec();
}
