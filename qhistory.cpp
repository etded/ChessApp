#include "qhistory.h"




QHistory::QHistory() : QWidget()
{
    QVBoxLayout *vboxLayout = new QVBoxLayout(this);

    QTableWidget *historyTable = new QTableWidget(this);
    QStringList headerLabels = {"Turn number", "White move", "Black move", "Turn Time"};
    historyTable->setVerticalHeaderLabels(headerLabels);
    historyTable->setColumnCount(4);
    historyTable->setRowCount(10);

    vboxLayout->addWidget(historyTable);
    vboxLayout->addStretch();

    this->setLayout(vboxLayout);
}
