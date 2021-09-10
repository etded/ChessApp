#include "window.h"

Window::Window() : QMainWindow()
{
    chessMenu = new QChessMenu(this);

    this->setMenuBar(chessMenu);

    centralWidget = new QWidget(this);

    QGridLayout *gridWindow = new QGridLayout(centralWidget);

    leftPanel = new QWidget(centralWidget);

        QVBoxLayout *leftPanelVBoxLayout = new QVBoxLayout(leftPanel);

        chessTopTimer = new QChessTimer(this);
        chessBottomTimer = new QChessTimer(this);
        chessBoard = new QChessBoard(this);

        leftPanelVBoxLayout->addWidget(chessTopTimer);
        leftPanelVBoxLayout->addWidget(chessBoard);
        leftPanelVBoxLayout->addWidget(chessBottomTimer);

        leftPanelVBoxLayout->setAlignment(chessTopTimer, Qt::AlignHCenter);
        leftPanelVBoxLayout->setAlignment(chessBottomTimer, Qt::AlignHCenter);
        leftPanel->setLayout(leftPanelVBoxLayout);

    gridWindow->addWidget(leftPanel, 0, 0);

    rightPanel = new QWidget(centralWidget);

        QVBoxLayout *rightPanelVBoxLayout = new QVBoxLayout(rightPanel);

        chessHistory = new QChessHistory(this);
        chessControl = new QChessControl(this);

        rightPanelVBoxLayout->addWidget(chessHistory);
        rightPanelVBoxLayout->addStretch();
        rightPanelVBoxLayout->addWidget(chessControl);

        rightPanel->setLayout(rightPanelVBoxLayout);

    gridWindow->addWidget(rightPanel, 0, 1);

    this->setLayout(gridWindow);

    this->setCentralWidget(centralWidget);
}

void Window::setChessBoardColor()
{
    chessBoard->openColorDialog();
}
