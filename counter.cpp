#include "counter.h"

void Counter::add_one()
{
     QString str = text(); // инкрементируем это значение, которое содержится в строке ввода
     int res = str.toInt();
     if (res != 0 && res % 5 ==0)
     {
         // генерируем сигнал
         emit tick_signal();
     }
     str.setNum(++res);
     setText(str);
}
