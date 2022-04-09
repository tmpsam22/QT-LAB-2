#pragma once

#ifndef figura_h
#define figura_h

#include "required_headers.h"

class Figura
{

protected:
    virtual void draw(QPainter *Painter) = 0;
public:
    Figura(int X, int Y, int Halflen)
        : x(X), y(Y), halflen(Halflen)
    { }

    void move(float Alpha, QPainter* Painter); // функция изменения угла наклона

    virtual ~Figura() {}

protected:
    int x, y, halflen, // координаты расположения центра фигуры, половина длина фигуры
        dx, dy; // координаты, указывающие угол наклона
};

class MyLine : public Figura
{
protected:
    void draw(QPainter *Painter) override;
public:
    MyLine(int x,int y, int halflen)
        : Figura(x, y, halflen)
    { }
};

class MyRect : public Figura
{
protected:
    void draw(QPainter *Painter) override;
public:
    MyRect(int x, int y, int halflen)
        : Figura(x, y, halflen)
    { }
};

#endif
