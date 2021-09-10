#ifndef WINDOW_H
#define WINDOW_H


#include <QWidget>
#include <QtWidgets>
#include "qchesshistory.h"
#include "qchessboard.h"
#include "qchesstimer.h"
#include "qchessmenu.h"
#include "qchesscontrol.h"

using namespace std;


class Window : public QMainWindow
{
    Q_OBJECT

    public:
        Window();

    protected:

    public slots:
        void setChessBoardColor();

    private:
        QChessHistory *chessHistory;
        QChessBoard *chessBoard;
        QChessTimer *chessTopTimer;
        QChessTimer *chessBottomTimer;
        QWidget *leftPanel;
        QWidget *rightPanel;
        QTimer *LCDNumber;
        QChessMenu *chessMenu;
        QWidget *centralWidget;
        QChessControl *chessControl;


};

#endif // WINDOW_H
