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
#include "labvector.hpp"

template<typename T>
std::string prettyLabVector(labvector<T> &v) {
    std::string s = "[";
    u_int vSize = v.getSize();
    for (u_int i = 0; i < vSize; i++) {
        s += std::to_string(v.get(i));
        if (i < vSize-1) {
            s += ", ";
        }
    }

    s += "]";
    return s;
}



bool validateOp(std::string s) {
    if (s != "insert" && s != "erase") return false;
    return true;
}

int main()
{
    std::cout << "Array modification\n";

    u_int numOfInts;
    getUserInputUntilCorrect("Input the number integers>", numOfInts);

    labvector<int> vec;

    for (u_int i = 0; i < numOfInts; i++) {
        int v;
        getUserInputUntilCorrect("Input the integer #" + std::to_string(i+1) + ">", v);
        vec.push_back(v);
    }

    std::cout << "Current array: " << prettyLabVector(vec) << "\n";

    while (true) {
        std::string op;
        getUserInputUntilCorrect("Input an operation (insert/erase)>", op, &validateOp);

        u_int lowerLimit = 0;
        u_int upperLimit = 0;

        if (op == "insert") {
            lowerLimit = 1;
            upperLimit = vec.getSize()+1;
        }

        if (op == "erase") {
            lowerLimit = 1;
            upperLimit = vec.getSize();
        }
        
        u_int position;
        if (vec.getSize() > 0) { 
           getUserInputUntilCorrect("Input a position>", position);
           while (position > upperLimit || position < lowerLimit) {
               std::cout << "Invalid position\n";
               getUserInputUntilCorrect("Input a position>", position);
           }
        }   

        if (op == "insert") {
            int v;
            getUserInputUntilCorrect("Input an integer>", v);
            if (vec.getSize() == 0) {
                vec.push_back(v);
            } else {
                vec.insert(position-1, v);
            }
        }

        if (op == "erase") {
            if (vec.getSize() == 0) {
                std::cout << "Cannot erase from an empty array\n";
            } else {
                vec.remove(position-1);
            }
        }

        std::cout << "Current array: " << prettyLabVector(vec) << "\n";

        if (!askDoContinue()) {
            vec.kill();
            return 0;
        }
    }
}
