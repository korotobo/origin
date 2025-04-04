#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch;
    int lapCounter;

private slots:
    void updateTime(double time);
    void onStartStopClicked();
    void onResetClicked();
    void onLapClicked();
};

#endif // MAINWINDOW_H
