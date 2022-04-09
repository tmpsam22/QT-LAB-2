#pragma once

#ifndef AREA_H
#define AREA_H

#include "figura.h"
#include "required_headers.h"

class Area : public QWidget
{
public:

    Area(QWidget *parent = nullptr);
    ~Area();
    MyLine *myline;
    MyRect *myrect;

protected:

                                         // обработчики событий
    void paintEvent(QPaintEvent *event); // отрисовка виджета
    void timerEvent(QTimerEvent *event); // срабатывания таймера
    void showEvent(QShowEvent *event); // виджет стал виден
    void hideEvent(QHideEvent *event); // виджет стал скрытым

private:

    int myTimer; // идентификатор таймера
    float alpha; // угол поворота

};

#endif
