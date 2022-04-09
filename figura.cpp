#include <math.h>
#include "figura.h"

void Figura::move(float Alpha, QPainter* Painter)
{
    // расчет координатов, задающий угол наклона
    dx = halflen * cos(Alpha);
    dy = halflen * sin(Alpha);
    draw(Painter); // отрисовка фигуры
}

// отрисовка линии
void MyLine::draw(QPainter* Painter)
{
    Painter->drawLine(x + dx, y + dy, x - dx, y - dy);
}

// отрисовка прямоугольника
void MyRect::draw(QPainter* Painter)
{
    Painter->drawLine(x + dx, y + dy, x + dy, y - dx);
    Painter->drawLine(x + dy, y - dx, x - dx, y - dy);
    Painter->drawLine(x - dx, y - dy, x - dy, y + dx);
    Painter->drawLine(x - dy, y + dx, x + dx, y + dy);
}
