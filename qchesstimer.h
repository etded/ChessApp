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

    private:
        QTime time = QTime(0, 10, 0);
        int refreshTime = 1;

    private slots:
        void showTime();
};

#endif // QCHESSTIMER_H
