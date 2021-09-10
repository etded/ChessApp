#include "qchesstimer.h"

QChessTimer::QChessTimer(QWidget *parent) : QLCDNumber(parent)
{
    this->setFixedSize(100, 50);

    QTimer *refreshTimer = new QTimer();
    connect(refreshTimer, &QTimer::timeout, this, &QChessTimer::showTime);
    refreshTimer->start(refreshTime*1000);
}

void QChessTimer::showTime()
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
