#ifndef QCHESSBOARD_H
#define QCHESSBOARD_H

#include <QWidget>
#include <QtWidgets>
#include <QtCore>

#include <iostream>

using namespace std;

class QChessBoard : public QTableWidget
{
    Q_OBJECT

    public:
        QChessBoard();
        void setChessBoardBackground();
        void setChessBoardPolicy();
        void setChessBoardSize();
        void setChessBoardNotation();

    private:
        int nbRows = 10;
        int nbColumns = 10;
        int rowHeight = 50;
        int columnWidth = 50;
        QColor coloredColor = Qt::black;
        QColor playerColor = Qt::white;
};

#endif // QCHESSBOARD_H
