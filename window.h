#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtWidgets>
#include "qhistory.h"
#include "qboard.h"


class Window : public QWidget
{
    Q_OBJECT
    public:
        Window();

    protected:

    private:
        QHistory *history;
        QBoard *chess_board;

    public slots:

    signals:

};

#endif // WINDOW_H
