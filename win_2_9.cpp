#include "win_2_9.h"

Win_2_9::Win_2_9()
{
    this->setWindowTitle("Обработка событий");
    // создание вертикального менеджера компоновки
    QVBoxLayout* layout = new QVBoxLayout(this);

    // создание Area и добавление в компоновку
    area = new Area(this);
    layout->addWidget(area);

    // добавление кнопки и добавление в компоновку
    btn = new QPushButton("Завершить", this);
    layout->addWidget(btn);

    // связывание кнопки "Завершить" с сигналом clicked(), который приводит к завершению программы
    // поведением close()
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(close()));
};
