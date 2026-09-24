// Выполнил: Немычников Василий Васильевич 6103-010302D
// Версия: 1

/*
Вариант 4. Геометрическая прогрессия
55
Программа должна вычислять сумму заданного количества
начальных элементов заданной геометрической прогрессии.
Входные данные. Первый элемент геометрической прогрессии,
знаменатель этой прогрессии и количество элементов.
Выходные данные. Единственное дробное число – сумма
заданного количества элементов этой геометрической прогрессии.
Пример текстового интерфейса пользователя
```
Geometric series
Input a start value>2
Input a common ratio>3
Input the number of elements>4
Result: 80.0
Continue? (Y/N)>Y
Input a start value>0.1
Input a common ratio>0.5
Input the number of elements>1000000
Result: 0.2
Continue? (Y/N)>N
```
```
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <functional>
#include "labstd.hpp"

bool checkGreaterThanZero(unsigned int v) {
    return v > 0;
}

int main()
{
    std::cout << "Geometric series\n";

    while (true) {
        double start;
        double ratio;
        unsigned int numberOfEl;

        getUserInputUntilCorrect("Input a start value>", start);
        getUserInputUntilCorrect("Input a common ratio>", ratio);
        getUserInputUntilCorrect("Input the number of elements>", numberOfEl, &checkGreaterThanZero);

        printGeometricProgression(start, ratio, numberOfEl);

        if (!askDoContinue()) {
            return 0;
        }
    }
}
