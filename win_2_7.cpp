#include "win_2_7.h"

Win_2_7::Win_2_7(QWidget *parent)
    :   QWidget(parent)
{
    frame = new QFrame(this);   // создание рамки
    frame->setFrameShadow(QFrame::Raised); // 3D-эффект рамки
    frame->setFrameShape(QFrame::Panel); // форма рамки

    inputLabel = new QLabel("Введите число:", this); // заголовка ввода
    inputEdit = new QLineEdit("",this); // строка ввода

    StrValidator *v=new StrValidator(inputEdit); // создание вспомогательного класса проверки ввода
    inputEdit->setValidator(v); // помещаем строку ввода
    outputLabel = new QLabel("Результат:", this); // заголовка вывода
    outputEdit = new QLineEdit("",this); // строка результата

    // создание кнопок
    nextButton = new QPushButton("Следующее", this);
    exitButton = new QPushButton("Выход", this);

    // для динамической сетки
    // помещаем всех необходимые компоненты

    // вертикальная разметка
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    // горизонтальная разметка
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    // ожидание ввода данных (числа для возведения в квадрат)
    begin();

    // связываем кнопку "exitButton" с сигналом clicked(), который приводит к закрытию приложения поведением close()
    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    // связываем кнопку "nextButton" с сигналом clicked(), который приводит к изменению текущего объекта
    // поведением, определенным в begin()
    connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(begin()));
    // связываем кнопку "inputEdit" с сигналом returnPressed(), который приводит к изменению текущего объекта
    // поведением, определенным в calc()
    connect(inputEdit,  SIGNAL(returnPressed()), this, SLOT(calc()));
}

void Win_2_7::begin()
{
    inputEdit->clear(); // очищаем введенное число
    nextButton->setEnabled(false); // отключаем кнопку "Следующее"
    nextButton->setDefault(false); // убираем кнопку с фокуса
    inputEdit->setEnabled(true); // включаем ввод
    // отключаем видимость результата
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    // выключаем ввод
    outputEdit->setEnabled(false);
    // фокус на вводе (нажатие клавиш)
    inputEdit->setFocus();
}

void Win_2_7::calc()
{
    bool Ok = true;
    QString str = inputEdit->text(); // получаем ввод
    float value = str.toDouble(&Ok); // кастим к float

    if (Ok)
    {
        float res = value * value; // вычисляем результат
        str.setNum(res); // копируем значение в QString
        outputEdit->setText(str); // вывод полученного значения в строку Результата
        inputEdit->setEnabled(false); // отключаем ввод
        // включаем видимость результата
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);

        // кнопка по умолчанию теперь nextButton
        nextButton->setDefault(true);
        // включаем эту кнопку
        nextButton->setEnabled(true);
        // фокус на этой кнопке (нажатие клавиш)
        nextButton->setFocus();
        return;
    }

    // если входное значение является не валидным
    if (!str.isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Information,
        "Возведение в квадрат.",
        "Введено неверное значение.",
        QMessageBox::Ok);
        msgBox.exec();
    }
}
