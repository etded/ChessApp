#ifndef QCHESSMENU_H
#define QCHESSMENU_H

#include <QWidget>
#include <QtWidgets>
#include <QtCore>

#include <iostream>

using namespace std;

class QChessMenu : public QMenuBar
{
    Q_OBJECT

    public:
        explicit QChessMenu(QWidget *parent = nullptr);

    private:
        QMenu *menuFile;
        QMenu *menuShow;
        QMenu *menuOptions;
        QAction *boardColorAction;

};

#endif // QCHESSMENU_H
