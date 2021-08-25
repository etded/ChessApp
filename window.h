#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QWidget>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Window : public QWidget
{
    Q_OBJECT
    public:
        Window(QWidget *parent = nullptr);

    protected:

    private:

    public slots:

    signals:

};

#endif // WINDOW_H
