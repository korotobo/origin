#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    void resetTimeOnly();
    double getLapTime();

signals:
    void timeUpdated(double time);

private:
    QTimer *timer;
    double currentTime;
    double lastLapTime;

private slots:
    void updateTime();
};

#endif // STOPWATCH_H
