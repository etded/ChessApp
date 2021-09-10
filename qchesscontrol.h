#ifndef QCHESSCONTROL_H
#define QCHESSCONTROL_H

#include <QWidget>
#include <QtWidgets>
#include <QtCore>

#include <iostream>

using namespace std;

class QChessControl : public QGroupBox
{
    Q_OBJECT

    public:
        QChessControl(QWidget *parent = nullptr);

    private:
        QPushButton *startButton;
        QPushButton *resetButton;
        QPushButton *searchButton;
        QPushButton *analyzeButton;
};

#endif // QCHESSCONTROL_H
