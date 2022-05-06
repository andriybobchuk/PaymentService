#include "PaymentServiceWithQt.h"
#include <QtWidgets/QApplication>
#include "database.h"
#include "constants.h"


int main(int argc, char *argv[])
{
    //// Reading the datyabase just ONCE
    //deserialize(DATABASE_FILE, PaymentService::getInstance());

    QApplication a(argc, argv);
    PaymentServiceWithQt w;
    w.show();

    return a.exec();
}
