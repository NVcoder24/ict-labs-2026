// Выполнил: Немычников Василий Васильевич 6103-010302D
// Версия: 1

/*
Вариант 19. Вставка и удаление элементов
Программа должна хранить конечную последовательность целых
чисел и позволять пользователю последовательно вставлять элементы
в эту последовательность на заданную позицию и удалять элементы
этой последовательности с заданной позиции. Остальные элементы
при этом должны сдвигаться и перенумеровываться. Программа
должна показывать текущее состояние последовательности после
каждой операции.
Входные данные. Конечная последовательность целых чисел,
действия пользователя.
Выходные данные. Состояние последовательности после каждого
действия пользователя.
Пример текстового интерфейса пользователя
```
Array modification
Input the number integers>5
Input the integer #1>-1
Input the integer #2>2
Input the integer #3>4
103
Input the integer #4>-3
Input the integer #5>1
Current array: [-1, 2, 4, -3, 1]
Input an operation (insert/erase)>insert
Input a position>3
Input an integer>10
Current array: [-1, 2, 10, 4, -3, 1]
Continue? (Y/N)>Y
Input an operation (insert/erase)>erase
Input a position>2
Current array: [-1, 10, 4, -3, 1]
Continue? (Y/N)>N
```
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <functional>
#include "labstd.hpp"

bool validateOp(std::string s) {
    if (s != "insert" && s != "erase") return false;
    return true;
}

int main()
{
    std::cout << "Array modification\n";

    u_int numOfInts;
    getUserInputUntilCorrect("Input the number integers>", numOfInts);

    std::vector<int> vec;

    for (u_int i = 0; i < numOfInts; i++) {
        int v;
        getUserInputUntilCorrect("Input the integer #" + std::to_string(i+1) + ">", v);
        vec.push_back(v);
    }

    std::cout << "Current array: " << prettyVector(vec) << "\n";

    while (true) {
        std::string op;
        getUserInputUntilCorrect("Input an operation (insert/erase)>", op, &validateOp);

        u_int position;
        if (vec.size() > 0) { 
           getUserInputUntilCorrect("Input a position>", position);
           while (position > vec.size() || position == 0) {
               std::cout << "Invalid position\n";
               getUserInputUntilCorrect("Input a position>", position);
           }
        }   

        if (op == "insert") {
            int v;
            getUserInputUntilCorrect("Input an integer>", v);
            if (vec.size() == 0) {
                vec.push_back(v);
            } else {
                vec.insert(vec.begin()+position-1, v);
            }
        }

        if (op == "erase") {
            if (vec.size() == 0) {
                std::cout << "Cannot erase from an empty array\n";
            } else {
                vec.erase(vec.begin()+position-1);
            }
        }

        std::cout << "Current array: " << prettyVector(vec) << "\n";

        if (!askDoContinue()) {
            return 0;
        }
    }
}
