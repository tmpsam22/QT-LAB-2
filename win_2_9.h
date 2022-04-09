#ifndef window_h
#define window_h
#include <QtGui>

#include "area.h"
#include "required_headers.h"

struct Win_2_9 : public QWidget
{
    Win_2_9();
protected:
    Area * area; // область отображения рисунка
    QPushButton * btn;
};
#endif
