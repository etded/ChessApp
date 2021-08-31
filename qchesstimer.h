#ifndef QCHESSTIMER_H
#define QCHESSTIMER_H

#include <QWidget>
#include <QtWidgets>

#include <iostream>

using namespace std;

class QChessTimer : public QLCDNumber
{
    public:
        QChessTimer();
        void setChessTimerSize();

    private:
        QTime time = QTime(0, 1, 10);
        int refreshTime = 1;

    private slots:
        void showTime();
};

#endif // QCHESSTIMER_H
