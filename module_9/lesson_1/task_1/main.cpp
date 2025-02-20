#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMessageBox msg;

    msg.setText("Hello, Graphic world!!!");
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowTitle("First app");
    msg.show();

    int x = 0;
    qDebug() << x;
    ++x;
    qDebug() << x;
    // MainWindow w;
    // w.show();
    return a.exec();
}
