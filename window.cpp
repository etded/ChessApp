#include "window.h"

Window::Window() : QWidget()
{
    QHBoxLayout *hboxWindow = new QHBoxLayout(this);

    leftPanel = new QWidget(this);

        QVBoxLayout *leftPanelVBoxLayout = new QVBoxLayout(leftPanel);

        QChessTimer *chessTimer = new QChessTimer();

        leftPanelVBoxLayout->addWidget(chessTimer);

        QChessBoard *chessBoard = new QChessBoard();

        leftPanelVBoxLayout->addWidget(chessBoard);

        leftPanel->setLayout(leftPanelVBoxLayout);

    hboxWindow->addWidget(leftPanel);

    rightPanel = new QWidget(this);

        QVBoxLayout *rightPanelVBoxLayout = new QVBoxLayout(rightPanel);

        QHistory *chessHistory = new QHistory();

        rightPanelVBoxLayout->addWidget(chessHistory);
        rightPanelVBoxLayout->addStretch();

        rightPanel->setLayout(rightPanelVBoxLayout);

    hboxWindow->addWidget(rightPanel);

    this->setLayout(hboxWindow);
}
