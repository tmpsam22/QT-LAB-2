#include "area.h"

Area::Area(QWidget *parent) : QWidget(parent)
{
    setFixedSize(QSize(300, 200));  // настраиваем фиксированный размер окна
    myline = new MyLine(80, 100, 50); // создаем первоначальную линию
    myrect = new MyRect(220, 100, 50); // создаем прямоугольник
    alpha = 0; // задаем начальный угол поворота
}

void Area::showEvent(QShowEvent *)
{
    myTimer = startTimer(50); // создание таймера
}

void Area::paintEvent(QPaintEvent *)
{
    // отрисовка фигур
    QPainter painter(this);
    painter.setPen(Qt::blue);
    // движение и отрисовка фигуры
    myline->move(alpha, &painter);
    myrect->move(alpha * (-0.5), &painter);
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha = alpha + 0.2;
        update(); // обновить внешний вид поведением paintEvent
        return;
    }
    QWidget::timerEvent(event); // иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer); // уничтожить таймер
}

Area::~Area()
{
    delete myline;
    delete myrect;
}
