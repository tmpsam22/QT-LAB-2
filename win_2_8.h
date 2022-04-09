#pragma once
#ifndef win_2_8_h
#define win_2_8_h

#include "counter.h"
#include "required_headers.h"

class Win_2_8: public QWidget
{
    Q_OBJECT

protected:

    QLabel* label1, *label2;
    Counter* edit1, *edit2;
    QPushButton* calcbutton;
    QPushButton* exitbutton;

public:
    Win_2_8(QWidget* parent = nullptr);
};

#endif
