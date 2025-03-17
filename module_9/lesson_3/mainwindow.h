#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showDatabaseDialog();

private:
    Dialog *dbDialog;
    QPushButton *connectButton;
};

#endif // MAINWINDOW_H
