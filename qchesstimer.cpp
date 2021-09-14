#include "qchesstimer.h"

QChessTimer::QChessTimer(QWidget *parent) : QLCDNumber(parent)
{
    this->setFixedSize(100, 50);

    refreshTimer = new QTimer();
    connect(refreshTimer, &QTimer::timeout, this, &QChessTimer::updateTime);

    QString text = time.toString("mm:ss");
    display(text);
}

void QChessTimer::updateTime()
{
    if (time.minute() == 0 && time.second() == 0)
    {
        time = QTime(0, 0, 0);
    }
    else
    {
        if (time.second() < refreshTime)
        {
            time = QTime(time.hour(), time.minute() - 1, time.second() + 60 - refreshTime);
        }
        else
        {
            time = QTime(time.hour(), time.minute(), time.second() - refreshTime);
        }
    }
    QString text = time.toString("mm:ss");
    display(text);
}

void QChessTimer::startTimer()
{
    refreshTimer->start(refreshTime*1000);
}

void QChessTimer::pauseTimer()
{
    refreshTimer->stop();
}

void QChessTimer::unpauseTimer()
{
    refreshTimer->start(refreshTime*1000);
}
