#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QTcpSocket>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    QTcpSocket* socket;

    return a.exec();
}
