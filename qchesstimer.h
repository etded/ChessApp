#ifndef QCHESSTIMER_H
#define QCHESSTIMER_H

#include <QWidget>
#include <QtWidgets>
#include <QtCore>

#include <iostream>

using namespace std;

class QChessTimer : public QLCDNumber
{
    public:
        QChessTimer(QWidget *parent = nullptr);
        void startTimer();
        void pauseTimer();
        void unpauseTimer();

    private:
        QTime time = QTime(0, 10, 0);
        QTimer *refreshTimer;
        int refreshTime = 1;

    private slots:
        void updateTime();

};

#endif // QCHESSTIMER_H
