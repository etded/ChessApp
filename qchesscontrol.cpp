#include "qchesscontrol.h"

QChessControl::QChessControl(QWidget *parent) : QGroupBox(parent)
{
    QVBoxLayout *VBoxLayout = new QVBoxLayout(this);

    QGroupBox *modeOne = new QGroupBox("Mode 1");
    QGroupBox *modeTwo = new QGroupBox("Mode 2");

    QHBoxLayout *modeOneHBoxLayout = new QHBoxLayout(modeOne);

        startButton = new QPushButton("Start");
        resetButton = new QPushButton("Reset");

        QObject::connect(startButton, SIGNAL(clicked()), parent, SLOT(startGame()));

    modeOneHBoxLayout->addWidget(startButton);
    modeOneHBoxLayout->addWidget(resetButton);

    modeOne->setLayout(modeOneHBoxLayout);

    QHBoxLayout *modeTwoHBoxLayout = new QHBoxLayout(modeTwo);

        searchButton = new QPushButton("Search");
        analyzeButton = new QPushButton("Analyze");

    modeTwoHBoxLayout->addWidget(searchButton);
    modeTwoHBoxLayout->addWidget(analyzeButton);

    modeTwo->setLayout(modeTwoHBoxLayout);

    VBoxLayout->addWidget(modeOne);
    VBoxLayout->addWidget(modeTwo);

    this->setLayout(VBoxLayout);
}
