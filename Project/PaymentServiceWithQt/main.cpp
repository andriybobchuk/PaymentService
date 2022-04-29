#include "PaymentServiceWithQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaymentServiceWithQt w;
    w.show();
    return a.exec();
}
