#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <functional>

template<typename T>
bool getUserInput(std::string text, T &v) {
    std::cout << text;

    std::string s;

    if (!std::getline(std::cin, s)) {
        return false;
    }

    std::istringstream ss(s);

    if (!(ss >> v)) {
        return false;
    }

    char extra;
    if (ss >> extra) {
        return false;
    }

    return true;
}

template<typename T>
bool getUserInput(std::string text, T &v, bool(*compare)(T)) {
    std::cout << text;

    std::string s;

    if (!std::getline(std::cin, s)) {
        return false;
    }

    std::istringstream ss(s);

    if (!(ss >> v)) {
        return false;
    }

    if (!compare(v)) {
        return false;
    }

    char extra;
    if (ss >> extra) {
        return false;
    }

    return true;
}

template<typename T>
void getUserInputUntilCorrect(std::string text, T &v) {
    while (!getUserInput(text, v)) {
        std::cerr << "Invalid input! Try again.\n";
    }
}

template<typename T>
void getUserInputUntilCorrect(std::string text, T &v, bool(*compare)(T)) {
    while (!getUserInput(text, v, compare)) {
        std::cerr << "Invalid input! Try again.\n";
    }
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

        if (ans == 'Y' || ans == 'y') {
            return true;
        }
        else if (ans == 'N' || ans == 'n') {
            return false;
        }
        else {
            std::cout << "Invalid input\n";
            continue;
        }
    }
}

void printGeometricProgression(double start, double ratio, unsigned int numberOfEl) {
    float result;
    if (ratio == 1) {
        result = start;
    } else {
        result = (start * (std::pow(ratio, numberOfEl) - 1)) / (ratio - 1);
    }
    if (std::isinf(result) || std::isnan(result)) {
        std::cout << "Unable to calculate result. (try smaller values)\n";
    } else {
        std::cout << "Result: " << result << "\n";
    }
}