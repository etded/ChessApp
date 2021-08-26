#ifndef QBOARD_H
#define QBOARD_H

#include <QWidget>
#include <QtWidgets>

class QBoard : public QWidget
{
    Q_OBJECT

    public:
        QBoard();

    private:
        QPushButton *button1;
        QPushButton *button2;
        QPushButton *button3;
        QPushButton *button4;
};

#endif // QBOARD_H
