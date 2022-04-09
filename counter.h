#pragma once

#ifndef counter_h
#define counter_h

#include "required_headers.h"

class Counter : public QLineEdit
{
    Q_OBJECT
public:

    Counter(const QString & contents, QWidget* parent = 0)
        : QLineEdit(contents, parent)
    {}

signals:

    // сигнал срабатывает, если число кратно 5
    void tick_signal();

public slots:

    // метод увеличивает число на 1
    void add_one();
};

#endif
