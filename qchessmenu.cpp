#include "qchessmenu.h"

QChessMenu::QChessMenu(QWidget *parent) : QMenuBar(parent)
{
    menuFile = this->addMenu("&File");
    menuShow = this->addMenu("&Show");
    menuOptions = this->addMenu("&Options");
    boardColorAction = new QAction("&Board Color", this);
    menuOptions->addAction(boardColorAction);
    QObject::connect(boardColorAction, SIGNAL(triggered()), parent, SLOT(setChessBoardColor()));
}
