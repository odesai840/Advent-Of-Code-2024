#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool checkSafeP1(std::vector<int>& levels) {
    bool increasing = true, decreasing = true;

    for (int i = 1; i < levels.size(); i++) {
        int diff = levels[i] - levels[i - 1];

        if (abs(diff) < 1 || abs(diff) > 3) {
            return false;
        }

        if (diff < 0) {
            increasing = false;
        }
        if (diff > 0) {
            decreasing = false;
        }
    }

    return increasing || decreasing;
}

bool checkSafeP2(std::vector<int>& levels) {
    if (checkSafeP1(levels)) {
        return true;
    }

    for (int i = 0; i < levels.size(); i++) {
        std::vector<int> dampenedLevels = levels;
        dampenedLevels.erase(dampenedLevels.begin() + i);

        if (checkSafeP1(dampenedLevels)) {
            return true;
        }
    }

    return false;
}

int main() {
    // read input file
    std::ifstream file("input.txt");
    
    /*
    // part 1
    std::string line;
    int safe = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int> levels;
        int num;

        while (iss >> num) {
            levels.push_back(num);
        }

        if (checkSafeP1(levels) == true) {
            safe++;
        }
    }

    file.close();

    std::cout << safe << std::endl;
    */

    // part 2
    std::string line;
    int safe = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int> levels;
        int num;

        while (iss >> num) {
            levels.push_back(num);
        }

        if (checkSafeP2(levels) == true) {
            safe++;
        }
    }

    file.close();

    std::cout << safe << std::endl;
}
