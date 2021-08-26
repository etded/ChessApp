#ifndef QHISTORY_H
#define QHISTORY_H

#include <QWidget>
#include <QtWidgets>

class QHistory : public QWidget
{
    Q_OBJECT

    public:
        QHistory();

    private:
        QTableWidget *historyTable;
        QStringList headerLabels;
};

#endif // QHISTORY_H
