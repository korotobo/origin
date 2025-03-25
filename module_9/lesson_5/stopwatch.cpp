#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    currentTime = 0.0;
    lastLapTime = 0.0;
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &Stopwatch::updateTime);
}

void Stopwatch::start()
{
    timer->start();
}

void Stopwatch::stop()
{
    timer->stop();
}

void Stopwatch::reset()
{
    timer->stop();
    currentTime = 0.0;
    lastLapTime = 0.0;
}

void Stopwatch::resetTimeOnly()
{
    currentTime = 0.0;
    lastLapTime = 0.0;
}

double Stopwatch::getLapTime()
{
    double lapTime = currentTime - lastLapTime;
    lastLapTime = currentTime;
    return lapTime;
}

void Stopwatch::updateTime()
{
    currentTime += 0.1;
    emit timeUpdated(currentTime);
}
