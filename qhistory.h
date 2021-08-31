#ifndef QHISTORY_H
#define QHISTORY_H

#include <QWidget>
#include <QtWidgets>

#include <iostream>

using namespace std;

class QHistory : public QTableWidget
{
    Q_OBJECT

    public:
        QHistory();
        void setHistoryPolicy();
        void setHistorySize();

    private:
        QStringList headerLabels;
        int nbRows = 10;
        int nbColumns = 3;
        int rowHeight = 30;
        int columnWidth = 75;
};

#endif // QHISTORY_H
