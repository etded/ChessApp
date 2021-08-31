#include "qchessboard.h"




QChessBoard::QChessBoard() : QTableWidget()
{
    setChessBoardSize();

    setChessBoardPolicy();

    setChessBoardBackground();

    setChessBoardNotation();
}

void QChessBoard::setChessBoardBackground()
{
    int i; int j;
    for (i = 0; i < this->nbRows; i++)
    {
        for (j = 0; j < this->nbColumns; j++)
        {
            this->setItem(i, j, new QTableWidgetItem);
            if ((i == 0)  || (j == 0) || (i == this->nbRows-1) || (j == this->nbColumns-1))
            {
                this->item(i, j)->setBackground(QColor(240, 240, 240));
            }
            else if ((i != 0)  && (j != 0) && (i != this->nbRows-1) && (j != this->nbColumns-1) && ((i+j)%2 == 0))
            {
                this->item(i, j)->setBackground(Qt::white);
            }
            else
            {
                this->item(i, j)->setBackground(this->coloredColor);
            }
        }
    }
}

void QChessBoard::setChessBoardPolicy()
{
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setFocusPolicy(Qt::NoFocus);
    this->setSelectionMode(QAbstractItemView::NoSelection);
    this->verticalHeader()->hide();
    this->horizontalHeader()->hide();
}

void QChessBoard::setChessBoardSize()
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

    this->setFixedSize(this->nbRows*this->rowHeight+2*this->frameWidth(), this->nbColumns*this->columnWidth+2*this->frameWidth());
}

void QChessBoard::setChessBoardNotation()
{
    QLabel *label = new QLabel();
    label->setText("0");
    this->setCellWidget(0, 0, label);
}
