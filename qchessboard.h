#ifndef QCHESSBOARD_H
#define QCHESSBOARD_H

#include <QWidget>
#include <QtWidgets>
#include <QtCore>

#include <iostream>
#include "qvector_functions.h"

using namespace std;

class QChessBoard : public QTableWidget
{
    Q_OBJECT

    public:
        explicit QChessBoard(QWidget *parent = nullptr);
        void openColorDialog();
        void initializeBoardCells();
        void setChessBoardColor(QColor);
        void setChessBoardPolicy();
        void setChessBoardSize();
        void setChessBoardNotation();
        void setChessBoardPieces();
        void setPlayerColor(QColor);
        void playChessGame();
        void setChessBoardItemSelectionColor(QColor);
        void computePossibleMoves(QTableWidgetItem*);
        void resetMovesCellColor();
        QVector<QVector<int>> test();
        QColor getPlayerColor();
        QColor getPieceColor(QTableWidgetItem*);

    public slots:
        void movePiece(QTableWidgetItem*);
        void movePieceTo();
        void assignNextTurnColor();
        void showPossibleMoves(QTableWidgetItem*);

    signals:
        void movePieceSignal();
        void showPossibleMovesSignal(QTableWidgetItem*);

    private:
        int nbRows;
        int nbColumns;
        int rowHeight;
        int columnWidth;
        QColor coloredColor;
        QColor playerColor;
        QColor turnColor;
        QVector<QVector<int>> possibleMoves;
        QTableWidgetItem *pieceToMove;
        QTableWidgetItem *location;
        int clickCounter;
};

#endif // QCHESSBOARD_H
