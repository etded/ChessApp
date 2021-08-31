#include "qhistory.h"




QHistory::QHistory() : QTableWidget()
{
    setHistoryPolicy();
    setHistorySize();

    QStringList headerLabels = {"White move", "Black move", "Turn Time"};
    this->setHorizontalHeaderLabels(headerLabels);
}

void QHistory::setHistoryPolicy()
{
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setFocusPolicy(Qt::NoFocus);
    this->setSelectionMode(QAbstractItemView::NoSelection);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void QHistory::setHistorySize()
{
    this->setColumnCount(this->nbColumns);
    this->setRowCount(this->nbRows);
    int i;
    for (i = 0; i < this->nbRows; i++)
    {
        this->setRowHeight(i, this->rowHeight);
    }
    for (i = 0; i < nbColumns; i++)
    {
        this->setColumnWidth(i, this->columnWidth);
    }
    this->verticalHeader()->setFixedWidth(this->columnWidth);
    this->horizontalHeader()->setFixedHeight(this->rowHeight);
    this->setFixedSize(this->nbColumns*this->columnWidth+2*this->frameWidth()+this->columnWidth, this->nbRows*this->rowHeight+2*this->frameWidth()+this->rowHeight);
}
