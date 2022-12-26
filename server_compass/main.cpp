#include <QCoreApplication>
#include "Compass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Compass compass(&a);
    return a.exec();
}
