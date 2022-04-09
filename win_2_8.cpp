#include "win_2_8.h"

Win_2_8::Win_2_8(QWidget* parent)
    : QWidget(parent)
{
     this->setWindowTitle("Счетчик");

     // создаем необходимые заголовки и помещаем их в горизонтальную компоновку
     label1 = new QLabel("Cчет по 1", this);
     label2 = new QLabel("Cчет по 5", this);
     QHBoxLayout* layout1 = new QHBoxLayout();
     layout1->addWidget(label1);
     layout1->addWidget(label2);

     // создаем строки ввода и помещаем их в горизонтальную компоновку
     edit1 = new Counter("0", this);
     edit2 = new Counter("0", this);
     QHBoxLayout* layout2 = new QHBoxLayout();
     layout2->addWidget(edit1);
     layout2->addWidget(edit2);

     // создаем кнопки и помещаем их в горизонтальную компоновку
     calcbutton = new QPushButton("+1", this);
     exitbutton = new QPushButton("Выход", this);
     QHBoxLayout* layout3 = new QHBoxLayout();
     layout3->addWidget(calcbutton);
     layout3->addWidget(exitbutton);

     // базовая компоновка для всех виджетов
     QVBoxLayout* layout4 = new QVBoxLayout(this);
     layout4->addLayout(layout1);
     layout4->addLayout(layout2);
     layout4->addLayout(layout3);

     // связываем кнопку "+1" с сигналом clicked(), который приводит к изменению
     // содержимого в edit1 ("счёт по 1") поведением, реализованный в слоте add_one
     connect(calcbutton, SIGNAL(clicked(bool)), edit1, SLOT(add_one()));

     // связываем ввод данных в заголовке "Счёт по 1" с сигналом tick_singal(), который приводит
     //к изменению содержимого в edit2 ("Счёт по 5") поведением, реализованный в слоте add_one
     connect(edit1, SIGNAL(tick_signal()), edit2, SLOT(add_one()));
     // связываем кнопку "Выход" с сигналом clicked(), который завершает работу приложения поведением close()
     connect(exitbutton, SIGNAL(clicked(bool)), this, SLOT(close()));
}
