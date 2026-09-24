// Выполнил: Немычников Василий Васильевич 6103-010302D
// Версия: 1

/*
Вариант 9. Форматирование времени
Программа должна переводить количество секунд, прошедших с
начала суток, в формат «часы:минуты:секунды».
Входные данные. Целое неотрицательное число – количество
секунд, прошедших с начала суток.
Выходные данные. Количество часов, прошедших с начала суток,
количество минут, прошедших с начала последнего часа, и количество
секунд, прошедших с начала последней минуты, в формате
«часы:минуты:секунды».
```
Пример текстового интерфейса пользователя
Time formatter
Input the number of seconds>43200
12:00:00
Continue? (Y/N)>Y
Input the number of seconds>10000
02:46:40
Continue? (Y/N)>N
```
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


bool getUserInput(unsigned int& secs) {
    std::string s;

    std::cout << "Input the number of seconds>";

    if (!std::getline(std::cin, s)) {
        return false;
    }

    std::istringstream ss(s);

    if (!(ss >> secs)) {
        return false;
    }

    char extra;
    if (ss >> extra) {
        return false;
    }

    return true;
}

bool askDoContinue() {
    while (true) {
        std::string s;

        std::cout << "Continue? (Y/N)>";

        if (!std::getline(std::cin, s)) {
            std::cout << "Invalid input\n";
            continue;
        }

        std::istringstream ss(s);

        char ans;

        if (!(ss >> ans)) {
            std::cout << "Invalid input\n";
            continue;
        }

        char extra;
        if (ss >> extra) {
            std::cout << "Invalid input\n";
            continue;
        }

        if (ans == 'Y') {
            return true;
        }
        else if (ans == 'N') {
            return false;
        }
        else {
            std::cout << "Invalid input\n";
            continue;
        }
    }
}

std::string fmtDoubleDigit(int v) {
    std::string s;
    if (v < 10) s += "0";
    return s + std::to_string(v);
}

bool printFormatedTime(unsigned int time) {
    constexpr unsigned int secsInMin = 60;
    constexpr unsigned int secsInHr = secsInMin * 60;
    constexpr unsigned int secsInDay = secsInHr * 24;

    if (time >= secsInDay) {
        std::cout << "Time cant be greater than or equal to 86400 seconds (1 full day)\n";
        return false;
    }

    int h = time / secsInHr;
    int m = time / secsInMin % 60;
    int s = time % 60;

    std::cout << std::setfill('0') << 
        std::setw(2) << h << ":" << 
        std::setw(2) << m << ":" << 
        std::setw(2) << s << "\n";

    return true;
}

int main()
{
    std::cout << "Time formatter\n";

    while (true) {
        unsigned int time;

        while (!getUserInput(time) || !printFormatedTime(time)) {
            std::cerr << "Invalid input! Try again.\n";
        }

        if (!askDoContinue()) {
            return 0;
        }
    }
}
