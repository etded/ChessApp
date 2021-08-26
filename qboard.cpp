#include "qboard.h"




QBoard::QBoard() : QWidget()
{
    QGridLayout *gridLayout = new QGridLayout(this);

    QPushButton *button1 = new QPushButton(this);
    QPushButton *button2 = new QPushButton(this);
    QPushButton *button3 = new QPushButton(this);
    QPushButton *button4 = new QPushButton(this);

    gridLayout->addWidget(button1, 0, 0);
    gridLayout->addWidget(button2, 0, 1);
    gridLayout->addWidget(button3, 1, 0);
    gridLayout->addWidget(button4, 1, 1);

    this->setLayout(gridLayout);
}
