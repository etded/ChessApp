#include "window.h"

Window::Window() : QWidget()
{
    QHBoxLayout *hboxWindow = new QHBoxLayout(this);

        QBoard *chessBoard = new QBoard();

        QHistory *chessHistory = new QHistory();

        hboxWindow->addWidget(chessBoard);
        hboxWindow->addWidget(chessHistory);

    this->setLayout(hboxWindow);
}
