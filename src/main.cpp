#include "DoubleWindowContainer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DoubleWindowContainer w;
    w.show();
    return a.exec();
}
