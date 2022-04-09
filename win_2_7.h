#pragma once

#ifndef win_2_7_h
#define win_2_7_h

#include "required_headers.h"

class Win_2_7 : public QWidget // класс окна
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов

public:

    Win_2_7(QWidget* parent = nullptr); // конструктор

public slots:

    void begin(); // метод начальной настройки интерфейса

    void calc(); // метод реализации вычислений

protected:

    QFrame* frame; // рамка
    QLabel* inputLabel; // метка ввода
    QLineEdit* inputEdit; // строчный редактор ввода
    QLabel* outputLabel; // метка вывода
    QLineEdit* outputEdit; // строчный редактор вывода
    QPushButton* nextButton; // кнопка Следующее
    QPushButton* exitButton; // кнопка Выход

};

struct StrValidator : QValidator // класс компонента проверки ввода
{
     StrValidator(QObject* parent)
         : QValidator(parent)
     { }

     virtual State validate(QString& /*str*/, int&/*pos*/)const
     {
        return Acceptable; // метод всегда принимает вводимую строку
     }
};
#endif
