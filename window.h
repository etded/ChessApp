#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtWidgets>
#include "qhistory.h"
#include "qchessboard.h"
#include "qchesstimer.h"


class Window : public QWidget
{
    Q_OBJECT
    public:
        Window();

    protected:

    private:
        QHistory *history;
        QChessBoard *chessBoard;
        QChessTimer *chessTimer;
        QWidget *leftPanel;
        QWidget *rightPanel;
        QTimer *LCDNumber;

    public slots:

    signals:

};

#endif // WINDOW_H
