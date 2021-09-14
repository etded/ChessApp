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
        QColor getPlayerColor();
        QColor getPieceColor(QTableWidgetItem*);

    public slots:
        void movePiece(QTableWidgetItem*);
        void movePieceTo();
        void assignNextTurnColor();

    signals:
        void movePieceSignal();

    private:
        int nbRows;
        int nbColumns;
        int rowHeight;
        int columnWidth;
        QColor coloredColor;
        QColor playerColor;
        QColor turnColor;
        QTableWidgetItem *pieceToMove;
        QTableWidgetItem *location;
        int clickCounter;
};

#endif // QCHESSBOARD_H
