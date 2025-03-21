#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stopwatch = new Stopwatch(this);
    lapCounter = 0;

    ui->pb_lap->setEnabled(false);
    ui->label_time->setText("0.0");

    connect(stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateTime);
    connect(ui->pb_startStop, &QPushButton::clicked, this, &MainWindow::onStartStopClicked);
    connect(ui->pb_reset, &QPushButton::clicked, this, &MainWindow::onResetClicked);
    connect(ui->pb_lap, &QPushButton::clicked, this, &MainWindow::onLapClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime(double time)
{
    ui->label_time->setText(QString::number(time, 'f', 1));
}

void MainWindow::onStartStopClicked()
{
    if (ui->pb_startStop->text() == "Старт") {
        ui->pb_startStop->setText("Стоп");
        ui->pb_lap->setEnabled(true);
        stopwatch->start();
    } else {
        ui->pb_startStop->setText("Старт");
        ui->pb_lap->setEnabled(false);
        stopwatch->stop();
    }
}

void MainWindow::onResetClicked()
{
    stopwatch->reset();
    ui->label_time->setText("0.0");
    ui->textBrowser->clear();
    lapCounter = 0;
    ui->pb_startStop->setText("Старт");
    ui->pb_lap->setEnabled(false);
}

void MainWindow::onLapClicked()
{
    lapCounter++;
    double lapTime = stopwatch->getLapTime();
    ui->textBrowser->append(QString("Круг %1, время: %2 сек")
    .arg(lapCounter)
    .arg(lapTime, 0, 'f', 1));
}
