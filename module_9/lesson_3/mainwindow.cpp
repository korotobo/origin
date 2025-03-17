#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    connectButton = new QPushButton("Подключиться к БД", this);
    layout->addWidget(connectButton);

    dbDialog = new Dialog(this);

    connect(connectButton, &QPushButton::clicked,
            this, &MainWindow::showDatabaseDialog);
}

void MainWindow::showDatabaseDialog()
{
    dbDialog->exec();
}

MainWindow::~MainWindow()
{
}
