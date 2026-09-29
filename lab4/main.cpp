#include <fstream>
#include <string>
#include <iostream>
#include "labstd.hpp"

std::string getFileContent() {
    std::string fn("");
    std::string c("");
    getUserInputUntilCorrect("Input a filename>", fn);
    std::ifstream f;
    f = std::ifstream(fn);
    while (!f.is_open()) {
        std::cout << "Unable to open file\n";
        fn = "";
        getUserInputUntilCorrect("Input a filename>", fn);
        f = std::ifstream(fn);
    }
    char ch;
    while (f.get(ch))
    {
        c += ch;
    }
    f.close();
    return c;
}

std::string findMaxSubString(std::string &s1, std::string &s2) {
    int maxL = 1;
    std::string maxS;

    while (maxL < s2.length() && maxL < s1.length()) {
        bool found = false;
        for (int i = 0; i < s1.length() - maxL+1; i++) {
            //std::cout << i << " " << maxL << "\n";
            std::string sub3 = s1.substr(i, maxL);
            if (s2.find(sub3)!=std::string::npos) {
                maxS = sub3;
                found = true;
                break;
            }
        }
        maxL += 1;
        if (!found) {
            break;
        }
        //std::cout << maxL << "\n";
    }
    return maxS;
}

int main()
{
    std::cout << "Longest common substring\n";

    while (true) {
        std::string s1 = getFileContent();
        std::string s2 = getFileContent();

        std::cout << "Result: '" << findMaxSubString(s1, s2) << "'\n";

        if (!askDoContinue()) {
            return 0;
        }
    }
}