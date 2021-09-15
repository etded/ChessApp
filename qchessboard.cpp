#include "qchessboard.h"




QChessBoard::QChessBoard(QWidget *parent) : QTableWidget(parent)
{
    nbRows = 10;
    nbColumns = 10;
    columnWidth = 50;
    rowHeight = 50;
    coloredColor = Qt::black;
    playerColor = Qt::white;
    turnColor = Qt::white;
    clickCounter = 0;

    setChessBoardSize();

    initializeBoardCells();

    setChessBoardPolicy();

    setChessBoardColor(coloredColor);

    setChessBoardItemSelectionColor(coloredColor);

    setChessBoardNotation();

    setChessBoardPieces();

}

void QChessBoard::initializeBoardCells()
{
    int i; int j;
    for (i = 0; i < this->nbRows; i++)
    {
        for (j = 0; j < this->nbColumns; j++)
        {
            this->setItem(i, j, new QTableWidgetItem);
            this->item(i, j)->setText("");
        }
    }
}

void QChessBoard::setChessBoardColor(QColor boardColor)
{
    int i; int j;
    for (i = 0; i < this->nbRows; i++)
    {
        for (j = 0; j < this->nbColumns; j++)
        {
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
                this->item(i, j)->setBackground(QColor(boardColor.red(), boardColor.green(), boardColor.blue(), 127));
            }
        }
    }
}

void QChessBoard::openColorDialog()
{
    QColor color;
    color = QColorDialog::getColor(Qt::black, this);
    this->coloredColor = color;
    this->setChessBoardColor(color);
    this->setChessBoardItemSelectionColor(color);
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
    int i;
    this->setColumnCount(this->nbColumns);
    this->setRowCount(this->nbRows);

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
    int i; int j;
    QList<QString> horizontalNotation;
    QList<QString> verticalNotation;
    if (playerColor == Qt::white)
    {
        horizontalNotation = {"", "A", "B", "C", "D", "E", "F", "G", "H", ""};
        verticalNotation = {"", "8", "7", "6", "5", "4", "3", "2", "1", ""};
    }
    else if (playerColor == Qt::black)
    {
        horizontalNotation = {"", "H", "G", "F", "E", "D", "C", "B", "A", ""};
        verticalNotation = {"", "1", "2", "3", "4", "5", "6", "7", "8", ""};
    }
    for (i = 0; i < this->nbRows; i++)
    {
        for (j = 0; j < this->nbColumns; j++)
        {
            if ((i == 0)  || (i == this->nbRows-1))
            {
                this->item(i, j)->setText(horizontalNotation.value(j));
                this->item(i, j)->setTextAlignment(Qt::AlignCenter);
            }
            else if ((j == 0) || (j == this->nbColumns-1))
            {
                this->item(i, j)->setText(verticalNotation.value(i));
                this->item(i, j)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
}

void QChessBoard::setChessBoardPieces()
{
    int i; int j;
    QString blackPawn; QString blackKnight; QString blackBishop; QString blackRook; QString blackQueen; QString blackKing;
    QString whitePawn; QString whiteKnight; QString whiteBishop; QString whiteRook; QString whiteQueen; QString whiteKing;
    blackPawn = "♟"; blackKnight = "♞"; blackBishop = "♝"; blackRook = "♜"; blackQueen = "♛"; blackKing = "♚";
    whitePawn = "♙"; whiteKnight = "♘"; whiteBishop = "♗"; whiteRook = "♖"; whiteQueen = "♕"; whiteKing = "♔";
    for (i = 1; i < this->nbRows-1; i++)
    {
        for (j = 1; j < this->nbColumns-1; j++)
        {
            this->item(i, j)->setTextAlignment(Qt::AlignCenter);
            this->item(i, j)->setFont(QFont("Times", 20));
        }
    }
    if (playerColor == Qt::white)
    {
        this->item(1, 1)->setText(blackRook); this->item(8, 8)->setText(whiteRook);
        this->item(1, 2)->setText(blackKnight); this->item(8, 7)->setText(whiteKnight);
        this->item(1, 3)->setText(blackBishop); this->item(8, 6)->setText(whiteBishop);
        this->item(1, 4)->setText(blackQueen); this->item(8, 5)->setText(whiteKing);
        this->item(1, 5)->setText(blackKing); this->item(8, 4)->setText(whiteQueen);
        this->item(1, 6)->setText(blackBishop); this->item(8, 3)->setText(whiteBishop);
        this->item(1, 7)->setText(blackKnight); this->item(8, 2)->setText(whiteKnight);
        this->item(1, 8)->setText(blackRook); this->item(8, 1)->setText(whiteRook);
        this->item(2, 1)->setText(blackPawn); this->item(7, 8)->setText(whitePawn);
        this->item(2, 2)->setText(blackPawn); this->item(7, 7)->setText(whitePawn);
        this->item(2, 3)->setText(blackPawn); this->item(7, 6)->setText(whitePawn);
        this->item(2, 4)->setText(blackPawn); this->item(7, 5)->setText(whitePawn);
        this->item(2, 5)->setText(blackPawn); this->item(7, 4)->setText(whitePawn);
        this->item(2, 6)->setText(blackPawn); this->item(7, 3)->setText(whitePawn);
        this->item(2, 7)->setText(blackPawn); this->item(7, 2)->setText(whitePawn);
        this->item(2, 8)->setText(blackPawn); this->item(7, 1)->setText(whitePawn);
    }
    else if (playerColor == Qt::black)
    {
        this->item(1, 1)->setText(whiteRook); this->item(8, 8)->setText(blackRook);
        this->item(1, 2)->setText(whiteKnight); this->item(8, 7)->setText(blackKnight);
        this->item(1, 3)->setText(whiteBishop); this->item(8, 6)->setText(blackBishop);
        this->item(1, 4)->setText(whiteKing); this->item(8, 5)->setText(blackQueen);
        this->item(1, 5)->setText(whiteQueen); this->item(8, 4)->setText(blackKing);
        this->item(1, 6)->setText(whiteBishop); this->item(8, 3)->setText(blackBishop);
        this->item(1, 7)->setText(whiteKnight); this->item(8, 2)->setText(blackKnight);
        this->item(1, 8)->setText(whiteRook); this->item(8, 1)->setText(blackRook);
        this->item(2, 1)->setText(whitePawn); this->item(7, 8)->setText(blackPawn);
        this->item(2, 2)->setText(whitePawn); this->item(7, 7)->setText(blackPawn);
        this->item(2, 3)->setText(whitePawn); this->item(7, 6)->setText(blackPawn);
        this->item(2, 4)->setText(whitePawn); this->item(7, 5)->setText(blackPawn);
        this->item(2, 5)->setText(whitePawn); this->item(7, 4)->setText(blackPawn);
        this->item(2, 6)->setText(whitePawn); this->item(7, 3)->setText(blackPawn);
        this->item(2, 7)->setText(whitePawn); this->item(7, 2)->setText(blackPawn);
        this->item(2, 8)->setText(whitePawn); this->item(7, 1)->setText(blackPawn);
    }
}

void QChessBoard::setPlayerColor(QColor color)
{
    playerColor = color;
}

QColor QChessBoard::getPlayerColor()
{
    return(playerColor);
}

void QChessBoard::setChessBoardItemSelectionColor(QColor color)
{
    int itemSelectionColorRed = color.red();
    int itemSelectionColorGreen = color.green();
    int itemSelectionColorBlue = color.blue();
    QString styleSheet = "QTableView::item:selected { border: 1px solid black; background: rgba(";
    styleSheet = styleSheet.append(QString::number(itemSelectionColorRed));
    styleSheet = styleSheet.append(", ");
    styleSheet = styleSheet.append(QString::number(itemSelectionColorGreen));
    styleSheet = styleSheet.append(", ");
    styleSheet = styleSheet.append(QString::number(itemSelectionColorBlue));
    styleSheet = styleSheet.append(", 25%) }");
    this->setStyleSheet(styleSheet);
}

void QChessBoard::playChessGame()
{
    this->setSelectionMode(QAbstractItemView::SingleSelection);

    QObject::connect(this, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(movePiece(QTableWidgetItem*)));
    QObject::connect(this, SIGNAL(movePieceSignal()), this, SLOT(movePieceTo()));
    QObject::connect(this, SIGNAL(movePieceSignal()), this, SLOT(assignNextTurnColor()));
    QObject::connect(this, SIGNAL(showPossibleMovesSignal()), this, SLOT(showPossibleMoves()));
}

void QChessBoard::movePiece(QTableWidgetItem* piece)
{
    QColor pieceColor = getPieceColor(piece);
    if ((clickCounter == 0) && (piece->text() != "") && (pieceColor == turnColor))
    {
        pieceToMove = piece;
        clickCounter = 1;
    }
    else if (clickCounter == 1)
    {
        location = piece;
        clickCounter = 0;
        if (pieceToMove != location)
        {
            emit movePieceSignal();
        }
        else
        {
            clickCounter = 1;
        }
    }
}

void QChessBoard::movePieceTo()
{
    location->setText(pieceToMove->text());
    pieceToMove->setText("");
}

void QChessBoard::assignNextTurnColor()
{
    if (turnColor == Qt::white)
    {
        turnColor = Qt::black;
    }
    else if (turnColor == Qt::black)
    {
        turnColor = Qt::white;
    }
}


QColor QChessBoard::getPieceColor(QTableWidgetItem* piece)
{
    if ((piece->text() == "♟") || (piece->text() == "♞") || (piece->text() == "♝") || (piece->text() == "♜") || (piece->text() == "♛") || (piece->text() == "♚"))
    {
        return(Qt::black);
    }
    else if ((piece->text() == "♙") || (piece->text() == "♘") || (piece->text() == "♗") || (piece->text() == "♖") || (piece->text() == "♕") || (piece->text() == "♔"))
    {
        return(Qt::white);
    }
    else
        return(Qt::gray);
}

void QChessBoard::showPossibleMoves(QTableWidgetItem* piece)
{

}

QVector<QVector<int>> QChessBoard::computePossibleMoves(QTableWidgetItem* piece)
{
    QVector<QVector<int>> possibleMoves;
    if (playerColor == Qt::white)
    {
        if ((piece->text() == "♟") || (piece->text() == "♙"))
        {
            if (piece->text() == "♟")
            {
                if (this->item(piece->row() + 1, piece->column())->text() == "")
                {
                    if ((piece->row() == 2) && (this->item(piece->row() + 2, piece->column())->text() == ""))
                    {
                        possibleMoves.push_back({piece->row() + 2, piece->column()});
                    }
                    possibleMoves.push_back({piece->row() + 1, piece->column()});
                }
                if (this->item(piece->row() + 1, piece->column() + 1)->text() == "♙")
                {
                    possibleMoves.push_back({piece->row() + 1, piece->column() + 1});
                }
                if (this->item(piece->row() + 1, piece->column() - 1)->text() == "♙")
                {
                    possibleMoves.push_back({piece->row() + 1, piece->column() - 1});
                }
            }
            else if (piece->text() == "♙")
            {

            }
        }
    }
    else if (playerColor == Qt::black)
    {

    }
    return(possibleMoves);
}

QVector<QVector<int>> QChessBoard::test()
{
    QVector<QVector<int>> testArray;
    testArray.push_back({0, 0});
    testArray.push_back({0, 0});
    testArray.push_back({0, 0});
    return(testArray);
}
