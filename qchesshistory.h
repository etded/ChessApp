#ifndef QCHESSHISTORY_H
#define QCHESSHISTORY_H

#include <QWidget>
#include <QtWidgets>

#include <iostream>

using namespace std;

class QChessHistory : public QTableWidget
{
    Q_OBJECT

    public:
        QChessHistory(QWidget *parent = nullptr);
        void setChessHistoryPolicy();
        void setChessHistorySize();

    private:
        QStringList headerLabels;
        int nbRows = 10;
        int nbColumns = 3;
        int rowHeight = 30;
        int columnWidth = 75;
};

#endif // QCHESSHISTORY_H
